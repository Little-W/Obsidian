#!/usr/bin/env python3
"""Render research SVGs and check exact connector geometry and text ink bounds.

Uses Sharp/libvips for rasterization. Text extents describe rendered ink pixels;
the geometric checks use the same named ports as the editable SVG source.
"""
from copy import deepcopy
import json
from pathlib import Path
import subprocess
import tempfile
import xml.etree.ElementTree as ET
from validate_precise_figures import validate

ROOT=Path(__file__).resolve().parents[1]
NS='{http://www.w3.org/2000/svg}'
ET.register_namespace('',NS[1:-1])


def dataset(element):
    def camel(key):
        parts=key[5:].split('-')
        return parts[0]+''.join(x.title() for x in parts[1:])
    return {camel(k):v for k,v in element.attrib.items() if k.startswith('data-')}


def main():
    jobs,figures,pngs=[],[],[]
    for path in sorted((ROOT/'assets/research').glob('*.svg')):
        root=ET.parse(path).getroot()
        w,h=map(float,root.attrib['viewBox'].split()[2:])
        figure={'file':str(path.relative_to(ROOT)),'width':w,'height':h,
                'texts':[],'rects':[],'connectors':[],'rules':[],'junctions':[]}
        for elem in root.iter():
            kind=elem.get('data-kind')
            if elem.tag==NS+'text':
                isolated=ET.Element(NS+'svg',root.attrib)
                isolated.append(deepcopy(elem))
                origin_y=float(elem.get('y'))-80
                isolated.set('height','160')
                isolated.set('viewBox',f'0 {origin_y} {w} 160')
                uid=path.stem+'::'+elem.attrib['id']
                jobs.append({'id':uid,'originY':origin_y,'svg':ET.tostring(isolated,encoding='unicode')})
                figure['texts'].append({'id':uid,'text':''.join(elem.itertext()),'size':float(elem.get('font-size')),
                                       'owner':elem.get('data-owner'),'padding':float(elem.get('data-padding','12'))})
            if elem.tag==NS+'rect' and kind:
                figure['rects'].append({'id':elem.attrib['id'],'box':[float(elem.get(k,'0')) for k in ('x','y','width','height')],
                                       'kind':kind,'stroke':elem.get('stroke','none'),'stroke_width':float(elem.get('stroke-width','0'))})
            if elem.tag==NS+'polyline':
                points=[tuple(map(float,x.split(','))) for x in elem.attrib['points'].split()]
                line={'id':elem.attrib['id'],'points':points,'width':float(elem.get('stroke-width','0'))}
                if kind=='connector':
                    line.update(arrow=bool(elem.get('marker-end')),data=dataset(elem))
                    figure['connectors'].append(line)
                else:
                    figure['rules'].append(line)
            if kind=='junction':
                figure['junctions'].append({'id':elem.attrib['id'],'x':float(elem.get('cx')),'y':float(elem.get('cy'))})
        figures.append(figure)
        dest=path.parent/'png'/(path.stem+'.png');dest.parent.mkdir(exist_ok=True)
        pngs.append({'source':str(path),'destination':str(dest)})
    with tempfile.TemporaryDirectory(prefix='mbist_svg_') as tmp:
        tmp=Path(tmp)
        (tmp/'jobs.json').write_text(json.dumps(jobs),encoding='utf-8')
        (tmp/'pngs.json').write_text(json.dumps(pngs),encoding='utf-8')
        subprocess.run(['node',str(ROOT/'src/render_svg_metrics.cjs'),str(tmp/'jobs.json'),str(tmp/'boxes.json'),str(tmp/'pngs.json')],check=True)
        measured={item['id']:item['box'] for item in json.loads((tmp/'boxes.json').read_text())}
    reports=[]
    for figure in figures:
        for text in figure['texts']:
            text['box']=measured[text['id']]
        issues=validate(figure)
        reports.append({'file':figure['file'],'texts':len(figure['texts']),'connectors':len(figure['connectors']),'issues':issues})
    report={'renderer':'Sharp/libvips','measurement':'Rasterized text ink bounds; SVG named-port and segment checks',
            'figures':len(figures),'text_count':len(jobs),'passed':all(not r['issues'] for r in reports),'results':reports}
    (ROOT/'checks/research_figure_validation.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(report,ensure_ascii=False,indent=2))
    if not report['passed']:
        raise SystemExit(1)


if __name__=='__main__':
    main()
