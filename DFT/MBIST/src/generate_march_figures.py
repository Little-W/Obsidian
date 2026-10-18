#!/usr/bin/env python3
"""Compatibility entry point for the precise march diagrams.
The old freehand-coordinate generator has been replaced, not retained as default.
"""
import argparse,subprocess,sys
from pathlib import Path
from generate_precise_figures import generate,ROOT

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--out-dir',type=Path);p.add_argument('--data',type=Path)
    p.add_argument('--png',action='store_true');p.add_argument('--png-scale',type=float,default=1.5)
    a=p.parse_args()
    if a.png and a.out_dir:p.error('Use the default assets directory with --png, or render custom SVGs separately.')
    generate('march',a.out_dir,a.data)
    if a.png:subprocess.run([sys.executable,str(ROOT/'src/validate_precise_figures.py'),'--png','--png-scale',str(a.png_scale)],check=True)
if __name__=='__main__':main()
