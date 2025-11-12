#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$ROOT/build"

echo "Building project (CMake)..."
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake ..
cmake --build . -j$(nproc)

EXECUTABLES=(shellSort selectionSort heapsort quickSort bubbleSort straightInsertionSort)

check_sorted() {
  # input: line with numbers separated by spaces
  awk 'BEGIN{ok=1}{for(i=2;i<=NF;i++){if($i < $(i-1)){ok=0;break}}}END{if(ok) print "PASS"; else print "FAIL"}'
}

cd "$BUILD_DIR"

for exe in "${EXECUTABLES[@]}"; do
  if [[ -x "${BUILD_DIR}/${exe}" ]]; then
    echo "\n=== Running ${exe} ==="
    out="$(${BUILD_DIR}/${exe})"
    echo "$out"

    # extract Sorted Ordered Array line and check
    ord_line=$(printf "%s\n" "$out" | sed -n 's/^Sorted Ordered Array:\s*//p' | tr -d '\r')
    rev_line=$(printf "%s\n" "$out" | sed -n 's/^Sorted Reverse Array:\s*//p' | tr -d '\r')
    rand_line=$(printf "%s\n" "$out" | sed -n 's/^Sorted Random Array:\s*//p' | tr -d '\r')

    if [[ -n "$ord_line" ]]; then
      echo -n "Ordered: "
      printf "%s\n" "$ord_line" | check_sorted
    fi
    if [[ -n "$rev_line" ]]; then
      echo -n "Reverse: "
      printf "%s\n" "$rev_line" | check_sorted
    fi
    if [[ -n "$rand_line" ]]; then
      echo -n "Random: "
      printf "%s\n" "$rand_line" | check_sorted
    fi
  else
    echo "Executable ${exe} not found in ${BUILD_DIR}, skipping."
  fi
done

echo "\nDone."
