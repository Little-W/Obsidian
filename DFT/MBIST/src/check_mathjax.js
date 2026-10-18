'use strict';
// Run validate_handbook.py first. This is TeX conversion, not an Obsidian UI test.
const fs = require('fs'), path = require('path');
const mj = require('./mathjax_common.js');
const root = path.resolve(__dirname, '..');
const expressions = JSON.parse(fs.readFileSync(path.join(root, 'checks/math_input.json'), 'utf8'));
const errors = [];
expressions.forEach((item, i) => { try { mj.convert(item); } catch (e) {errors.push({index: i, ...item, error: String(e)});} });
const result = {engine: 'MathJax full', version: mj.version, total: expressions.length,
  display: expressions.filter(x => x.display).length, inline: expressions.filter(x => !x.display).length,
  errors, passed: errors.length === 0, scope: 'Offline TeX-to-SVG conversion; not an Obsidian UI test.'};
fs.writeFileSync(path.join(root, 'checks/mathjax_validation.json'), JSON.stringify(result, null, 2) + '\n');
console.log(JSON.stringify(result, null, 2));
if (errors.length) process.exitCode = 1;
