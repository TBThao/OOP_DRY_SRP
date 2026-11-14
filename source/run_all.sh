#!/usr/bin/env bash
# Biên dịch và chạy toàn bộ ví dụ. Cần g++ hỗ trợ C++17.
# Cách dùng:  ./run_all.sh
set -e
cd "$(dirname "$0")"
BIN="$(mktemp -d)"
for dir in $(find . -name '*.cpp' -printf '%h\n' | sort -u); do
  echo "=============================================================="
  echo "== $dir"
  echo "=============================================================="
  g++ -std=c++17 -Wall -Wextra -I"$dir" "$dir"/*.cpp -o "$BIN/prog"
  "$BIN/prog"
  echo
done
