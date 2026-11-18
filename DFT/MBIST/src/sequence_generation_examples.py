#!/usr/bin/env python3
"""Reproducible finite examples for March sequence generation.

The local models are defined in chapter 05. They are teaching models and have
no transistor-level, timing, retention, multiport, or linked-fault semantics.
Only the Python standard library is required.
"""
from __future__ import annotations

from collections import deque
from dataclasses import dataclass
from itertools import product
from pathlib import Path
import argparse
import json
import math
import random

ROOT = Path(__file__).resolve().parents[1]


def euler_circuit(vertex_count: int, edges: list[tuple[int, int, str]], start: int) -> list[int]:
    """Return edge indices with Hierholzer's algorithm on a directed graph."""
    outgoing: list[list[int]] = [[] for _ in range(vertex_count)]
    indegree = [0] * vertex_count
    for index, (src, dst, _label) in enumerate(edges):
        outgoing[src].append(index)
        indegree[dst] += 1
    assert all(len(outgoing[v]) == indegree[v] for v in range(vertex_count))
    # Reverse once so the original edge order determines traversal order.
    for indexes in outgoing:
        indexes.reverse()
    stack: list[tuple[int, int | None]] = [(start, None)]
    reverse_edges: list[int] = []
    while stack:
        vertex, incoming = stack[-1]
        if outgoing[vertex]:
            edge_index = outgoing[vertex].pop()
            stack.append((edges[edge_index][1], edge_index))
        else:
            stack.pop()
            if incoming is not None:
                reverse_edges.append(incoming)
    circuit = list(reversed(reverse_edges))
    assert len(circuit) == len(edges)
    assert len(set(circuit)) == len(edges)
    current = start
    for index in circuit:
        src, dst, _label = edges[index]
        assert src == current
        current = dst
    assert current == start
    return circuit


def state_bits(value: int) -> list[int]:
    return [(value >> 1) & 1, value & 1]


def euler_example() -> dict:
    # This order gives the circuit printed in the chapter.
    states = [0b00, 0b10, 0b11, 0b01, 0b00, 0b01, 0b11, 0b10, 0b00]
    edges = []
    for src, dst in zip(states, states[1:]):
        addr = 0 if (src ^ dst) == 2 else 1
        bit = state_bits(dst)[addr]
        edges.append((src, dst, f'w{bit}@{addr}'))
    circuit = euler_circuit(4, edges, 0)
    actual_states = [0] + [edges[i][1] for i in circuit]
    assert actual_states == states
    expected_edges = {(s, s ^ (1 << b)) for s in range(4) for b in range(2)}
    assert {(s, t) for s, t, _ in edges} == expected_edges
    program: list[tuple[str, int, int]] = [('w', 0, 0), ('w', 1, 0)]
    row_records = []
    for step, index in enumerate(circuit, start=1):
        src, dst, label = edges[index]
        addr = int(label[-1])
        value = int(label[1])
        bits = state_bits(dst)
        chunk = [('w', addr, value), ('r', 0, bits[0]), ('r', 1, bits[1])]
        program.extend(chunk)
        row_records.append({'step': step, 'source': format(src, '02b'),
                            'destination': format(dst, '02b'),
                            'operations': [f'{op}{val}@{a}' for op, a, val in chunk]})
    faults = []
    for addr in range(2):
        for value in range(2):
            faults.append(('SAF', addr, value, None))
            faults.append(('TF', addr, value, None))
    for aggressor in range(2):
        for before in range(2):
            for victim_before in range(2):
                faults.append(('CF', aggressor, before, victim_before))
    records = []
    delayed_records = []
    delayed = [op for op in program if op[0] == 'w'] + [('r', 0, 0), ('r', 1, 0)]
    for fault in faults:
        for initial in product((0, 1), repeat=2):
            mismatch = replay_pair(program, fault, initial)
            assert mismatch is not None, (fault, initial)
            records.append({'fault': list(fault), 'initial': list(initial), 'first_mismatch': mismatch})
            late_mismatch = replay_pair(delayed, fault, initial)
            delayed_records.append({'fault': list(fault), 'initial': list(initial),
                                    'detected': late_mismatch is not None})
    assert len(program) == 26
    assert sum(x['detected'] for x in delayed_records) < len(delayed_records)
    return {'scope': 'Two isolated cells, one active fault primitive per run.',
            'states': [format(x, '02b') for x in actual_states],
            'required_edges': len(expected_edges), 'visited_edges': len(circuit),
            'rows': row_records, 'operation_count': len(program),
            'fault_primitive_count': len(faults), 'initial_states_per_primitive': 4,
            'detected_scenarios': len(records), 'scenario_count': len(records),
            'detection_records': records,
            'final_read_only_detected_scenarios': sum(x['detected'] for x in delayed_records),
            'final_read_only_records': delayed_records}


