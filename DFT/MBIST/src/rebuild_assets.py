#!/usr/bin/env python3
"""Recompute examples and regenerate exact-port SVG diagrams.
PNG and full geometric validation require Playwright + Chromium.
"""
from pathlib import Path
import argparse,subprocess,sys

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--png',action='store_true');p.add_argument('--check',action='store_true')
    p.add_argument('--browser',type=Path);p.add_argument('--png-scale',type=float,default=1.5);a=p.parse_args()
    src=Path(__file__).resolve().parent
    for name in ['teaching_examples.py','generate_precise_figures.py']:
        subprocess.run([sys.executable,str(src/name)],check=True)
    if a.png or a.check:
        cmd=[sys.executable,str(src/'validate_precise_figures.py')]
        if a.png:cmd+=['--png','--png-scale',str(a.png_scale)]
        if a.browser:cmd+=['--browser',str(a.browser)]
        subprocess.run(cmd,check=True)
if __name__=='__main__':main()
