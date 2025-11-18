/* main.c - beginner-friendly demo for several sorting algorithms.
   Each sort is implemented in its own file and declared in `sorts.h`.
   This program runs each sort on three inputs: ordered, reversed and random.
   It prints the sorted arrays and the time taken (nanoseconds). */

#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "sorts.h"

/* Simple name for a sorting function */
typedef void (*SortFn)(int[], int);

/* time_and_print: sort a copy of `arr`, print the labeled sorted array,
   and return elapsed time in nanoseconds. */
static long time_and_print(const char *label, int arr[], int n, SortFn fn)
{
    struct timespec start, end;
    int copy[SIZE];

    /* copy input so original stays unchanged */
    memcpy(copy, arr, n * sizeof(int));

    clock_gettime(CLOCK_REALTIME, &start);
    fn(copy, n);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("%s:\n", label);
    printArray(copy, n);

    return (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
}

/* run_test: run one sorting function on ordered, reversed and random inputs.
   Prints the sorted arrays and a small "Time Taken" block. */
static void run_test(const char *label, SortFn fn, int orderedArr[], int reversedArr[])
{
    int randomArr[SIZE];
    printf("=== %s ===\n", label);

    /* show the actual input arrays before sorting */
    printf("Input - ordered:\n");
    printArray(orderedArr, SIZE);
    long t_ordered = time_and_print("ordered", orderedArr, SIZE, fn);

    printf("Input - reversed:\n");
    printArray(reversedArr, SIZE);
    long t_reversed = time_and_print("reversed", reversedArr, SIZE, fn);

    generate_random(randomArr, SIZE);
    printf("Input - random:\n");
    printArray(randomArr, SIZE);
    long t_random = time_and_print("random", randomArr, SIZE, fn);

    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n",
           t_ordered, t_reversed, t_random);
}

int main(void)
{
    int orderedArr[SIZE] = {5, 6, 9, 36, 54, 80, 85, 102, 103, 104, 108};
    int reversedArr[SIZE] = {108, 104, 103, 102, 85, 80, 54, 36, 9, 6, 5};

    /* run tests for each sorting algorithm */
    run_test("Bubble Sort", bubbleSort, orderedArr, reversedArr);
    run_test("Quick Sort", quickSortWrapper, orderedArr, reversedArr);
    run_test("Heap Sort", heapSort, orderedArr, reversedArr);
    run_test("Selection Sort", selectionSort, orderedArr, reversedArr);
    run_test("Shell Sort", shell_sort, orderedArr, reversedArr);
    run_test("Insertion Sort", straightInsertionSort, orderedArr, reversedArr);

    return 0;
}
