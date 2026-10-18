'use strict';
// Render JSON [{tex, display}, ...] to standalone mathematical SVG fragments.
const fs = require('fs');
const mj = require('./mathjax_common.js');
if (process.argv.length !== 4) {
  console.error('Usage: node src/render_math.js input.json output.json'); process.exit(2);
}
const expressions = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const result = expressions.map(item => ({...item, html: mj.convert(item)}));
fs.writeFileSync(process.argv[3], JSON.stringify(result));
console.log(`Rendered ${result.length} mathematical expressions with MathJax ${mj.version}.`);