def replay_pair(program: list[tuple[str, int, int]], fault: tuple,
                initial: tuple[int, int]) -> dict | None:
    """Replay writes and reads on actual cell values, including observations."""
    kind, target, value, victim_value = fault
    actual = list(initial)
    if kind == 'SAF':
        actual[target] = value
    for step, (op, addr, data) in enumerate(program, start=1):
        old = actual[addr]
        if op == 'r':
            if actual[addr] != data:
                return {'step': step, 'address': addr, 'expected': data,
                        'observed': actual[addr]}
            continue
        actual[addr] = data
        if kind == 'SAF':
            actual[target] = value
        elif kind == 'TF' and addr == target and old == value and data == 1 - value:
            actual[addr] = old
        elif (kind == 'CF' and addr == target and old == value and data == 1 - value
              and actual[1 - target] == victim_value):
            actual[1 - target] ^= 1
    return None


KINDS = ('SAF', 'TF', 'WDF', 'RDF', 'DRDF', 'D2R')
SCENARIOS = tuple((kind, value, initial) for kind in KINDS for value in (0, 1)
                  for initial in (0, 1))
ACTIONS = ('r', 'w0', 'w1')


def initial_product_state() -> tuple:
    encoded = []
    for kind, value, initial in SCENARIOS:
        encoded.append(value if kind == 'SAF' else initial)
    return (-1, *encoded)


def product_step(state: tuple, action: str) -> tuple:
    """Advance the search state; -1 marks a scenario already detected."""
    ideal = state[0]
    is_read = action == 'r'
    if is_read:
        assert ideal in (0, 1)
        new_ideal = ideal
    else:
        new_ideal = int(action[1])
    out = [new_ideal]
    for encoded, (kind, value, _initial) in zip(state[1:], SCENARIOS):
        if encoded == -1:
            out.append(-1)
            continue
        bit = encoded & 1
        reads = encoded >> 1
        if is_read:
            returned = bit
            new_bit, new_reads = bit, 0
            if kind == 'RDF' and bit == value:
                new_bit ^= 1
                returned = new_bit
            elif kind == 'DRDF' and bit == value:
                new_bit ^= 1
            elif kind == 'D2R' and bit == value:
                new_reads = min(reads + 1, 2)
                if new_reads == 2:
                    new_bit ^= 1
            if returned != ideal:
                out.append(-1)
            else:
                out.append(new_bit + 2 * new_reads)
        else:
            new_bit = new_ideal
            if kind == 'SAF':
                new_bit = value
            elif kind == 'TF' and bit == value and new_ideal == 1 - value:
                new_bit = bit
            elif kind == 'WDF' and bit == value and new_ideal == value:
                new_bit = 1 - value
            out.append(new_bit)
    return tuple(out)


def evaluate_actions(actions: tuple[str, ...] | list[str]) -> tuple[int, tuple]:
    assert actions and actions[0] == 'w0'
    state = initial_product_state()
    for action in actions:
        state = product_step(state, action)
    return sum(value == -1 for value in state[1:]), state


def format_sequence(actions: tuple[str, ...] | list[str]) -> list[str]:
    ideal = None
    sequence = []
    for action in actions:
        if action == 'r':
            assert ideal is not None
            sequence.append(f'r{ideal}')
        else:
            ideal = int(action[1])
            sequence.append(action)
    return sequence


