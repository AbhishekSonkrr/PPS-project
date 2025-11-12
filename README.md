# PPS-project — Sorting implementations

This folder contains small C sorting algorithm implementations (shell, quick, heap, selection, bubble, insertion). The project is organized for both CLion (CMake) and simple Makefile-based builds.

Layout
- src/ — C source files for each sorting algorithm
- include/ — shared header `sort_main.h` that provides a common `main()` and helpers
- build/ — CMake build directory (generated)

Build with CMake (recommended for CLion)

```bash
mkdir -p build && cd build
cmake ..
cmake --build . -j$(nproc)
```

This creates executables in `build/` (or `build/bin/` depending on your generator): `shellSort`, `selectionSort`, `heapsort`, `quickSort`, `bubbleSort`, `straightInsertionSort`.

Build with Make (simple)

```bash
make
```

Notes for CLion on Arch Linux (KDE Plasma)
-- Install toolchain: `sudo pacman -Syu base-devel gcc gdb cmake ninja`
-- Install CLion (JetBrains Toolbox or AUR package)
-- Open this folder in CLion — it will detect `CMakeLists.txt` and configure the project.

Debugging in CLion (quick tips)

- After opening the project, select the executable target (e.g. `shellSort`) in the Run Configurations drop-down.
- Use the green Debug button to start a debug session. CLion uses your system `gdb` by default.
- To set breakpoints, click the gutter next to the source lines in an algorithm (for example `src/quickSort.c`).
- To examine variables, use the Variables pane or hover values while paused.

Automated run & verify script

I added a small helper script `run_all.sh` that:

- builds the project (CMake build directory),
- runs each sorter executable, and
- verifies that each printed "Sorted ... Array" lines are non-decreasing.

Run it from the repository root:

```bash
./run_all.sh
```

The script prints a per-executable PASS/FAIL summary. It's a quick smoke-test you can run after editing or benchmarking.

How the unified main works
- `include/sort_main.h` provides a common `main()` which expects each sorter source to `#define SORT_FUNC <name>` before including the header. This keeps all mains consistent and avoids duplication.

CI
-- A small GitHub Actions workflow runs the project's `run_all.sh` on push/PR to `main`. You can find it at `.github/workflows/ci.yml`.

Quick local commands

```bash
# configure + build
mkdir -p build && cd build
cmake .. && cmake --build .

# run the smoke tests from repository root
./run_all.sh
```

CLion / Arch notes (brief)
- Ensure `gcc`, `gdb`, `cmake` are installed (`sudo pacman -Syu base-devel gcc gdb cmake ninja`).
- In CLion's Settings -> Build, Execution, Deployment -> Toolchains, set the C compiler to `/usr/bin/gcc` and the debugger to `/usr/bin/gdb` if not auto-detected.
- Open the project root in CLion and wait for CMake configuration; use the upper-right target selector to run or debug any sorter executable.

Badge (CI)
- After you push this branch, you can add a CI status badge using the GitHub Actions workflow name `CI` and branch `main`.

If you'd like, I can add the CI badge to this README automatically after you push the commits to `origin/main`.

## Project organization updates

I reorganized source files to fix a misspelled filename and provide a clear layout under `src/`:

- Added `src/straightInsertionSort.c` (correct spelling) with the insertion sort implementation.
- Converted the old `src/straightInstertionSort.c` into a small wrapper that forwards to the corrected implementation to keep backwards compatibility.

All other algorithm implementations remain in `src/` and the build files were left intact — the top-level `CMakeLists.txt` already maps the misspelled name to the correct target (`straightInsertionSort`).

If you'd like, I can also remove the legacy `archive/` folder contents or update the Makefile to match the cleaned layout.
