"""Render historical measurements; no inference or synthetic measurements."""
from pathlib import Path
import csv
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

ROOT = Path(__file__).resolve().parent
plt.rcParams.update({'font.family': 'DejaVu Sans', 'font.size': 11,
                     'svg.fonttype': 'none', 'svg.hashsalt': 'llm-quantization-method', 'axes.spines.top': False,
                     'axes.spines.right': False})

def rows(name):
    with (ROOT / name).open(newline='', encoding='utf-8') as stream:
        return list(csv.DictReader(stream))

def save(fig, name):
    svg = ROOT / (name + '.svg')
    fig.savefig(svg, bbox_inches='tight', metadata={'Date': None})
    svg.write_text('\n'.join(line.rstrip() for line in svg.read_text().splitlines()) + '\n')
    fig.savefig(ROOT / (name + '.png'), bbox_inches='tight', dpi=160)
    plt.close(fig)

r = rows('accuracy.csv'); x = list(range(len(r)))
fig, ax = plt.subplots(figsize=(11, 4.5))
a = [100 * float(i['top1_matches']) / float(i['positions']) for i in r]
b = [100 * float(i['top32_overlap']) / float(i['topk']) for i in r]
ax.bar([i - .19 for i in x], a, .38, label='Top-1 agreement', color='#286ca0')
ax.bar([i + .19 for i in x], b, .38, label='Top-32 overlap', color='#cc882b')
ax.set(xticks=x, xticklabels=[i['condition'] for i in r], ylim=(0, 100),
       ylabel='Agreement / overlap (%)', title='Same forced history: 30 output positions')
ax.legend(loc='lower left');ax.grid(axis='y', alpha=.18);ax.set_axisbelow(True)
for i, v in enumerate(a): ax.text(i - .19, v + 1, f'{v:.1f}', ha='center', fontsize=9)
for i, v in enumerate(b): ax.text(i + .19, v + 1, f'{v:.1f}', ha='center', fontsize=9)
fig.text(.1, -.01, 'Fixed-history numerical comparison; this is not a long-dialogue quality score.', fontsize=9)
save(fig, 'accuracy')

r = rows('block_error.csv');fig, axs = plt.subplots(1, 2, figsize=(9, 4.3))
for ax, item in zip(axs, r):
    vals=[float(item['baseline_relative_l2']),float(item['candidate_relative_l2'])]
    ax.bar(['Baseline', 'Candidate'], vals, color=['#7b8791', '#286ca0'])
    ax.set(title=item['experiment'], ylabel='Held-out relative L2', ylim=(0, .041))
    for i,v in enumerate(vals):ax.text(i,v+.001,f'{v:.6f}',ha='center',fontsize=10)
fig.tight_layout();fig.text(.09,-.035,'Separate held-out experiments. A local gain does not establish dialogue correctness.',fontsize=9)
save(fig, 'block_error')

r=rows('performance.csv');fig, ax=plt.subplots(figsize=(9,4.5))
labels=['CModel\nisolated position','CModel\nfeedback position 30','SoC DDR\nisolated program','SoC DDR\nisolated turn']
v=[float(i['frequency_hz']) / int(i['cycles']) for i in r]
ax.bar(labels,v,color=['#286ca0','#286ca0','#cc882b','#cc882b'])
ax.set(ylabel='Cycle-equivalent token/s at 100 MHz',ylim=(0,3.1),title='Historical numerical programs: different inputs and timing models')
for i,value in enumerate(v):ax.text(i,value+.04,f'{value:.5f}',ha='center')
ax.grid(axis='y',alpha=.18);ax.set_axisbelow(True)
fig.text(.09,-.01,'Not host throughput; not a full UART dialogue benchmark or a speedup comparison.',fontsize=9)
save(fig,'performance')