def breadth_first_optimum() -> dict:
    first = product_step(initial_product_state(), 'w0')
    queue = deque([first])
    parent: dict[tuple, tuple[tuple | None, str]] = {first: (None, 'w0')}
    depth = {first: 1}
    depth_counts: dict[int, int] = {}
    while queue:
        state = queue.popleft()
        current_depth = depth[state]
        depth_counts[current_depth] = depth_counts.get(current_depth, 0) + 1
        if all(value == -1 for value in state[1:]):
            actions = []
            cursor = state
            while cursor is not None:
                previous, action = parent[cursor]
                actions.append(action)
                cursor = previous
            actions.reverse()
            return {'operation_count': len(actions), 'actions': actions,
                    'sequence': format_sequence(actions), 'visited_product_states': len(parent),
                    'dequeued_product_states': sum(depth_counts.values()),
                    'depth_counts': depth_counts,
                    'search_space': 'All sequences beginning with w0 over r,w0,w1; read expectations from ideal state.'}
        for action in ACTIONS:
            candidate = product_step(state, action)
            if candidate not in parent:
                parent[candidate] = (state, action)
                depth[candidate] = current_depth + 1
                queue.append(candidate)
    raise AssertionError('No complete sequence exists in the finite search space.')


def simulated_annealing(seed: int = 20261118, iterations: int = 6000) -> dict:
    rng = random.Random(seed)
    current = tuple(['w0', 'r', 'r', 'r', 'w0', 'r', 'r', 'r',
                     'w1', 'r', 'r', 'r', 'w1', 'r', 'r', 'r',
                     'w0', 'r', 'r', 'r'])
    initial = current
    total = len(SCENARIOS)
    penalty = 100

    def energy(sequence: tuple[str, ...]) -> int:
        detected, _state = evaluate_actions(sequence)
        return penalty * (total - detected) + len(sequence)

    assert evaluate_actions(current)[0] == total
    current_energy = energy(current)
    best, best_energy = current, current_energy
    improvements = [{'iteration': 0, 'length': len(best), 'detected_scenarios': total,
                     'sequence': format_sequence(best)}]
    accepted = 0
    uphill_accepted = 0
    for iteration in range(iterations):
        temperature = 4.0 * (0.05 / 4.0) ** (iteration / max(1, iterations - 1))
        proposal = list(current)
        move = rng.choice(('delete', 'insert', 'replace'))
        if move == 'delete' and len(proposal) > 2:
            del proposal[rng.randrange(1, len(proposal))]
        elif move == 'insert' and len(proposal) < 40:
            proposal.insert(rng.randrange(1, len(proposal) + 1), rng.choice(ACTIONS))
        elif move == 'replace':
            proposal[rng.randrange(1, len(proposal))] = rng.choice(ACTIONS)
        else:
            continue
        candidate = tuple(proposal)
        candidate_energy = energy(candidate)
        delta = candidate_energy - current_energy
        if delta <= 0 or rng.random() < math.exp(-delta / temperature):
            current, current_energy = candidate, candidate_energy
            accepted += 1
            uphill_accepted += int(delta > 0)
            if current_energy < best_energy:
                best, best_energy = current, current_energy
                detected, _state = evaluate_actions(best)
                improvements.append({'iteration': iteration + 1, 'length': len(best),
                                     'detected_scenarios': detected,
                                     'sequence': format_sequence(best)})
    detected, _state = evaluate_actions(best)
    return {'seed': seed, 'iterations': iterations, 'temperature_start': 4.0,
            'temperature_end': 0.05, 'missing_scenario_penalty': penalty,
            'maximum_candidate_length': 40, 'initial_length': len(initial),
            'initial_sequence': format_sequence(initial), 'actions': list(best),
            'sequence': format_sequence(best), 'operation_count': len(best),
            'scenario_count': total, 'detected_scenarios': detected,
            'accepted_proposals': accepted, 'accepted_uphill_proposals': uphill_accepted,
            'improvements': improvements}


