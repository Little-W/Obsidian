#!/usr/bin/env python3
"""Executable double-address transparent March examples.

The read-complement-read procedure and initial/final signature scans follow
Mrozek and Yarmolik, Entropy 23(7), 894 (2021), equations (5) and (6).
CRC-4 polynomial x^4+x+1 and the explicit fault instances are teaching choices.
Only the standard library is required. Each run contains at most one fault.
"""
from __future__ import annotations

import argparse
from collections import Counter
from itertools import product
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def double_addresses(depth: int, removed_bit: int, gray: bool = False) -> list[int]:
    assert depth >= 2 and depth & (depth - 1) == 0
    width = depth.bit_length() - 1
    assert 0 <= removed_bit <= width
    result = []
    for counter in range(2 * depth):
        value = counter ^ (counter >> 1) if gray else counter
        address = (value & ((1 << removed_bit) - 1)) | ((value >> (removed_bit + 1)) << removed_bit)
        result.append(address)
    assert Counter(result) == Counter({address: 2 for address in range(depth)})
    return result


def signature(bits: list[int]) -> int:
    """CRC-4 remainder: zero seed, x^4+x+1, MSB first, no final XOR."""
    state = 0
    for bit in bits:
        feedback = (state >> 3) ^ bit
        state = (state << 1) & 0xF
        if feedback:
            state ^= 0x3
    return state


def run(initial: list[int], addresses: list[int], variant: int,
        fault: dict | None = None, capture: bool = False) -> dict:
    assert variant in (1, 2)
    depth = len(initial)
    assert Counter(addresses) == Counter({address: 2 for address in range(depth)})
    memory = list(initial)
    fault = fault or {'kind': 'none'}
    if fault['kind'] == 'SAF':
        memory[fault['target']] = fault['value']
    entry = list(memory)
    trace = []
    local_failures = []
    step = 0
    snapshots = []

    def record(phase: str, address: int, operation: str, observed=None, expected=None, triggered=False):
        nonlocal step
        step += 1
        if capture:
            trace.append({'step': step, 'phase': phase, 'address': address,
                          'operation': operation, 'observed': observed, 'expected': expected,
                          'triggered': triggered, 'memory_after': list(memory)})

    def write(address: int, value: int) -> bool:
        before = memory[address]
        triggered = False
        if fault['kind'] == 'SAF' and address == fault['target']:
            memory[address] = fault['value']
            triggered = value != fault['value']
        elif (fault['kind'] == 'TF' and address == fault['target']
              and before == fault['before'] and value == 1 - before):
            triggered = True
        elif (fault['kind'] == 'PNPSF' and address == fault['target']
              and before == fault['before'] and value == 1 - before
              and all(memory[a] == b for a, b in zip(fault['neighbors'], fault['background']))):
            triggered = True
        else:
            memory[address] = value
        if (fault['kind'] == 'CFid' and address == fault['aggressor']
              and before == fault['before'] and memory[address] == 1 - before):
            memory[fault['victim']] = fault['forced_value']
            triggered = True
        return triggered

    initial_reads = []
    for address in range(depth):
        value = memory[address]
        initial_reads.append(value)
        record('initial_signature', address, 'read', observed=value)
    reference = signature(initial_reads)
    passes = [addresses] if variant == 1 else [addresses, list(reversed(addresses))]
    for pass_index, order in enumerate(passes, start=1):
        for visit, address in enumerate(order, start=1):
            value = memory[address]
            record(f'base_{pass_index}', address, 'read_latch', observed=value)
            expected = 1 - value
            triggered = write(address, expected)
            record(f'base_{pass_index}', address, f'write{expected}', triggered=triggered)
            observed = memory[address]
            record(f'base_{pass_index}', address, 'read_compare', observed=observed, expected=expected)
            if observed != expected:
                local_failures.append({'step': step, 'base': pass_index, 'visit': visit,
                                       'address': address, 'expected': expected, 'observed': observed})
        snapshots.append(list(memory))
    final_reads = []
    for address in range(depth):
        value = memory[address]
        final_reads.append(value)
        record('final_signature', address, 'read', observed=value)
    actual = signature(final_reads)
    assert step == (8 if variant == 1 else 14) * depth
    return {'variant': f'March_2A_{variant}', 'initial': entry, 'addresses': addresses,
            'operation_count': step, 'local_failures': local_failures,
            'reference_signature': reference, 'final_signature': actual,
            'signature_mismatch': reference != actual,
            'detected': bool(local_failures) or reference != actual,
            'final': memory, 'restored': memory == entry,
            'base_final_states': snapshots, 'fault': fault, 'trace': trace}


