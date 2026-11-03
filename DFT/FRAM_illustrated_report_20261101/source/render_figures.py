"""Render final SVG files to high-resolution PNG; requires Inkscape."""
from pathlib import Path
import os, subprocess, sys, concurrent.futures, time
from diagram_common import ROOT
def main():
    svgdir=ROOT/"figures"/"svg"
    pngdir=ROOT/"figures"/"png";pngdir.mkdir(parents=True,exist_ok=True)
    qc=ROOT.parent/".fram_render_qc";qc.mkdir(exist_ok=True)
    conf=qc/"fonts.conf"
    from html import escape
    conf.write_text('<?xml version="1.0"?><!DOCTYPE fontconfig SYSTEM "fonts.dtd"><fontconfig><include ignore_missing="yes">/etc/fonts/fonts.conf</include><dir>'+escape(str(ROOT/"assets"/"fonts"))+'</dir><cachedir>'+escape(str(qc/"fontcache"))+'</cachedir></fontconfig>')
    env=dict(os.environ,FONTCONFIG_FILE=str(conf))
    names=sys.argv[1:]
    paths=[svgdir/n for n in names] if names else sorted(svgdir.glob("*.svg"))
    def render(p):
        out=pngdir/(p.stem+".png")
        temporary=pngdir/(".render_"+p.stem+".png")
        command=["inkscape",str(p),"--batch-process","--export-type=png","--export-width=2800","--export-filename="+str(temporary)]
        r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
        if r.returncode or not temporary.exists():raise RuntimeError(p.name+": "+r.stderr)
        png_end=bytes.fromhex("0000000049454e44ae426082")
        for attempt in range(50):
            if temporary.read_bytes().endswith(png_end):break
            time.sleep(0.1)
        else:raise RuntimeError("Incomplete PNG: "+p.name)
        temporary.replace(out)
        return out.name
    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as ex:
        for name in ex.map(render,paths):print(name)
if __name__=="__main__":main()

