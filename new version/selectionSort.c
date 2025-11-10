#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include "sort.h"

#define SIZE 11

/* small, inlinable swap to reduce call overhead */
static inline void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/* slightly optimized selection sort: use local variables to reduce memory refs */
static void selectionSort(int arr[], int n) {
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
            /* place minVal at i and move old arr[i] to minIndex */
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

/* generate once (do NOT call srand() here) */
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) arr[i] = rand() % 200;
}

/* time sorting a copy repeated 'reps' times, return average ns per run */
static long long timed_avg_ns(void (*sortfn)(int[], int), int src[], int n, int reps) {
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

int main(void) {
     sortDemo("Selection Sort", selectionSort, timed_avg_ns);
    //sortDemo("Bubble Sort", bubbleSort, timed_avg_ns);
    // int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    // int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
    // int random[SIZE];

    // /* seed once (do not reseed every generate) */
    // srand((unsigned)time(NULL));
    // generateRandomArray(random, SIZE);

    // /* print samples (not measured) */
    // puts("Original Ordered Array:");
    // printArray(ordered, SIZE);
    // puts("Sorted Ordered Array:");
    // int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof tmp1); selectionSort(tmp1, SIZE); printArray(tmp1, SIZE);

    // puts("\nOriginal Reverse Array:");
    // printArray(reverse, SIZE);
    // puts("Sorted Reverse Array:");
    // int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof tmp2); selectionSort(tmp2, SIZE); printArray(tmp2, SIZE);

    // puts("\nOriginal Random Array:");
    // printArray(random, SIZE);
    // puts("Sorted Random Array:");
    // int tmp3[SIZE]; memcpy(tmp3, random, sizeof tmp3); selectionSort(tmp3, SIZE); printArray(tmp3, SIZE);

    // /* measure average time per sort (increase reps for more stable numbers) */
    // const int REPS = 20000; /* tune up/down as desired */
    // long long tord = timed_avg_ns(selectionSort, ordered, SIZE, REPS);
    // long long trev = timed_avg_ns(selectionSort, reverse, SIZE, REPS);
    // long long trand = timed_avg_ns(selectionSort, random, SIZE, REPS);

    // printf("\nAverage time per sort (over %d runs):\n", REPS);
    // printf("Ordered : %lld ns\n", tord);
    // printf("Reverse : %lld ns\n", trev);
    // printf("Random  : %lld ns\n", trand);

    return 0;
}