@dataclass
class CellModel:
    kind: str
    parameter: int
    value: int
    consecutive_reads: int = 0

    def write(self, data: int) -> None:
        before = self.value
        self.consecutive_reads = 0
        if self.kind == 'SAF':
            self.value = self.parameter
        elif self.kind == 'TF' and before == self.parameter and data != before:
            self.value = before
        elif self.kind == 'WDF' and before == self.parameter and data == before:
            self.value = 1 - before
        else:
            self.value = data

    def read(self) -> int:
        returned = self.value
        if self.kind == 'RDF' and self.value == self.parameter:
            self.value = 1 - self.value
            returned = self.value
        elif self.kind == 'DRDF' and self.value == self.parameter:
            self.value = 1 - self.value
        elif self.kind == 'D2R':
            if self.value == self.parameter:
                self.consecutive_reads += 1
                if self.consecutive_reads == 2:
                    self.value = 1 - self.value
            else:
                self.consecutive_reads = 0
        return returned


def independent_replay(sequence: list[str]) -> list[dict]:
    """Use a separate mutable model and explicit read values for verification."""
    records = []
    for kind, parameter, initial in SCENARIOS:
        actual_initial = parameter if kind == 'SAF' else initial
        cell = CellModel(kind, parameter, actual_initial)
        first = None
        trace = []
        for step, token in enumerate(sequence, start=1):
            before = cell.value
            if token[0] == 'w':
                cell.write(int(token[1]))
                returned = None
            else:
                returned = cell.read()
                if returned != int(token[1]) and first is None:
                    first = step
            trace.append({'step': step, 'operation': token, 'before': before,
                          'returned': returned, 'after': cell.value,
                          'consecutive_reads': cell.consecutive_reads})
        records.append({'fault': f'{kind}{parameter}', 'initial': initial,
                        'detected': first is not None, 'first_mismatch_step': first,
                        'trace': trace})
    return records


def verify_model_implementations() -> dict:
    # Compare every short legal sequence between the two implementations.
    count = 0
    for suffix_length in range(6):
        for suffix in product(ACTIONS, repeat=suffix_length):
            actions = ('w0',) + suffix
            covered, state = evaluate_actions(actions)
            records = independent_replay(format_sequence(actions))
            expected = [encoded == -1 for encoded in state[1:]]
            observed = [entry['detected'] for entry in records]
            assert observed == expected
            assert covered == sum(observed)
            count += 1
    return {'sequences_compared': count, 'maximum_sequence_length': 6,
            'scenarios_per_sequence': len(SCENARIOS), 'passed': True}


def de_bruijn_example() -> dict:
    cycle = '00010111'
    windows = [((cycle + cycle[:2])[i:i + 3]) for i in range(len(cycle))]
    assert len(set(windows)) == 8
    assert set(windows) == {''.join(bits) for bits in product('01', repeat=3)}
    linear = cycle + cycle[:2]
    return {'alphabet_size': 2, 'window_length': 3, 'cyclic_sequence': cycle,
            'linear_sequence': linear, 'windows': windows, 'distinct_windows': len(set(windows))}


def cover_example() -> dict:
    sets = [{0, 1, 2}, {2, 3}, {0, 3}, {1}]
    costs = [4, 3, 3, 2]
    universe = {0, 1, 2, 3}
    options = []
    for flags in product((0, 1), repeat=4):
        chosen = [i for i, flag in enumerate(flags) if flag]
        covered = set().union(*(sets[i] for i in chosen))
        if covered == universe:
            options.append((sum(costs[i] for i in chosen), chosen))
    optimum = min(cost for cost, _chosen in options)
    choices = [chosen for cost, chosen in options if cost == optimum]
    return {'costs': costs, 'sets': [sorted(s) for s in sets], 'minimum_cost': optimum,
            'minimum_cost_choices_zero_based': choices,
            'assumption': 'Each candidate includes its own complete initialization and observation.'}



