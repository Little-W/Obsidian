#!/usr/bin/env python3
"""Count and simulate complete March sequences in the handbook.

This is a fault-free word-value model, not a physical fault-coverage proof.
Every arbitrary-direction element is independently tried in both directions.
No third-party packages are required.
"""
from pathlib import Path
from itertools import product
import re
import json

ROOT = Path(__file__).resolve().parents[1]

def extract():
    for name in ('03_March基础与经典算法.md', '04_增强March与复杂故障测试.md'):
        text = (ROOT / name).read_text(encoding='utf-8')
        for match in re.finditer(r'```[^\n]*\n([\s\S]*?)```', text):
            block = match[1]
            br = re.search(r'\{([\s\S]*?)\}', block)
            if not br:
                continue
            elements = re.findall(r'([↑↓⇕])\s*\(([^()]*)\)', br[1])
            if not elements:
                continue
            remainder = re.sub(r'([↑↓⇕])\s*\(([^()]*)\)', '', br[1])
            if re.sub(r'[;\s]', '', remainder):
                continue
            operations = []
            for direction, raw in elements:
                ops = [x.strip() for x in raw.split(',')]
                if not all(re.fullmatch(r'[rw][01]', op) for op in ops):
                    break
                operations.append((direction, ops))
            else:
                before = text[:match.start()]
                labels = re.findall(r'(?m)^(?:#{2,5}\s+([^\n]+)|\*\*([^\n]+?)\*\*)', before)
                label = next((a or b for a, b in reversed(labels)), name)
                yield name, before.count('\n') + 1, label, operations, block.strip()

def main():
    results, errors = [], []
    for name, line, label, elements, block in extract():
        n_arbitrary = sum(direction == '⇕' for direction, _ in elements)
        coefficient = sum(len(ops) for _, ops in elements)
        tests = []
        for size in (1, 2, 4, 7, 16):
            for choices in product(('↑', '↓'), repeat=n_arbitrary):
                choices_iter = iter(choices)
                memory = [None] * size
                count = 0
                failures = []
                for stage, (direction, ops) in enumerate(elements):
                    if direction == '⇕':
                        direction = next(choices_iter)
                    addresses = range(size) if direction == '↑' else range(size - 1, -1, -1)
                    for address in addresses:
                        for op in ops:
                            expected = int(op[1])
                            if op[0] == 'w':
                                memory[address] = expected
                            elif memory[address] != expected:
                                failures.append({'stage': stage, 'address': address,
                                                 'expected': expected, 'actual': memory[address]})
                            count += 1
                okay = count == coefficient * size and not failures
                if not okay:
                    errors.append({'file': name, 'line': line, 'size': size,
                                   'choices': choices, 'failures': failures})
                tests.append({'N': size, 'arbitrary_directions': choices,
                              'operations': count, 'final_values': sorted(set(memory)), 'passed': okay})
        results.append({'file': name, 'line': line, 'label': label,
                        'operations_per_address': coefficient, 'sequence': block,
                        'test_count': len(tests), 'tests': tests})
    output = {'scope': 'Fault-free initialization/read-expectation/count simulation; no fault-coverage proof.',
              'sequence_count': len(results), 'simulation_count': sum(r['test_count'] for r in results),
              'errors': errors, 'passed': bool(results) and not errors, 'sequences': results}
    (ROOT / 'checks').mkdir(exist_ok=True)
    (ROOT / 'checks/march_sequences.json').write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in output.items() if k != 'sequences'}, ensure_ascii=False, indent=2))
    for item in results:
        print(f"{item['operations_per_address']:2d}N  {item['label']}")
    if not output['passed']:
        raise SystemExit(1)

if __name__ == '__main__':
    main()
