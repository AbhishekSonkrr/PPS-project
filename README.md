# Sorting Algorithms Demo

This small project demonstrates several sorting algorithms implemented in separate files. It's meant to be easy to read and modify.

Files:
- `sorts.h` : shared header with prototypes and constants (`SIZE`, `MAX`).
- `main.c` : sample program that runs and times each sort.
- `bubble.c`, `heap.c`, `quick.c`, `selection.c`, `shell.c`, `insertion.c` : implementations.
- `utils.c` : `printArray` and `generate_random`.
- `Makefile` : build helper.

Build and run:
```
make
./sort_demo
```

Time complexity (brief):
- Bubble Sort: O(n^2) worst/average, O(n) best (if optimized), simple stable sort.
- Selection Sort: O(n^2) worst/average/best, does minimal swaps.
- Insertion Sort: O(n^2) worst, O(n) best, good for small/partially sorted arrays.
- Shell Sort: depends on gap sequence; generally between O(n) and O(n^2).
- Quick Sort: O(n log n) average, O(n^2) worst (rare with poor pivot choice).
- Heap Sort: O(n log n) worst and average, not stable.

You can change `SIZE` and `MAX` in `sorts.h` to experiment with different array sizes and ranges.
