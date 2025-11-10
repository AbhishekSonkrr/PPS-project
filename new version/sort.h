#ifndef SORT_DEMO_H
#define SORT_DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#define SIZE 11

void printArray(int arr[], int n);
void generateRandomArray(int arr[], int n);

// Demo function: pass any sorting function with signature void sort(int[], int)
static inline void sortDemo(const char *sortName, void (*sortfn)(int[], int), long long (*timed_avg_ns)(void (*)(int[], int), int[], int, int)) {
    int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
    int random[SIZE];

    srand((unsigned)time(NULL));
    generateRandomArray(random, SIZE);

    printf("\n=== %s Demo ===\n", sortName);

    puts("Original Ordered Array:");
    printArray(ordered, SIZE);
    puts("Sorted Ordered Array:");
    int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof tmp1); sortfn(tmp1, SIZE); printArray(tmp1, SIZE);

    puts("\nOriginal Reverse Array:");
    printArray(reverse, SIZE);
    puts("Sorted Reverse Array:");
    int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof tmp2); sortfn(tmp2, SIZE); printArray(tmp2, SIZE);

    puts("\nOriginal Random Array:");
    printArray(random, SIZE);
    puts("Sorted Random Array:");
    int tmp3[SIZE]; memcpy(tmp3, random, sizeof tmp3); sortfn(tmp3, SIZE); printArray(tmp3, SIZE);

    const int REPS = 20000;
    long long tord = timed_avg_ns(sortfn, ordered, SIZE, REPS);
    long long trev = timed_avg_ns(sortfn, reverse, SIZE, REPS);
    long long trand = timed_avg_ns(sortfn, random, SIZE, REPS);

    printf("\nAverage time per sort (over %d runs):\n", REPS);
    printf("Ordered : %lld ns\n", tord);
    printf("Reverse : %lld ns\n", trev);
    printf("Random  : %lld ns\n", trand);
}

#endif // SORT_DEMO_H