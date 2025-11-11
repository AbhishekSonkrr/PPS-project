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

This creates executables: `shellSort`, `selectionSort`, `heapsort`, `quickSort`, `bubbleSort`, `straightInsertionSort` in the build directory (or in-place when using the provided Makefile).

Build with Make (simple)

```bash
make
```

Notes for CLion on Arch Linux (KDE Plasma)
- Install toolchain: `sudo pacman -Syu base-devel gcc gdb cmake ninja`
- Install CLion (JetBrains Toolbox or AUR package)
- Open this folder in CLion — it will detect `CMakeLists.txt` and configure the project.

How the unified main works
- `include/sort_main.h` provides a common `main()` which expects each sorter source to `#define SORT_FUNC <name>` before including the header. This keeps all mains consistent and avoids duplication.
