#ifndef SORT_MAIN_H
#define SORT_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef SIZE
#define SIZE 11
#endif

#ifndef REPS
#define REPS 100000
#endif

#ifndef SORT_FUNC
#error "You must #define SORT_FUNC as the sorting function name before including sort_main.h"
#endif

/* Declare the sorting function (the including file must provide it) */
void SORT_FUNC(int arr[], int n);

static void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
}

static void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 200;
}

/* Returns average elapsed time per sort in nanoseconds (approximate) */
static double sortAndTime(int arr[], int n) {
    int tmp[SIZE];
    clock_t start = clock();
    for (int i = 0; i < REPS; ++i) {
        memcpy(tmp, arr, sizeof(int) * n);
        SORT_FUNC(tmp, n);
    }
    clock_t end = clock();
    return ((double)(end - start) * (1e9 / CLOCKS_PER_SEC)) / REPS;
}

int main(void) {
    int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    int reverse[SIZE] = {108,104,103,102,85,80,54,36,9,6,5};
    int randomArr[SIZE];

    srand((unsigned)time(NULL));
    generateRandomArray(randomArr, SIZE);

    printf("Original Ordered Array:\n");
    printArray(ordered, SIZE);
    printf("Original Reverse Array:\n");
    printArray(reverse, SIZE);
    printf("Original Random Array:\n");
    printArray(randomArr, SIZE);

    printf("\nSorted Ordered Array:\n");
    { int tmp[SIZE]; memcpy(tmp, ordered, sizeof(tmp)); SORT_FUNC(tmp, SIZE); printArray(tmp, SIZE); }

    printf("Sorted Reverse Array:\n");
    { int tmp[SIZE]; memcpy(tmp, reverse, sizeof(tmp)); SORT_FUNC(tmp, SIZE); printArray(tmp, SIZE); }

    printf("Sorted Random Array:\n");
    { int tmp[SIZE]; memcpy(tmp, randomArr, sizeof(tmp)); SORT_FUNC(tmp, SIZE); printArray(tmp, SIZE); }

    printf("\nAverage execution time per sort (nanoseconds, approximate):\n");
    printf("Ordered : %.0f\n", sortAndTime(ordered, SIZE));
    printf("Reverse : %.0f\n", sortAndTime(reverse, SIZE));
    printf("Random  : %.0f\n", sortAndTime(randomArr, SIZE));

    return 0;
}

#endif 
