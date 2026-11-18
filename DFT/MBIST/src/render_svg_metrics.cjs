'use strict';
// Render local SVGs and measure the nontransparent pixels of individual texts.
const fs = require('fs');
const sharp = require('sharp');
(async () => {
  const input = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
  const results = [];
  for (const job of input) {
    const { info } = await sharp(Buffer.from(job.svg)).trim().png().toBuffer({ resolveWithObject: true });
    results.push({ id: job.id, box: [-info.trimOffsetLeft, -info.trimOffsetTop + job.originY, info.width, info.height] });
  }
  fs.writeFileSync(process.argv[3], JSON.stringify(results));
  if (process.argv[4]) {
    const jobs = JSON.parse(fs.readFileSync(process.argv[4], 'utf8'));
    for (const job of jobs) await sharp(job.source).png().toFile(job.destination);
  }
})().catch(error => { console.error(String(error)); process.exit(1); });
