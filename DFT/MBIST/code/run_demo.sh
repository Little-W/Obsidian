#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
mkdir -p "$ROOT/build" "$ROOT/results"
${CXX:-g++} -std=c++17 -O2 -Wall -Wextra -pedantic \
  "$ROOT/code/mbist_demo.cpp" -o "$ROOT/build/mbist_demo"
"$ROOT/build/mbist_demo" "$ROOT/data/memories.csv" "$ROOT/results" \
  3 10 300 20 2 | tee "$ROOT/results/comparison.csv"
