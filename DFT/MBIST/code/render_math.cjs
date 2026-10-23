// Convert supplied TeX to self-contained SVG; the output HTML needs no MathJax runtime.
// Rebuilding requires: npm install mathjax-full
const fs = require('fs');
const {mathjax} = require('mathjax-full/js/mathjax.js');
const {TeX} = require('mathjax-full/js/input/tex.js');
const {SVG} = require('mathjax-full/js/output/svg.js');
const {liteAdaptor} = require('mathjax-full/js/adaptors/liteAdaptor.js');
const {RegisterHTMLHandler} = require('mathjax-full/js/handlers/html.js');
const {AllPackages} = require('mathjax-full/js/input/tex/AllPackages.js');
const adaptor = liteAdaptor();
RegisterHTMLHandler(adaptor);
const doc = mathjax.document('', {
  InputJax: new TeX({packages: AllPackages}),
  OutputJax: new SVG({fontCache: 'none'})
});
if(process.argv.length!==4) throw new Error('Usage: node render_math.cjs input.json output.json');
const items=JSON.parse(fs.readFileSync(process.argv[2],'utf8'));
const result=items.map(item=>{
  const node=doc.convert(item.tex,{display:item.display,em:16,ex:8,containerWidth:1000});
  return {id:item.id,svg:adaptor.outerHTML(node)};
});
fs.writeFileSync(process.argv[3],JSON.stringify(result));
