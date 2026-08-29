#!/usr/bin/env python3
"""Render a PPTX to PDF/PNG, create a contact sheet, and collect proofing artifacts."""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path


def require(command: str) -> str:
    path = shutil.which(command)
    if not path:
        raise SystemExit(f"required command not found: {command}")
    return path


def parse_pages(value: str) -> list[int]:
    pages: set[int] = set()
    if not value.strip():
        return []
    for part in value.split(","):
        part = part.strip()
        if not part:
            continue
        match = re.fullmatch(r"(\d+)(?:-(\d+))?", part)
        if not match:
            raise argparse.ArgumentTypeError(f"invalid page selection: {part}")
        start = int(match.group(1))
        end = int(match.group(2) or start)
        if start < 1 or end < start:
            raise argparse.ArgumentTypeError(f"invalid page range: {part}")
        pages.update(range(start, end + 1))
    return sorted(pages)


def run(command: list[str], *, env: dict[str, str] | None = None) -> None:
    subprocess.run(command, check=True, env=env)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pptx", type=Path)
    parser.add_argument("--out-dir", type=Path)
    parser.add_argument("--overview-dpi", type=int, default=96)
    parser.add_argument("--detail-dpi", type=int, default=160)
    parser.add_argument("--detail-pages", default="")
    args = parser.parse_args()

    pptx = args.pptx.expanduser().resolve()
    if not pptx.is_file() or pptx.suffix.lower() != ".pptx":
        raise SystemExit(f"PPTX not found: {pptx}")

    soffice = require("soffice")
    pdftoppm = require("pdftoppm")
    montage = require("montage")
    unzip = require("unzip")
    pdftotext = shutil.which("pdftotext")
    pdfinfo = shutil.which("pdfinfo")

    if args.out_dir:
        out_dir = args.out_dir.expanduser().resolve()
        out_dir.mkdir(parents=True, exist_ok=True)
    else:
        out_dir = Path(tempfile.mkdtemp(prefix=f"{pptx.stem}-proof-"))

    detail_pages = parse_pages(args.detail_pages)
    with tempfile.TemporaryDirectory(prefix="lo-proof-profile-") as profile:
        env = os.environ.copy()
        env["SAL_USE_VCLPLUGIN"] = "svp"
        run(
            [
                soffice,
                f"-env:UserInstallation=file://{profile}",
                "--headless",
                "--convert-to",
                "pdf",
                "--outdir",
                str(out_dir),
                str(pptx),
            ],
            env=env,
        )

    pdf = out_dir / f"{pptx.stem}.pdf"
    if not pdf.is_file():
        raise SystemExit(f"PDF export missing: {pdf}")

    structure = subprocess.run(
        [unzip, "-t", str(pptx)], check=True, text=True, capture_output=True
    )
    (out_dir / "pptx-structure.txt").write_text(
        structure.stdout + structure.stderr, encoding="utf-8"
    )
    overview_prefix = out_dir / "slide"
    run(
        [
            pdftoppm,
            "-png",
            "-r",
            str(args.overview_dpi),
            str(pdf),
            str(overview_prefix),
        ]
    )
    overview_pages = sorted(out_dir.glob("slide-*.png"))
    if not overview_pages:
        raise SystemExit("overview PNG export produced no pages")

    run(
        [
            montage,
            *map(str, overview_pages),
            "-thumbnail",
            "480x270",
            "-tile",
            "3x",
            "-geometry",
            "+10+20",
            str(out_dir / "contact-sheet.png"),
        ]
    )

    for page in detail_pages:
        run(
            [
                pdftoppm,
                "-f",
                str(page),
                "-l",
                str(page),
                "-singlefile",
                "-png",
                "-r",
                str(args.detail_dpi),
                str(pdf),
                str(out_dir / f"detail-{page:02d}"),
            ]
        )

    if pdftotext:
        run([pdftotext, "-layout", str(pdf), str(out_dir / "slides.txt")])
    if pdfinfo:
        result = subprocess.run(
            [pdfinfo, str(pdf)], check=True, text=True, capture_output=True
        )
        (out_dir / "pdfinfo.txt").write_text(result.stdout, encoding="utf-8")

    print(f"proof directory: {out_dir}")
    print(f"pdf: {pdf}")
    print(f"contact sheet: {out_dir / 'contact-sheet.png'}")
    if detail_pages:
        print("detail pages: " + ", ".join(map(str, detail_pages)))


if __name__ == "__main__":
    main()
