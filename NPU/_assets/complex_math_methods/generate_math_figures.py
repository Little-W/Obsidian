#!/usr/bin/env python3
"""Reproducible algorithm illustrations, not RTL performance/accuracy results.

Run this numerical experiment on the remote analysis host. matplotlib is the
only extra dependency. All plots retain SVG, PNG and underlying CSV/JSON data.
"""
from pathlib import Path
import argparse, csv, json, math
from decimal import Decimal, getcontext
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


def cordic(theta, iterations, fraction=None):
    sign = 1
    if theta > math.pi/2:
        theta -= math.pi; sign = -1
    elif theta < -math.pi/2:
        theta += math.pi; sign = -1
    inv_gain = 1/math.prod(math.sqrt(1+2.**(-2*i)) for i in range(iterations))
    if fraction is None:
        x,y,z=inv_gain,0.,theta
        for i in range(iterations):
            d=1 if z>=0 else -1
            x,y,z=x-d*y*2.**(-i),y+d*x*2.**(-i),z-d*math.atan(2.**(-i))
        return sign*x,sign*y
    unit=1<<fraction
    x,y,z=round(inv_gain*unit),0,round(theta*unit)
    for i in range(iterations):
        d=1 if z>=0 else -1
        x,y,z=x-d*(y>>i),y+d*(x>>i),z-d*round(math.atan(2.**(-i))*unit)
        assert -(1<<31)<=x<(1<<31) and -(1<<31)<=y<(1<<31)
    return sign*x/unit,sign*y/unit


def write_csv(path, rows):
    with path.open('w',newline='') as f:
        w=csv.DictWriter(f,fieldnames=list(rows[0]),lineterminator='\n');w.writeheader();w.writerows(rows)


def save(fig, root, name):
    fig.savefig(root/(name+'.svg'),bbox_inches='tight')
    svg=root/(name+'.svg')
    svg.write_text('\n'.join(line.rstrip() for line in svg.read_text().splitlines())+'\n')
    fig.savefig(root/(name+'.png'),dpi=220,bbox_inches='tight')
    plt.close(fig)


def main():
    p=argparse.ArgumentParser();p.add_argument('--output-dir',type=Path,default=Path(__file__).parent)
    root=p.parse_args().output_dir;root.mkdir(parents=True,exist_ok=True)
    plt.rcParams.update({'font.size':11,'axes.spines.top':False,'axes.spines.right':False,'svg.fonttype':'none'})
    rows=[]
    for n in (4,8,12,16,20,24,28,32):
        errors=[0.,0.]
        for k in range(4097):
            a=-math.pi+2*math.pi*k/4096
            target=(math.cos(a),math.sin(a))
            for j,frac in enumerate((None,28)):
                actual=cordic(a,n,frac)
                errors[j]=max(errors[j],*(abs(x-y) for x,y in zip(actual,target)))
        rows.append(dict(iterations=n,fp64_rotation_max_abs_error=errors[0],fixed_w32_f28_max_abs_error=errors[1],angles=4097))
    assert rows[-1]['fp64_rotation_max_abs_error']<1e-8
    assert rows[3]['fixed_w32_f28_max_abs_error']<5e-5
    write_csv(root/'cordic_error.csv',rows)
    fig,ax=plt.subplots(figsize=(8,4.4))
    for key,label in (('fp64_rotation_max_abs_error','FP64 iteration arithmetic'),('fixed_w32_f28_max_abs_error','Signed W=32, F=28; arithmetic shifts')):
        ax.semilogy([r['iterations'] for r in rows],[r[key] for r in rows],'o-',label=label)
    ax.set(xlabel='Micro-rotation iterations',ylabel='Max absolute sin/cos error',title='CORDIC: iteration error and finite-word-length floor')
    ax.grid(True,which='both',alpha=.25);ax.legend(fontsize=9)
    fig.text(.01,-.02,'Algorithm simulation: 4097 angles; finite-N gain compensation; not RTL measurement.',fontsize=9)
    save(fig,root,'cordic_error')

    getcontext().prec=100
    recip=Decimal('.1');rsqrt=Decimal('.1');nr=[]
    for k in range(6):
        nr.append(dict(iteration=k,reciprocal_relative_error=str(abs(recip)),rsqrt_relative_error=str(abs(rsqrt))))
        recip=recip*recip
        rsqrt=-Decimal('1.5')*rsqrt*rsqrt-Decimal('.5')*rsqrt*rsqrt*rsqrt
    write_csv(root/'newton_error.csv',nr)
    fig,ax=plt.subplots(figsize=(8,4.4))
    for key,label in (('reciprocal_relative_error','Reciprocal: e(next) = e^2'),('rsqrt_relative_error','RSQRT: d(next) = -1.5 d^2 - 0.5 d^3')):
        ax.semilogy([r['iteration'] for r in nr],[float(r[key]) for r in nr],'o-',label=label)
    ax.axhline(2**-24,ls='--',color='#555555',label='FP32 unit roundoff (reference, not a universal error bound)')
    ax.set(xlabel='Newton updates',ylabel='Absolute relative error',title='Ideal Newton convergence from 10% initial error',ylim=(1e-34,.4))
    ax.grid(True,which='both',alpha=.25);ax.legend(fontsize=8)
    fig.text(.01,-.02,'100-digit algebraic recurrence; excludes rounding, seed generation and hardware latency.',fontsize=9)
    save(fig,root,'newton_error')

    clipping=[]
    for length in (128,1024,32768):
        for t in (8,12,16,20,24):
            delta=(length-1)*math.exp(-t)
            clipping.append(dict(length=length,threshold=t,tail_weight_bound=delta,removed_probability_mass_bound=delta/(1+delta),softmax_l1_bound=2*delta/(1+delta)))
    write_csv(root/'softmax_tail_bound.csv',clipping)
    fig,ax=plt.subplots(figsize=(8,4.4))
    for length in (128,1024,32768):
        selected=[r for r in clipping if r['length']==length]
        ax.semilogy([r['threshold'] for r in selected],[r['removed_probability_mass_bound'] for r in selected],'o-',label=f'N = {length:,}')
    ax.set(xlabel='Drop logits below max - T',ylabel='Upper bound on removed probability mass',title='Softmax tail clipping: the length-dependent worst case')
    ax.grid(True,which='both',alpha=.25);ax.legend()
    fig.text(.01,-.02,'Analytical upper bound with at least one max term = 1; not observed model accuracy.',fontsize=9)
    save(fig,root,'softmax_tail_bound')

    meta=dict(schema='transformer_npu.complex_math_materials.v1',scope='standalone mathematical illustrations; no hardware timing or model acceptance claims',cordic=dict(samples=4097,word_bits=32,fraction_bits=28,gain='finite-iteration compensated',shift='Python signed arithmetic right shift',angle_rounding='nearest even',coordinate_overflow='assert signed32 range'),newton=dict(decimal_precision=100,initial_relative_error='0.1',rounding='none'),softmax=dict(bound='delta/(1+delta), delta=(N-1)exp(-T)',empirical=False))
    (root/'experiment_manifest.json').write_text(json.dumps(meta,indent=2)+'\n')
    print(json.dumps(dict(cordic=rows,newton=nr,softmax_32k=[r for r in clipping if r['length']==32768]),indent=2))

if __name__=='__main__':main()