def validate() -> dict:
    counts = []
    total = 0
    for depth in (2, 4, 8):
        cases = 0
        width = depth.bit_length() - 1
        for gray in (False, True):
            for removed in range(width + 1):
                order = double_addresses(depth, removed, gray)
                for bits in product((0, 1), repeat=depth):
                    for variant in (1, 2):
                        result = run(list(bits), order, variant)
                        assert result['restored'] and not result['detected']
                        assert all(state == list(bits) for state in result['base_final_states'])
                        cases += 1
        counts.append({'depth': depth, 'initial_patterns': 2 ** depth,
                       'address_generators': 2 * (width + 1), 'variants': 2, 'runs': cases})
        total += cases
    order = double_addresses(4, 2)
    simple_count = 0
    for kind in ('SAF', 'TF'):
        for target, polarity, bits, variant in product(range(4), (0, 1), product((0, 1), repeat=4), (1, 2)):
            fault = {'kind': kind, 'target': target,
                     'value' if kind == 'SAF' else 'before': polarity}
            result = run(list(bits), order, variant, fault)
            assert result['local_failures']
            simple_count += 1
    samples = {
        'fault_free_8N': run([0, 1, 0, 1], order, 1, capture=True),
        'fault_free_14N': run([0, 1, 0, 1], order, 2, capture=True),
        'SAF0': run([0, 1, 0, 1], order, 1, {'kind': 'SAF', 'target': 2, 'value': 0}, True),
        'TF_up': run([0, 1, 0, 1], order, 1, {'kind': 'TF', 'target': 2, 'before': 0}, True),
        'CFid_signature': run([0, 1, 0, 1], order, 1,
                              {'kind': 'CFid', 'aggressor': 0, 'before': 0,
                               'victim': 1, 'forced_value': 0}, True),
    }
    pattern_fault = {'kind': 'PNPSF', 'target': 1, 'before': 0,
                     'neighbors': [0, 2], 'background': [0, 1]}
    samples['PNPSF_8N'] = run([0, 0, 0, 0], order, 1, pattern_fault, True)
    samples['PNPSF_14N'] = run([0, 0, 0, 0], order, 2, pattern_fault, True)
    assert not samples['CFid_signature']['local_failures']
    assert samples['CFid_signature']['signature_mismatch']
    assert not samples['PNPSF_8N']['detected']
    assert samples['PNPSF_14N']['local_failures']
    # Exhibit a collision for this explicitly selected four-bit signature.
    zero = [0] * 8
    collision = next(list(bits) for bits in product((0, 1), repeat=8)
                     if any(bits) and signature(list(bits)) == signature(zero))
    return {'schema_version': 1, 'source_doi': '10.3390/e23070894',
            'signature_choice': {'width': 4, 'polynomial': 'x^4+x+1',
                                 'seed': 0, 'final_xor': 0, 'input_order': 'address ascending',
                                 'scope': 'Teaching implementation; the paper leaves the signature polynomial unspecified.'},
            'fault_free_validation': counts, 'fault_free_runs': total,
            'simple_fault_runs_detected': simple_count, 'samples': samples,
            'signature_collision_example': {'first': zero, 'second': collision,
                                            'signature': signature(zero)}, 'passed': True}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT / 'examples/transparent_march_results.json')
    args = parser.parse_args()
    result = validate()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({key: result[key] for key in ('passed', 'fault_free_runs', 'simple_fault_runs_detected')}, indent=2))
    print(json.dumps({key: {field: value[field] for field in ('operation_count', 'detected', 'restored', 'reference_signature', 'final_signature', 'local_failures')}
                      for key, value in result['samples'].items()}, indent=2))


if __name__ == '__main__':
    main()
