#!/usr/bin/env python3
"""Export checked, fault-free March accesses using the handbook definitions.

Fixed sequences come from validate_march_sequences.extract(), March iC- from
validate_march_ic.expanded(), and transparent tests from transparent_march_examples.run().
The exporter does not contain a second copy of their operation sequences.
"""
from __future__ import annotations

import argparse
import csv
from itertools import product
import json
from pathlib import Path
import re
import unicodedata

import validate_march_sequences as fixed
import validate_march_ic as ic
import transparent_march_examples as transparent

ROOT = Path(__file__).resolve().parents[1]
FIELDS = [
    'algorithm', 'stage', 'step', 'address', 'operation', 'expected_read',
    'write_value', 'observed_read', 'cell_before', 'cell_after',
    'state_before', 'state_after', 'direction', 'background', 'observation',
]
SNAPSHOT_LIMIT = 16
# The source transparent simulator stores a full memory snapshot per access.
TRANSPARENT_SIZE_LIMIT = 256


def normalize(name: str) -> str:
    name = unicodedata.normalize('NFKC', name).replace('−', '-').replace('–', '-')
    return re.sub(r'[\s_]', '', name).lower()


def registry() -> list[dict]:
    entries = []
    for source, line, label, elements, sequence in fixed.extract():
        match = re.search(r'\bMarch\s+([A-Za-z][A-Za-z0-9+−-]*)', label)
        mats = re.search(r'\bMATS\+{0,2}', label)
        if match:
            short = match[1].replace('−', '-')
            name = f'March {short}'
            aliases = [short]
        elif mats:
            name = mats[0]
            aliases = []
        elif '分离读取' in label:
            name, aliases = 'March 13N separated reads', ['13N separated reads']
        else:
            raise ValueError(f'Cannot derive an algorithm name from source label: {label}')
        entries.append({'name': name, 'aliases': aliases, 'kind': 'fixed',
                        'source': source, 'source_line': line, 'source_label': label,
                        'definition_provider': 'validate_march_sequences.extract',
                        'coefficient': sum(len(ops) for _, ops in elements),
                        'elements': elements, 'sequence': sequence,
                        'capacity_rule': 'Any positive integer number of one-bit addresses.'})
    entries.append({'name': 'March iC-', 'aliases': ['iC-'], 'kind': 'ic',
                    'source': 'src/validate_march_ic.py',
                    'definition_provider': 'validate_march_ic.expanded', 'coefficient': 10,
                    'capacity_rule': 'Power of two, at least 2; reflected Gray-code address order.'})
    for variant in (1, 2):
        entries.append({'name': f'March_2A_{variant}', 'aliases': [f'2A_{variant}'],
                        'kind': 'transparent', 'variant': variant,
                        'source': 'src/transparent_march_examples.py',
                        'definition_provider': 'transparent_march_examples.run',
                        'coefficient': 8 if variant == 1 else 14,
                        'capacity_rule': f'Power of two from 2 through {TRANSPARENT_SIZE_LIMIT}; two full address sweeps.'})
    names = [normalize(entry['name']) for entry in entries]
    if len(names) != len(set(names)):
        raise ValueError('The source definitions contain duplicate algorithm names.')
    return entries


def resolve(name: str, entries: list[dict]) -> dict:
    requested = normalize(name)
    matches = [entry for entry in entries
               if requested in {normalize(x) for x in [entry['name'], *entry['aliases']]}]
    if len(matches) != 1:
        raise ValueError(f'Unknown algorithm {name!r}. Use --list to see supported names.')
    return matches[0]


def initial_values(value: str | None, size: int, kind: str) -> list[int | None]:
    if value is None:
        return [index % 2 for index in range(size)] if kind == 'transparent' else [None] * size
    if not re.fullmatch('[01]+', value):
        raise ValueError('--initial must contain only 0 and 1.')
    if len(value) == 1:
        value *= size
    if len(value) != size:
        raise ValueError(f'--initial needs one bit or exactly {size} bits; received {len(value)}.')
    return [int(bit) for bit in value]


def bit_text(value: int | None) -> str:
    return 'x' if value is None else str(value)


def state_text(memory: list[int | None]) -> str:
    return ''.join(bit_text(bit) for bit in memory) if len(memory) <= SNAPSHOT_LIMIT else ''


