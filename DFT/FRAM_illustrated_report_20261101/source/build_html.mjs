/**
 * Build a self-contained static HTML report.
 * Dependencies: marked 17.0.5, mathjax-full 3.2.2.
 * All formulae are rendered to SVG during the build; no runtime JS/CDN is needed.
 */
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath,pathToFileURL} from 'node:url';
import {createRequire} from 'node:module';
const require=createRequire(import.meta.url);
const here=path.dirname(fileURLToPath(import.meta.url));
const root=path.dirname(here);
const runtimeModules=process.env.CODEX_PRIMARY_RUNTIME_NODE_MODULES;
const markedPath=runtimeModules ? path.join(runtimeModules,'marked/lib/marked.esm.js') : require.resolve('marked');
const {marked}=await import(pathToFileURL(markedPath));
const mjRoot=process.env.FRAM_MATHJAX_ROOT || path.dirname(require.resolve('mathjax-full/package.json'));
const {mathjax}=require(path.join(mjRoot,'js/mathjax.js'));
const {TeX}=require(path.join(mjRoot,'js/input/tex.js'));
const {SVG}=require(path.join(mjRoot,'js/output/svg.js'));
const {liteAdaptor}=require(path.join(mjRoot,'js/adaptors/liteAdaptor.js'));
const {RegisterHTMLHandler}=require(path.join(mjRoot,'js/handlers/html.js'));
require(path.join(mjRoot,'js/input/tex/ams/AmsConfiguration.js'));
require(path.join(mjRoot,'js/input/tex/newcommand/NewcommandConfiguration.js'));
const adaptor=liteAdaptor();RegisterHTMLHandler(adaptor);
const document=mathjax.document('',{
  InputJax:new TeX({packages:['base','ams','newcommand'],maxBuffer:20000}),
  OutputJax:new SVG({fontCache:'local'})
});
const mathErrors=[];let inlineMathCount=0,displayMathCount=0;
function renderMath(tex,display){
  const out=adaptor.outerHTML(document.convert(tex,{display,em:16,ex:8,containerWidth:1000}));
  if(out.includes('data-mjx-error')||out.includes('merror'))mathErrors.push(tex);
  if(display)displayMathCount++;else inlineMathCount++;
  return display?'<div class="math-display">'+out+'</div>':out;
}
marked.use({extensions:[
  {name:'mathBlock',level:'block',start(src){return src.indexOf('$$');},
   tokenizer(src){const m=/^\$\$[ \t]*\n([\s\S]*?)\n\$\$(?:\n|$)/.exec(src);if(m)return{type:'mathBlock',raw:m[0],tex:m[1]};},
   renderer(tok){return renderMath(tok.tex,true);}},
  {name:'mathInline',level:'inline',start(src){return src.indexOf('$');},
   tokenizer(src){const m=/^\$(?!\$)((?:\\.|[^$\\\n])+)\$/.exec(src);if(m)return{type:'mathInline',raw:m[0],tex:m[1]};},
   renderer(tok){return renderMath(tok.tex,false);}}
]});
const reportName='FRAM_特殊故障与测试算法调研_20261101.md';
const markdown=fs.readFileSync(path.join(root,reportName),'utf8');
const figureInfo=JSON.parse(fs.readFileSync(path.join(root,'source/figures.json'),'utf8'));
const referenceCount=[...markdown.matchAll(/^\[\d+\]: /gm)].length;
const chapterCount=[...markdown.matchAll(/^## \d+　/gm)].length;
let html=marked.parse(markdown);
let imageCount=0;
html=html.replace(/<img src="figures\/png\/([^"]+)\.png" alt="([^"]*)"[^>]*>/g,(_,stem,alt)=>{
  const file=path.join(root,'figures/svg',stem+'.svg');
  if(!fs.existsSync(file))throw new Error('Missing '+file);
  const encoded=fs.readFileSync(file).toString('base64');
  imageCount++;
  return '<figure id="'+stem+'"><img loading="eager" src="data:image/svg+xml;base64,'+encoded+'" alt="'+alt+'"></figure>';
});
const toc=[];let headingIndex=0;
html=html.replace(/<h([23])>([\s\S]*?)<\/h\1>/g,(all,level,content)=>{
  const plain=content.replace(/<[^>]+>/g,'').replace(/&amp;/g,'&');
  const id='section-'+(++headingIndex);
  if(level==='2')toc.push({id,text:plain});
  return '<h'+level+' id="'+id+'">'+content+'</h'+level+'>';
});
const bodyFont=fs.readFileSync(path.join(root,'assets/fonts/FRAMReportSans-Regular.woff')).toString('base64');
const navigation=toc.map(x=>'<a href="#'+x.id+'">'+x.text+'</a>').join('\n');
const style=`
@font-face{font-family:'FRAM Report Sans';font-style:normal;font-weight:400;src:url(data:font/woff;base64,${bodyFont}) format('woff')}
*{box-sizing:border-box}html{scroll-behavior:smooth}
body{margin:0;color:#20344b;background:#eef2f7;font-family:'FRAM Report Sans','Noto Sans CJK SC','Microsoft YaHei',sans-serif;font-size:17px;line-height:1.9}
aside{position:fixed;inset:0 auto 0 0;width:245px;overflow:auto;background:#142c47;color:#fff;padding:28px 20px}
aside strong{display:block;font-size:22px;letter-spacing:1px;margin-bottom:6px}
aside small{color:#bbcee5;display:block;line-height:1.7;margin-bottom:26px}
aside a{display:block;color:#dce6f3;text-decoration:none;font-size:14px;line-height:1.6;border-radius:6px;margin:4px 0;padding:7px 9px}
aside a:hover{background:#294966;color:#fff}
main{max-width:1190px;margin:30px 38px 60px 275px;background:#fff;padding:44px 52px 80px;border-radius:14px;box-shadow:0 10px 45px #23344b12}
h1{font-size:34px;line-height:1.5;color:#142c47;margin:0 0 24px}
h2{font-size:27px;line-height:1.6;border-bottom:2px solid #2366b0;padding-bottom:10px;margin:52px 0 24px;scroll-margin-top:24px}
h3{font-size:22px;line-height:1.6;color:#2366b0;margin:34px 0 15px;scroll-margin-top:24px}
p{margin:14px 0}a{color:#2366b0;text-decoration:none}a:hover{text-decoration:underline}
blockquote{margin:25px 0;padding:14px 22px;border-left:4px solid #2366b0;background:#edf4fc;border-radius:0 8px 8px 0;font-size:16px}
blockquote p{margin:7px 0}
figure{margin:28px -12px 12px;padding:0;break-inside:avoid}
figure img{display:block;width:100%;height:auto;border:1px solid #d6e1eb;border-radius:10px}
table{border-collapse:collapse;width:100%;font-size:15px;line-height:1.8;margin:24px 0}
th,td{border:1px solid #d7e0e9;padding:10px 13px;vertical-align:top}
th{background:#edf4fc;font-weight:700}tbody tr:nth-child(even){background:#fafbfd}
pre{padding:20px 22px;background:#142c47;color:#e7edf6;border-radius:9px;font-size:14px;line-height:1.7;overflow-x:auto;tab-size:4}
code{font-family:Consolas,'DejaVu Sans Mono',monospace;font-size:.91em}
p code,li code,td code{background:#eef3f8;padding:2px 5px;border-radius:4px;color:#365d81}
ul,ol{padding-left:26px}li{margin:5px 0}hr{border:0;border-top:1px solid #d8e1eb;margin:38px 0}
.math-display{overflow:auto;text-align:center;padding:12px 0}
mjx-container[jax="SVG"]{font-family:serif;max-width:100%}
mjx-container[jax="SVG"][display="true"]{display:block;text-align:center;margin:0.8em 0}
mjx-container[jax="SVG"]>svg{overflow:visible;vertical-align:middle}
mjx-container[jax="SVG"] text{font-family:'FRAM Report Sans',serif}
.notice{padding:14px 19px;margin:0 0 30px;background:#e9f6f3;border:1px solid #c8e2dc;border-radius:8px;color:#26615d;font-size:14px}
.footer{border-top:1px solid #d8e1eb;margin-top:40px;padding-top:20px;font-size:14px;color:#667a91}
@media(max-width:1100px){aside{display:none}main{margin:16px;padding:30px 28px}body{font-size:16px}h1{font-size:29px}figure{margin-left:0;margin-right:0}}
@media print{body{background:#fff;font-size:11pt}aside,.notice{display:none}main{margin:0;max-width:none;padding:0;box-shadow:none}h1{font-size:24pt}h2{font-size:18pt;break-after:avoid}h3{font-size:14pt;break-after:avoid}table{font-size:9pt}pre{white-space:pre-wrap;background:#f1f4f8;color:#172c45}figure{break-inside:avoid}a{color:inherit}.math-display{overflow:visible}}
`;
const out=`<!doctype html>
<html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>铁电存储器特殊故障与测试算法｜图文报告</title><style>${style}</style></head>
<body><aside><strong>FRAM 研究报告</strong><small>故障 · 建模 · 测试 · 研究方向<br>2026年11月1日<br>${chapterCount}章 / ${figureInfo.length}图 / ${referenceCount}条参考文献</small>${navigation}</aside>
<main><div class="notice">离线阅读版：正文、插图、中文字体与公式均已嵌入。完整压缩包另含 Markdown、可编辑 SVG、高清 PNG 与绘图源码。</div>${html}
<div class="footer">本阅读版根据随附 Markdown 生成。图中曲线与结构为定性示意；研究结论、适用条件与来源以正文为准。</div></main></body></html>`;
if(mathErrors.length)throw new Error('Formula errors: '+JSON.stringify(mathErrors));
if(imageCount!==figureInfo.length)throw new Error('Expected '+figureInfo.length+' images; found '+imageCount);
const outPath=path.join(root,'FRAM_图文报告_20261101.html');
fs.writeFileSync(outPath,out);
console.log(JSON.stringify({file:outPath,imageCount,displayMathCount,inlineMathCount,mathErrors,bytes:Buffer.byteLength(out)},null,2));

