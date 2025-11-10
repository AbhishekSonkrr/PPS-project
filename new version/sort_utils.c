#include "sort_utils.h"
#include <stdio.h>
#include <string.h>

#define SIZE 11

static inline void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        int minVal = arr[i];
        for (int j = i + 1; j < n; ++j) {
            int v = arr[j];
            if (v < minVal) {
                minVal = v;
                minIndex = j;
            }
        }
        if (minIndex != i) {
            arr[minIndex] = arr[i];
            arr[i] = minVal;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
}

long long timed_avg_ns(void (*sortfn)(int[], int), int src[], int n, int reps) {
    int buf[SIZE];
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    for (int r = 0; r < reps; ++r) {
        memcpy(buf, src, n * sizeof buf[0]);
        sortfn(buf, n);
    }
    clock_gettime(CLOCK_MONOTONIC, &t2);
    long long total_ns = (long long)(t2.tv_sec - t1.tv_sec) * 1000000000LL
                       + (t2.tv_nsec - t1.tv_nsec);
    return total_ns / reps;
}