"""Re-render the four quoted source figures from the user's original PDFs.
Usage: python extract_paper_figures.py --papers /path/to/EDA-Agent
Requires PyMuPDF. No modifications to the original figure contents.
"""
import argparse,hashlib,json
from pathlib import Path
import fitz
p=argparse.ArgumentParser();p.add_argument('--papers',required=True);a=p.parse_args()
root=Path(a.papers);out=Path(__file__).resolve().parents[1]/'sources';out.mkdir(exist_ok=True)
jobs=[
('S1_DFTAgent_Fig1','LLM Agents as Catalysts*',6,'Figure 1',[166,65,560,350]),
('S2_EDAid_Fig4','Divergent Thoughts*',4,'Figure 4',[70,70,526,258]),
('S3_ChipMEM_Fig2','ChipMEM*',3,'Figure 2',[106,64,506,310]),
('S4_AgentSPEX_Fig1','AgentSPEX*',2,'Figure 1',[107,78,505,257]),
]
provenance=[]
for name,pattern,page,label,rect in jobs:
 files=list(root.rglob(pattern+'.pdf'))
 if len(files)!=1:raise ValueError((pattern,files))
 path=files[0];doc=fitz.open(path)
 img=doc[page-1].get_pixmap(matrix=fitz.Matrix(3,3),clip=fitz.Rect(rect),alpha=False)
 img.save(out/(name+'.png'))
 provenance.append({'figure':name,'source_pdf':str(path.relative_to(root)),'source_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'pdf_page':page,'original_figure':label,'clip_pdf_points':rect,'scale':3,'method':'Direct PDF rendering; original labels retained; no diagram redrawing'})
(out/'figure_provenance.json').write_text(json.dumps(provenance,ensure_ascii=False,indent=2))
print('Rendered',len(provenance),'source figures')
