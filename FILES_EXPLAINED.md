# Project files — simple explanation (Hindi + English)

Ye file chhoti aur seedhi bhaasha mein batati hai ki har file kya karti hai. Agar kuch samajh na aaye to batao, main aur simple kar dunga.

---

## Top-level (important)

- `CMakeLists.txt`  
  Kaam: Project ko CMake se build karne ki instructions. Kaunse programs banenge (targets) aur kaunse source files use hongi.

- `Makefile`  
  Kaam: Simple `make` command se binaries banane ka tarika. Agar tum CMake use nahi karna chahte to `make` se easily build kar sakte ho.

- `run_all.sh`  
  Kaam: (Removed) Previously a helper script that built the project and ran smoke tests.

- `README.md`  
  Kaam: Project ka short guide — kaise build/run karein, aur `sort_main.h` ka use kaise hota hai.

---

## Shared header

- `include/sort_main.h`  
  Kaam: Ek common `main()` aur helper functions provide karta hai. Har sorter file isko include karke `SORT_FUNC` define karti hai. Isse har program same way se test hota hai.

---

## Source files (`src/`) — short aur seedha

Har `src/*.c` file ek sorting algorithm implement karti hai. Har file `#define SORT_FUNC <function-name>` kar ke `sort_main.h` include karti hai.

- `src/bubbleSort.c` — Bubble sort implementation.
- `src/heapsort.c` — Heap sort implementation.
- `src/quickSort.c` — Quick sort implementation.
- `src/selectionSort.c` — Selection sort implementation.
- `src/shellSort.c` — Shell sort implementation.
- `src/straightInsertionSort.c` — Insertion sort (correctly named).

Note: Pehle ek misspelled file `straightInstertionSort.c` thi — usko archive mein move kar diya gaya hai. Ab `src/` mein sirf correct file hai.

---

## Archive aur extra files

- `archive/`  
  Kaam: Purani/backup copies rakhe hue files. Agar tum changes wapas lana chaho to yahan se dekh sakte ho.

- `patter-not-in-project.c`  
  Kaam: Ek extra/test file — build mein include nahi hota.

- `compile_commands.json`  
  Kaam: Editor/tools ke liye CMake ne generate kiya hua compile database. Editor (jaise clangd) use karta hai.

---

## Build folders / generated cheezein

- `build/`, `cmake-build-debug/`  
  Kaam: Ye folders build ke time bante hain (object files, executables). Safe hai delete karna; phir se `cmake` run karoge to wapas aa jayenge.

- Top-level binaries (jaise `bubbleSort`, `heapsort`)  
  Kaam: Ye compiled programs hain. Normally git mein include nahi karna chahiye — `.gitignore` mein add kar do.

- `.idea/`, `.vscode/`  
  Kaam: IDE settings — team policy ke hisaab se commit karna ya ignore karna.

---

## Har executable kya karta hai (bole toh)

1. Ek ordered array, ek reverse array, aur ek random array banata hai.
2. Originals print karta hai.
3. Corresponding sorting function call karta hai.
4. Sorted arrays print karta hai.
5. Thoda time measure karke average run-time print karta hai (simple timing harness from `sort_main.h`).

---

## Jaldi se build & run karne ke commands (copy-paste karein)

CMake (recommended):

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -j$(nproc)
cd ..
```

Make (agar `make` use karte ho):

```bash
make clean
make -j$(nproc)
```

Run smoke tests (build karega aur sab executables chalake check karega):

```bash
./run_all.sh
```

---

## Simple suggestions (jo main kar sakta hoon)

- `.gitignore` add kar doon (build folders, binaries, compile_commands.json).
- GitHub Actions add kar doon jo `./run_all.sh` chalaye on push — taaki auto-check ho jaye.
- `archive/` agar nahi chahiye toh main hata doon.

