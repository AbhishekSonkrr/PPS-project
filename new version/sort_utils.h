#ifndef SELECTIONSORT_UTILS_H
#define SELECTIONSORT_UTILS_H

#include <stddef.h>   // for size_t
#include <time.h>     // for struct timespec

// Swap two integers
static inline void swap_int(int *a, int *b);

// Selection sort
void selectionSort(int arr[], int n);

// Print array
void printArray(int arr[], int n);

// Time average sort duration in nanoseconds
long long timed_avg_ns(void (*sortfn)(int[], int), int src[], int n, int reps);

#endif // SELECTIONSORT_UTILS_H