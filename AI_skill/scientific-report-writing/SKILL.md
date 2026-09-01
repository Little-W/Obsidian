---
name: scientific-report-writing
description: Draft, revise, format, export, and audit Chinese scientific and technical reports and Word deliverables. Use for technical research, design, test, analysis, development, progress, or summary reports when report structure, formal Chinese, figures and tables, citations, DOCX styles, pagination, or PDF proofing matter; do not use for ordinary notes or journal-specific manuscripts unless the user asks to adapt these rules.
---

# Scientific Report Writing

Create a technically accurate report whose editable Word file and rendered PDF are both suitable for formal delivery.

## Authority order

Apply requirements in this order:

1. Follow the user's explicit content and format instructions.
2. Follow a supplied company, institute, funder, customer, or project template.
3. Follow the applicable current standard.
4. Use the baseline in [references/scientific-report-and-word-format.md](references/scientific-report-and-word-format.md).

Do not present a local font, margin, heading size, or line-spacing choice as a universal national requirement. Record which authority supplied an important format decision when that distinction affects review.

## Required reference

Read [references/scientific-report-and-word-format.md](references/scientific-report-and-word-format.md) completely before doing any of the following:

- drafting or substantially restructuring a scientific or technical report;
- creating or changing a Markdown-to-DOCX workflow or Word template;
- auditing headings, body text, lists, figures, tables, equations, citations, pagination, or blank pages;
- deciding whether the selected report type needs an abstract, test data, conclusions, or other report parts.

For a narrow sentence edit that cannot affect report structure or formatting, preserve the document's established conventions without loading unrelated material.

## Terminology and prohibited-word control

Before drafting or revising a report, inspect every user-supplied terminology, wording, and language-style constraint. When the local Chinese report baseline applies, read the prohibited-word rules in [references/scientific-report-and-word-format.md](references/scientific-report-and-word-format.md) and treat them as a mandatory content check, not an optional polishing pass.

- Apply the check to headings, body paragraphs, lists, table cells, figure labels, captions, and equation explanations.
- Rewrite each occurrence according to its technical meaning. Do not perform blind word substitution that changes a product term, measurement condition, or causal relation.
- Preserve exact names in bibliographic titles, standards, product commands, model identifiers, and indispensable quotations; record these source-controlled exceptions instead of silently changing them.
- Treat context-limited words separately: use them only in the explicitly permitted technical sense and rewrite vague abstract uses.
- Scan the Markdown source before export, then scan text extracted from the final DOCX and PDF. A clean source scan alone is insufficient because captions, fields, or converter output can reintroduce a prohibited expression.
- Report any unresolved occurrence and its reason. Do not declare the terminology audit complete while unexplained matches remain.

## Working method

1. Classify the report as research, design, test, analysis, development, progress, summary, or a user-defined hybrid. Do not turn a research report into a test record or invent data merely to complete a section.
2. Inspect the user's instructions, supplied template, terminology rules, sources, existing document, and required output files before drafting.
3. When the user edits a generated Word file and asks to sync it back, compare that DOCX with a fresh DOCX generated from the current Markdown, then apply only substantive content changes to the Markdown. Do not replace a structured Markdown source with a wholesale DOCX-to-Markdown conversion or import editor normalization as author edits.
4. Organize the report around the technical question. Keep sourced facts, calculations, measured results, engineering judgments, and recommendations distinguishable.
5. Prefer primary and authoritative sources. State conditions, scope, uncertainty, and limitations when they affect a claim.
6. Implement Word formatting with named styles and semantic document structure rather than manual spaces, repeated blank paragraphs, or appearance-only formatting.
7. Verify the actual DOCX, update fields when possible, render it to PDF, and inspect the rendered pages. A successful converter exit is not proof of a correct deliverable.

## Invariants

- Preserve the user's explicit choices, including requested omissions, unless they make the document unsafe or internally impossible.
- Never fabricate measurements, product specifications, bibliographic records, calculations, or conclusions.
- Treat user feedback, examples, and editing directions as instructions, not report content. Replace meta-writing such as “报告中应……” with the actual technical condition, operation, comparison rule, or result boundary unless document self-reference is genuinely required.
- Keep headings, cross-references, figures, tables, equations, citations, and the reference list mutually consistent.
- In editable Word deliverables, make sequential-number citation superscripts navigable: each visible citation number must link to its corresponding reference-list entry unless the governing template explicitly forbids hyperlinks. Preserve the required citation appearance and audit every link target.
- Treat displayed equations, body inline math, and table inline math as distinct format roles. Apply the governing template to each role; never force one global math font size merely because the body text has a single size.
- Treat the PDF rendering as evidence of pagination and layout quality.
- Reject blank pages, unexplained sparse pages, orphan headings, detached captions, unreadable tables, stale fields, broken superscripts, and inconsistent numbering.
- If an authoritative requirement cannot be established, label the choice as a project baseline or recommendation rather than attributing it to a standard.