def row_for(name, stage, step, address, kind, expected, write_value, observed,
            before, after, direction, background, observation, *, cell_before=None) -> dict[str, str]:
    values = dict(algorithm=name, stage=stage, step=step, address=address,
                  operation=(f'w{write_value}' if kind == 'w' else
                             f'r{expected}' if expected is not None else 'r'),
                  expected_read=expected, write_value=write_value, observed_read=observed,
                  cell_before=bit_text(cell_before if before is None else before[address]),
                  cell_after=bit_text(after[address]),
                  state_before=state_text(before) if before is not None else '', state_after=state_text(after),
                  direction=direction, background=background, observation=observation)
    return {key: '' if values[key] is None else str(values[key]) for key in FIELDS}


def build_trace(entry: dict, size: int, initial: str | None = None) -> tuple[list[dict], dict]:
    if size < 1:
        raise ValueError('--size must be a positive integer.')
    kind = entry['kind']
    if kind in ('ic', 'transparent') and (size < 2 or size & (size - 1)):
        raise ValueError(f'{entry["name"]} requires a power-of-two --size of at least 2.')
    if kind == 'transparent' and size > TRANSPARENT_SIZE_LIMIT:
        raise ValueError(f'{entry["name"]} trace export supports --size <= {TRANSPARENT_SIZE_LIMIT}; '
                         'the source simulator records a full memory snapshot for every access.')
    memory = initial_values(initial, size, kind)
    original = list(memory)
    rows = []
    meta = {'algorithm': entry['name'], 'kind': kind, 'size': size,
            'operations_per_address': entry['coefficient'], 'initial_state': original,
            'source': entry['source'], 'definition_provider': entry['definition_provider'],
            'full_state_columns_included': size <= SNAPSHOT_LIMIT,
            'state_address_order': 'Ascending logical addresses, left to right.'}
    if kind == 'transparent':
        order = transparent.double_addresses(size, size.bit_length() - 1)
        result = transparent.run(list(memory), order, entry['variant'], capture=True)
        if result['detected'] or not result['restored']:
            raise ValueError('The source transparent simulator failed its fault-free checks.')
        for item in result['trace']:
            stage = item['phase']
            op = item['operation']
            before, after = list(memory), item['memory_after']
            if stage == 'initial_signature':
                observation, direction = 'signature_reference', 'ascending'
            elif stage == 'final_signature':
                observation, direction = 'signature_result', 'ascending'
            else:
                observation = {'read_latch': 'capture_data', 'read_compare': 'local_compare'}.get(op, 'write')
                direction = 'double_forward' if stage == 'base_1' else 'double_reverse'
            write_value = int(op[-1]) if op.startswith('write') else None
            rows.append(row_for(entry['name'], stage, item['step'], item['address'],
                                'w' if write_value is not None else 'r', item['expected'],
                                write_value, item['observed'], before, after,
                                direction, f'initial[{item["address"]}]={original[item["address"]]}', observation))
            memory = list(after)
        meta.update(address_order=order, reverse_address_order=list(reversed(order)),
                    reference_signature=result['reference_signature'],
                    final_signature=result['final_signature'], restored=result['restored'],
                    signature_rule='Teaching CRC-4 x^4+x+1, zero seed, MSB first, final XOR zero.',
                    read_rule='Only local_compare rows have direct expected_read values; signature scans and capture reads are data-dependent.')
    else:
        stream = []
        if kind == 'fixed':
            for stage, (declared_direction, operations) in enumerate(entry['elements']):
                direction = 'descending' if declared_direction == '↓' else 'ascending'
                addresses = range(size - 1, -1, -1) if direction == 'descending' else range(size)
                for address in addresses:
                    for operation in operations:
                        stream.append((f'M{stage}', address, operation[0], int(operation[1]), direction, ''))
            meta.update(sequence=entry['sequence'], arbitrary_direction='ascending',
                        source_line=entry['source_line'])
        else:
            order = [value ^ (value >> 1) for value in range(size)]
            background, operations = ic.expanded(order, phase=0, final_reverse=False)
            stage_orders = {}
            for stage, address, _op, _data in operations:
                stage_order = stage_orders.setdefault(stage, [])
                if not stage_order or stage_order[-1] != address:
                    stage_order.append(address)
            directions = {}
            for stage, stage_order in stage_orders.items():
                if stage_order == order:
                    directions[stage] = 'gray_forward'
                elif stage_order == list(reversed(order)):
                    directions[stage] = 'gray_reverse'
                else:
                    raise ValueError('The iC- source returned an unexpected address order.')
            for stage, address, op, data in operations:
                direction = directions[stage]
                stream.append((f'M{stage}', address, op, data, direction,
                               f'B[{address}]={background[address]}'))
            meta.update(address_order=order, background=[background[a] for a in range(size)],
                        background_phase=0, final_reverse=False)
        for stage, address, op, data, direction, background in stream:
            cell_before = memory[address]
            before = list(memory) if size <= SNAPSHOT_LIMIT else None
            observed = memory[address] if op == 'r' else None
            if op == 'r' and observed != data:
                raise ValueError(f'{entry["name"]} has an incorrect read expectation at access {len(rows)+1}.')
            if op == 'w':
                memory[address] = data
            rows.append(row_for(entry['name'], stage, len(rows) + 1, address, op,
                                data if op == 'r' else None, data if op == 'w' else None,
                                observed, before, memory, direction, background,
                                'direct_compare' if op == 'r' else 'write', cell_before=cell_before))
    meta.update(operation_count=len(rows), final_state=memory,
                read_count=sum(row['operation'].startswith('r') for row in rows),
                write_count=sum(row['operation'].startswith('w') for row in rows))
    validate_rows(rows, meta)
    meta['fault_free_validation_passed'] = True
    return rows, meta


