#!/usr/bin/env python3
"""Check address-based March iC- expansion and explicit stale-wordline faults."""
import json
from pathlib import Path

SPECIAL_ORDER = [0, 1, 3, 2, 6, 4, 5, 7, 15, 13, 12, 14, 10, 11, 9, 8]


def expanded(order, phase=0, final_reverse=False):
    n = len(order)
    assert n % 2 == 0 and sorted(order) == list(range(n))
    assert all((a ^ b).bit_count() == 1 for a, b in zip(order, order[1:]))
    background = {address: phase ^ (index % 2) for index, address in enumerate(order)}
    stages = [
        (False, [('w', 0)]),
        (False, [('r', 0), ('w', 1)]),
        (False, [('r', 1), ('w', 0)]),
        (True, [('r', 0), ('w', 1)]),
        (True, [('r', 1), ('w', 0)]),
        (final_reverse, [('r', 0)]),
    ]
    operations = []
    for stage, (reverse, motif) in enumerate(stages):
        for address in reversed(order) if reverse else order:
            for kind, invert in motif:
                operations.append((stage, address, kind, background[address] ^ invert))
    assert len(operations) == 10 * n
    return background, operations


def sense(values):
    """Return a definite bit only when all selected cells contain that bit."""
    unique = set(values)
    return unique.pop() if len(unique) == 1 else 'X'


def run(order, phase=0, fault=None, final_reverse=False):
    background, operations = expanded(order, phase, final_reverse)
    memory = [None] * len(order)
    previous = None
    stale = None
    unknown_reads = []
    activations = []
    first_error = None
    for step, (stage, address, kind, expected) in enumerate(operations, 1):
        if address != previous:
            stale = previous if fault is not None and (previous, address) == fault else None
            if stale is not None:
                activations.append({'step': step, 'stage': stage, 'transition': list(fault)})
        selected = [address] if stale is None else [address, stale]
        if kind == 'w':
            for cell in selected:
                memory[cell] = expected
        else:
            actual = sense(memory[cell] for cell in selected)
            record = {'step': step, 'stage': stage, 'address': address,
                      'expected': expected, 'actual': actual, 'selected': selected}
            if actual == 'X':
                unknown_reads.append(record)
            elif actual != expected and first_error is None:
                first_error = record
        previous = address
    return {'operations': len(operations), 'first_error': first_error,
            'unknown_reads': unknown_reads, 'activations': activations,
            'final_memory': memory, 'background': background}


def main():
    assert sense([0, 0]) == 0 and sense([1, 1]) == 1 and sense([0, 1]) == 'X'
    orders = [[i ^ (i >> 1) for i in range(n)] for n in (4, 8, 16)] + [SPECIAL_ORDER]
    healthy_count = fault_count = 0
    for order in orders:
        for phase in (0, 1):
            for reverse in (False, True):
                result = run(order, phase, final_reverse=reverse)
                assert result['first_error'] is None and not result['unknown_reads']
                assert result['final_memory'] == [result['background'][i] for i in range(len(order))]
                healthy_count += 1
            pairs = [(a, b) for a, b in zip(order, order[1:])]
            pairs += [(b, a) for a, b in zip(order, order[1:])]
            for fault in pairs:
                result = run(order, phase, fault)
                assert result['first_error'] is not None, (order, phase, fault)
                fault_count += 1
    needed = {(a, a ^ (1 << bit)) for a in range(4) for bit in range(2)}
    seen = {(a & 3, b & 3) for a, b in zip(SPECIAL_ORDER, SPECIAL_ORDER[1:])
            if (a & 3) != (b & 3)}
    assert seen == needed
    example = run([0, 1, 3, 2], fault=(0, 1))
    assert example['first_error']['step'] == 5
    assert example['first_error']['selected'] == [0]
    report = {
        'scope': 'Independent digital examples; not an electrical or complete decoder-coverage simulation.',
        'healthy_runs': healthy_count, 'stale_wordline_fault_runs': fault_count,
        'target_subdecoder_bits': [1, 0], 'directed_projected_edges': sorted(map(list, seen)),
        'address_order': SPECIAL_ORDER, 'example': example, 'passed': True,
    }
    output = Path(__file__).resolve().parents[1] / 'examples/march_ic_results.json'
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in report.items() if k != 'example'}, ensure_ascii=False, indent=2))
    print('Example first error:', example['first_error'])


if __name__ == '__main__':
    main()
