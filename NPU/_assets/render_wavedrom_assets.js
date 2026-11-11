#!/usr/bin/env node
/* Export the WaveJSON stored in draw.io WaveDrom cells with the official
 * wavedrom/wavedrom command-line renderer.  This file performs extraction and
 * process orchestration only; it does not implement waveform drawing.
 */

'use strict';

const fs = require('fs');
const os = require('os');
const path = require('path');
const childProcess = require('child_process');

const officialRoot = process.env.WAVEDROM_ROOT || '/media/6/Agent_tools/wavedrom';
const officialCli = path.join(officialRoot, 'bin', 'cli.js');

if (!fs.existsSync(officialCli)) {
  throw new Error(
    `official WaveDrom CLI not found: ${officialCli}\n` +
    'clone https://github.com/wavedrom/wavedrom.git and set WAVEDROM_ROOT'
  );
}

function decodeXml(value) {
  return value
    .replace(/&quot;/g, '"')
    .replace(/&apos;/g, "'")
    .replace(/&lt;/g, '<')
    .replace(/&gt;/g, '>')
    .replace(/&amp;/g, '&');
}

function extractWaveJson(xml) {
  const cell = xml.match(/<mxCell[^>]*value="([^"]*)"[^>]*style="[^"]*mxgraph\.wavedrom\.abstract\.timing[^"]*"[^>]*>/);
  if (!cell) {
    throw new Error('WaveDrom custom cell not found');
  }
  return JSON.parse(decodeXml(cell[1]));
}

function renderOne(sourcePath) {
  const xml = fs.readFileSync(sourcePath, 'utf8');
  const source = extractWaveJson(xml);
  const tempRoot = fs.mkdtempSync(path.join(os.tmpdir(), 'npu-wavedrom-'));
  const waveJsonPath = path.join(tempRoot, `${path.basename(sourcePath, '.drawio')}.json5`);
  try {
    fs.writeFileSync(waveJsonPath, JSON.stringify(source, null, 2));
    const result = childProcess.spawnSync(
      process.execPath,
      [officialCli, '--input', waveJsonPath, '--indent', '2'],
      { encoding: 'utf8', cwd: officialRoot }
    );
    if (result.status !== 0) {
      throw new Error(`official WaveDrom CLI failed for ${sourcePath}:\n${result.stderr}`);
    }
    if (!result.stdout.startsWith('<svg')) {
      throw new Error(`official WaveDrom CLI did not return SVG for ${sourcePath}`);
    }
    const root = result.stdout.match(/^<svg\b[^>]*\bwidth="([0-9.]+)"[^>]*\bviewBox="0 0 ([0-9.]+) ([0-9.]+)"[^>]*>/);
    if (!root) {
      throw new Error(`official WaveDrom SVG root is not recognized for ${sourcePath}`);
    }
    const width = Number(root[1]);
    const viewWidth = Number(root[2]);
    const viewHeight = Number(root[3]);
    const horizontalPadding = 80;
    const paddedRoot = root[0]
      .replace(`width="${root[1]}"`, `width="${width + 2 * horizontalPadding}"`)
      .replace(
        `viewBox="0 0 ${root[2]} ${root[3]}"`,
        `viewBox="-${horizontalPadding} 0 ${viewWidth + 2 * horizontalPadding} ${viewHeight}"`
      );
    const svg = `${result.stdout.replace(root[0], paddedRoot).trimEnd()}\n`;
    fs.writeFileSync(sourcePath.replace(/\.drawio$/, '.svg'), svg);
  } finally {
    fs.rmSync(tempRoot, { recursive: true, force: true });
  }
}

const sources = process.argv.slice(2);
if (sources.length === 0) {
  throw new Error('usage: render_wavedrom_assets.js <file.drawio> [...]');
}
for (const sourcePath of sources) {
  renderOne(sourcePath);
}