def validate_rows(rows: list[dict], meta: dict) -> None:
    """Independently replay the serialized access fields and both observation types."""
    size = meta['size']
    memory = list(meta['initial_state'])
    latch = None
    initial_scan, final_scan = [], []
    if len(rows) != meta['operations_per_address'] * size:
        raise ValueError('Access count does not match the algorithm coefficient.')
    for step, row in enumerate(rows, 1):
        address = int(row['address'])
        if row['algorithm'] != meta['algorithm'] or int(row['step']) != step or not 0 <= address < size:
            raise ValueError(f'Invalid algorithm, step, or address in row {step}.')
        if row['state_before'] != state_text(memory) or row['cell_before'] != bit_text(memory[address]):
            raise ValueError(f'Incorrect before-state in row {step}.')
        if row['operation'].startswith('w'):
            data = int(row['write_value'])
            if data not in (0, 1) or row['operation'] != f'w{data}' or row['expected_read'] or row['observed_read']:
                raise ValueError(f'Incorrect write fields in row {step}.')
            if meta['kind'] == 'transparent' and latch != (address, 1 - data):
                raise ValueError(f'Transparent write does not complement the captured read in row {step}.')
            memory[address] = data
        else:
            observed = int(row['observed_read'])
            expected = int(row['expected_read']) if row['expected_read'] else None
            if row['write_value'] or observed != memory[address] or (expected is not None and observed != expected):
                raise ValueError(f'Incorrect read fields or expectation in row {step}.')
            if row['operation'] != (f'r{expected}' if expected is not None else 'r'):
                raise ValueError(f'Incorrect read operation in row {step}.')
            if row['observation'] == 'capture_data':
                latch = (address, observed)
            elif row['observation'] == 'local_compare':
                if latch is None or latch[0] != address or expected != 1 - latch[1]:
                    raise ValueError(f'Incorrect local complement comparison in row {step}.')
            elif row['observation'] == 'signature_reference':
                initial_scan.append((address, observed))
            elif row['observation'] == 'signature_result':
                final_scan.append((address, observed))
        if row['state_after'] != state_text(memory) or row['cell_after'] != bit_text(memory[address]):
            raise ValueError(f'Incorrect after-state in row {step}.')
    if memory != meta['final_state']:
        raise ValueError('Final state differs from the generator result.')
    if meta['kind'] == 'transparent':
        if [a for a, _ in initial_scan] != list(range(size)) or [a for a, _ in final_scan] != list(range(size)):
            raise ValueError('Initial and final signature scans must use the same ascending address order.')
        sf = transparent.signature([v for _, v in initial_scan])
        sr = transparent.signature([v for _, v in final_scan])
        if sf != sr or sf != meta['reference_signature'] or sr != meta['final_signature'] or memory != meta['initial_state']:
            raise ValueError('Transparent signature or restoration verification failed.')


def write_csv(path: Path, rows: list[dict], meta: dict) -> dict:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', encoding='utf-8-sig', newline='') as handle:
        writer = csv.DictWriter(handle, fieldnames=FIELDS)
        writer.writeheader()
        writer.writerows(rows)
    with path.open(encoding='utf-8-sig', newline='') as handle:
        reader = csv.DictReader(handle)
        if reader.fieldnames != FIELDS:
            raise ValueError('CSV header differs from the defined export fields.')
        recovered = list(reader)
    if recovered != rows:
        raise ValueError('CSV round-trip changed one or more fields.')
    validate_rows(recovered, meta)
    return {**meta, 'csv_path': str(path), 'csv_round_trip_passed': True}


def public_entry(entry: dict) -> dict:
    return {key: value for key, value in entry.items() if key != 'elements'}


