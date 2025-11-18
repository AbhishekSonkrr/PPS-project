/* main.c - demo program that runs several sorting algorithms and times them
   Easy to read and modify: each sort is in its own source file. */

#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "sorts.h"

/* Helper to copy and run a sort, printing time and result */
/* Run the given sort on a copy of `src` and return elapsed nanoseconds. */
/* Run the given sort on a copy of `src`, print the sorted result labeled by
   `label`, and return elapsed nanoseconds. */
static long run_sort_time_and_print(const char *label, int src[], int n, void (*sort_fn)(int[], int))
{
    struct timespec start, end;
    int tmp[SIZE];

    memcpy(tmp, src, n * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &start);
    sort_fn(tmp, n);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("%s:\n", label);
    printArray(tmp, n);

    return (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
}

int main(void)
{
    int base_ordered[SIZE] = {5, 6, 9, 36, 54, 80, 85, 102, 103, 104, 108};
    int base_reverse[SIZE] = {108, 104, 103, 102, 85, 80, 54, 36, 9, 6, 5};
    int randomArr[SIZE];



    /* For each sort we will run on ordered, reverse and random inputs */

    /* Bubble Sort */
    printf("=== Bubble Sort ===\n");
    long b_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, bubbleSort);
    long b_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, bubbleSort);
    generate_random(randomArr, SIZE);
    long b_rnd = run_sort_time_and_print("random", randomArr, SIZE, bubbleSort);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", b_ord, b_rev, b_rnd);

    /* Quick Sort */
    printf("=== Quick Sort ===\n");
    long q_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, quickSortWrapper);
    long q_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, quickSortWrapper);
    generate_random(randomArr, SIZE);
    long q_rnd = run_sort_time_and_print("random", randomArr, SIZE, quickSortWrapper);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", q_ord, q_rev, q_rnd);

    /* Heap Sort */
    printf("=== Heap Sort ===\n");
    long h_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, heapSort);
    long h_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, heapSort);
    generate_random(randomArr, SIZE);
    long h_rnd = run_sort_time_and_print("random", randomArr, SIZE, heapSort);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", h_ord, h_rev, h_rnd);

    /* Selection Sort */
    printf("=== Selection Sort ===\n");
    long s_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, selectionSort);
    long s_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, selectionSort);
    generate_random(randomArr, SIZE);
    long s_rnd = run_sort_time_and_print("random", randomArr, SIZE, selectionSort);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", s_ord, s_rev, s_rnd);

    /* Shell Sort */
    printf("=== Shell Sort ===\n");
    long sh_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, shell_sort);
    long sh_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, shell_sort);
    generate_random(randomArr, SIZE);
    long sh_rnd = run_sort_time_and_print("random", randomArr, SIZE, shell_sort);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", sh_ord, sh_rev, sh_rnd);

    /* Insertion Sort */
    printf("=== Insertion Sort ===\n");
    long i_ord = run_sort_time_and_print("ordered", base_ordered, SIZE, straightInsertionSort);
    long i_rev = run_sort_time_and_print("reversed", base_reverse, SIZE, straightInsertionSort);
    generate_random(randomArr, SIZE);
    long i_rnd = run_sort_time_and_print("random", randomArr, SIZE, straightInsertionSort);
    printf("Time Taken\nordered: %ld ns\nreversed: %ld ns\nrandom: %ld ns\n\n", i_ord, i_rev, i_rnd);

    return 0;
}
