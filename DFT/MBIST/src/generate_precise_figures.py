#!/usr/bin/env python3
"""Generate native editable SVGs with exact connection ports. No dependencies.

    python src/generate_precise_figures.py
    python src/generate_precise_figures.py --family march
    python src/validate_precise_figures.py --png

Edit precise_march.py / precise_systems.py and rerun validation after every edit.
"""
from pathlib import Path
import json,argparse
from svg_geometry import SIZES,FONT
from precise_march import BUILDERS as MARCH
from precise_systems import BUILDERS as SYSTEMS
ROOT=Path(__file__).resolve().parents[1]

def generate(family='all',out=None,data_path=None):
    result=[]
    data=json.loads((data_path or ROOT/'examples/results.json').read_text(encoding='utf-8'))
    for kind,builders in [('march',MARCH),('systems',SYSTEMS)]:
        if family not in ('all',kind):continue
        dest=out or ROOT/'assets'/kind;dest.mkdir(parents=True,exist_ok=True)
        rows=[]
        for fn in builders:
            fig=fn() if kind=='march' else fn(data)
            rows.append(fig.save(dest/(fig.stem+'.svg')))
            print(f'{kind}/{fig.stem}.svg: {len(fig.edges)} connections')
        (dest/'figures_manifest.json').write_text(json.dumps({'font_family':FONT,'font_sizes_px':SIZES,'figures':rows},ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
        result.extend([{'family':kind,**r} for r in rows])
    return result

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--family',choices=['all','march','systems'],default='all')
    p.add_argument('--out-dir',type=Path);p.add_argument('--data',type=Path);a=p.parse_args()
    if a.out_dir and a.family=='all':p.error('--out-dir requires a specific family')
    generate(a.family,a.out_dir,a.data)
if __name__=='__main__':main()
