'use strict';
// Prefer a project-local npm installation; also support an existing global installation.
const path = require('path');
const { createRequire } = require('module');
let load = require;
try { require.resolve('mathjax-full/js/mathjax.js'); }
catch (_) {
  try {
    const npmRoot = require('child_process').execSync('npm root -g', { encoding: 'utf8' }).trim();
    load = createRequire(path.join(npmRoot, '_loader.js'));
    load.resolve('mathjax-full/js/mathjax.js');
  } catch (error) {
    throw new Error('MathJax unavailable. Install mathjax-full 3.x locally or globally. ' + error.message);
  }
}
const {mathjax} = load('mathjax-full/js/mathjax.js');
const {TeX} = load('mathjax-full/js/input/tex.js');
const {SVG} = load('mathjax-full/js/output/svg.js');
const {liteAdaptor} = load('mathjax-full/js/adaptors/liteAdaptor.js');
const {RegisterHTMLHandler} = load('mathjax-full/js/handlers/html.js');
const {AllPackages} = load('mathjax-full/js/input/tex/AllPackages.js');
const adaptor = liteAdaptor();
RegisterHTMLHandler(adaptor);
const doc = mathjax.document('', {InputJax: new TeX({packages: AllPackages}), OutputJax: new SVG({fontCache: 'none'})});
module.exports = {
  version: load('mathjax-full/package.json').version,
  convert: (item) => {
    const html = adaptor.outerHTML(doc.convert(item.tex, {display: item.display}));
    if (html.includes('data-mjx-error') || html.includes('data-mml-node="merror"'))
      throw new Error(html);
    return html;
  }
};