def export_examples(entries: list[dict]) -> dict:
    presets = [('C-', 'march_c_minus_N4.csv'), ('SS', 'march_ss_N4.csv'),
               ('AB', 'march_ab_N4.csv'), ('AZ2', 'march_az2_N4.csv'),
               ('iC-', 'march_ic_minus_N4.csv'), ('2A_2', 'march_2a_2_N4.csv')]
    outputs = []
    for name, filename in presets:
        rows, meta = build_trace(resolve(name, entries), 4)
        result = write_csv(ROOT / 'examples' / 'traces' / filename, rows, meta)
        result['csv_path'] = str(Path('examples/traces') / filename)
        outputs.append(result)
    checks = 0
    for entry in entries:
        sizes = (1, 4, 7) if entry['kind'] == 'fixed' else (2, 4, 8)
        for size in sizes:
            build_trace(entry, size)
            checks += 1
    # Each transparent initial pattern must preserve the data-dependent semantics.
    for name in ('2A_1', '2A_2'):
        for bits in product('01', repeat=4):
            build_trace(resolve(name, entries), 4, ''.join(bits))
            checks += 1
    rejection_checks = [
        ('unknown_algorithm', lambda: resolve('unknown_march_algorithm', entries)),
        ('nonpositive_size', lambda: build_trace(resolve('C-', entries), 0)),
        ('unsupported_ic_size', lambda: build_trace(resolve('iC-', entries), 3)),
        ('unsupported_transparent_size', lambda: build_trace(resolve('2A_2', entries), 3)),
        ('transparent_snapshot_limit', lambda: build_trace(resolve('2A_2', entries), 512)),
        ('initial_pattern_length', lambda: build_trace(resolve('2A_2', entries), 4, '010')),
    ]
    rejections = []
    for name, action in rejection_checks:
        try:
            action()
        except ValueError as error:
            rejections.append({'case': name, 'message': str(error), 'passed': True})
        else:
            raise ValueError(f'Expected input rejection did not occur: {name}')
    report = {'schema_version': 1, 'scope': 'Fault-free logical one-bit access traces.',
              'fixed_sequence_count': sum(entry['kind'] == 'fixed' for entry in entries),
              'algorithm_count': len(entries), 'fields': FIELDS,
              'state_snapshot_limit': SNAPSHOT_LIMIT,
              'algorithms': [public_entry(entry) for entry in entries], 'exports': outputs,
              'validation': {'generated_runs': checks, 'csv_round_trips': len(outputs),
                             'input_rejection_checks': rejections,
                             'read_expectations_passed': True, 'access_counts_passed': True,
                             'transparent_restoration_passed': True}, 'passed': True}
    (ROOT / 'examples' / 'march_trace_catalog.json').write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    return report


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--list', action='store_true', help='List algorithm names and capacity rules.')
    mode.add_argument('--examples', action='store_true', help='Generate six N=4 CSV examples and validate the catalog.')
    mode.add_argument('--algorithm', help='Algorithm name or listed short alias.')
    parser.add_argument('--size', type=int, default=4, help='Number of one-bit addresses (default: 4).')
    parser.add_argument('--initial', help='One repeated bit or one bit per address; transparent default is 0101... .')
    parser.add_argument('--output', type=Path, help='CSV destination for a single algorithm.')
    args = parser.parse_args()
    try:
        entries = registry()
        if (args.list or args.examples) and (args.output is not None or args.initial is not None or args.size != 4):
            raise ValueError('--size, --initial, and --output customize only --algorithm exports.')
        if args.list:
            print(json.dumps([public_entry(entry) for entry in entries], ensure_ascii=False, indent=2))
        elif args.examples:
            report = export_examples(entries)
            print(json.dumps({'passed': report['passed'], 'fixed_sequence_count': report['fixed_sequence_count'],
                              'algorithm_count': report['algorithm_count'], 'csv_round_trips': len(report['exports']),
                              'generated_runs': report['validation']['generated_runs'],
                              'catalog': 'examples/march_trace_catalog.json'}, ensure_ascii=False, indent=2))
        else:
            entry = resolve(args.algorithm, entries)
            rows, meta = build_trace(entry, args.size, args.initial)
            slug = re.sub(r'[^a-z0-9]+', '_', normalize(entry['name']).replace('+', '_plus').replace('-', '_minus')).strip('_')
            path = args.output or ROOT / 'examples' / 'traces' / f'{slug}_N{args.size}.csv'
            result = write_csv(path, rows, meta)
            print(json.dumps(result, ensure_ascii=False, indent=2))
    except (ValueError, OSError, AssertionError) as error:
        parser.error(str(error))


if __name__ == '__main__':
    main()
