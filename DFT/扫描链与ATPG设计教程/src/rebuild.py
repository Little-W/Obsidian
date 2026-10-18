#!/usr/bin/env python3
"""Regenerate this tutorial's examples, graphics, offline pages and check reports.
Run from any directory. Optional dependencies are documented in requirements-optional.txt.
Markdown files are kept as the editable source and are not overwritten.
"""
from pathlib import Path
import shutil,subprocess,sys
ROOT=Path(__file__).resolve().parents[1]
def main():
    steps=[['teaching_examples.py'],['generate_figures.py'],['validate_precise_figures.py','--png','--png-scale','1.5'],
           ['test_geometry_checks.py'],['build_drawing_review.py'],['validate_book.py']]
    for args in steps:subprocess.run([sys.executable,str(ROOT/'src'/args[0]),*args[1:]],check=True,cwd=ROOT)
    node=shutil.which('node')
    if not node:raise SystemExit('Install Node.js and mathjax-full 3.x to generate HTML and check formulas.')
    subprocess.run([node,str(ROOT/'src/check_mathjax.js')],check=True,cwd=ROOT)
    for script in ['render_html.py','check_html.py','check_review_interaction.py']:
        subprocess.run([sys.executable,str(ROOT/'src'/script)],check=True,cwd=ROOT)
    print('Finished. Inspect all figures visually after editing; automated checks do not certify circuit meaning.')
if __name__=='__main__':main()
