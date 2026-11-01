#!/usr/bin/env python3
"""Build the self-contained HTML reading version using Pandoc."""
from pathlib import Path
import subprocess

root = Path(__file__).resolve().parents[1]
source = root / "Agent框架_Flow与智能体团队_调研报告.md"
output = root / "Agent框架_Flow与智能体团队_阅读版.html"
subprocess.run([
    "pandoc", str(source), "--from=markdown", "--to=html5",
    "--standalone", "--embed-resources",
    "--css", str(root / "assets" / "report.css"),
    "--metadata=lang:zh-CN",
    "--metadata=pagetitle:Agent 框架设计调研：Flow、图工作流与智能体团队",
    "--resource-path", str(root),
    "--output", str(output),
], check=True, cwd=root)
print(output.name)