def published_sequence_examples() -> dict:
    sequences = {
        'DDQN_AB1_subset_5N': [('+', ['w0']), ('+', ['w1', 'r1']),
                             ('-', ['w0', 'r0'])],
        'DDQN_AB1_residual_11N': [('+', ['w0']), ('+', ['w1', 'r1', 'r1']),
                                ('-', ['w1', 'r1', 'w0', 'r0', 'r0', 'w0', 'r0'])],
        'DDQN_LR_residual_16N': [('+', ['w1']),
                               ('+', ['r1', 'w1', 'r1', 'r1', 'w0', 'w0', 'r0']),
                               ('+', ['r0', 'w0', 'r0', 'r0', 'w1', 'w1', 'r1']),
                               ('+', ['r1'])],
    }
    results = {}
    for name, elements in sequences.items():
        coefficient = sum(len(ops) for _direction, ops in elements)
        for depth in (2, 4, 16):
            for initial_value in (0, 1):
                memory = [initial_value] * depth
                count = 0
                for direction, operations in elements:
                    addresses = range(depth) if direction == '+' else range(depth - 1, -1, -1)
                    for address in addresses:
                        for operation in operations:
                            value = int(operation[1])
                            if operation[0] == 'w':
                                memory[address] = value
                            else:
                                assert memory[address] == value, (name, depth, address, operation)
                            count += 1
                assert count == coefficient * depth
        results[name] = {'coefficient': coefficient, 'fault_free_depths': [2, 4, 16],
                         'fault_free_initial_backgrounds': [0, 1], 'fault_free_passed': True}
    # Two explicit a < v teaching traces for Table I's 11N program.
    for kind in ('CFwd', 'CFdrd'):
        memory = [0, 0]
        trace = []
        mismatch = None
        for element, (direction, operations) in enumerate(sequences['DDQN_AB1_residual_11N']):
            addresses = range(2) if direction == '+' else range(1, -1, -1)
            for address in addresses:
                for operation in operations:
                    expected = int(operation[1])
                    before = list(memory)
                    observed = None
                    trigger = (address == 1 and memory[0] == 1 and memory[1] == 1)
                    if operation[0] == 'w':
                        memory[address] = expected
                        if kind == 'CFwd' and trigger and expected == 1:
                            memory[address] = 0
                    else:
                        observed = memory[address]
                        if kind == 'CFdrd' and trigger:
                            memory[address] = 0
                        if observed != expected and mismatch is None:
                            mismatch = len(trace) + 1
                    trace.append({'step': len(trace) + 1, 'element': element, 'address': address,
                                  'operation': operation, 'before': before, 'observed': observed,
                                  'after': list(memory)})
        assert mismatch is not None
        results[f'11N_{kind}_a0_v1'] = {'first_mismatch': mismatch, 'trace': trace}
    return results


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT / 'examples/sequence_generation_results.json')
    args = parser.parse_args()
    result = {'schema_version': 1, 'model_scope': 'Finite teaching examples defined in chapter 05.',
              'euler': euler_example(), 'de_bruijn': de_bruijn_example(),
              'set_cover': cover_example(), 'published_sequences': published_sequence_examples(),
              'model_consistency': verify_model_implementations(),
              'simulated_annealing': simulated_annealing(), 'breadth_first': breadth_first_optimum()}
    for key in ('simulated_annealing', 'breadth_first'):
        sequence = result[key]['sequence']
        records = independent_replay(sequence)
        assert all(record['detected'] for record in records)
        result[key]['independent_detection_records'] = records
    assert result['simulated_annealing']['operation_count'] >= result['breadth_first']['operation_count']
    result['passed'] = True
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'passed': result['passed'], 'euler_detected': result['euler']['detected_scenarios'],
                      'euler_total': result['euler']['scenario_count'],
                      'delayed_read_detected': result['euler']['final_read_only_detected_scenarios'],
                      'annealing_length': result['simulated_annealing']['operation_count'],
                      'annealing_sequence': result['simulated_annealing']['sequence'],
                      'exact_length': result['breadth_first']['operation_count'],
                      'exact_sequence': result['breadth_first']['sequence'],
                      'exact_states': result['breadth_first']['visited_product_states'],
                      'model_comparisons': result['model_consistency']}, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
