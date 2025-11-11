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

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 200;
}

#ifndef SORT_FUNC
#error "You must define SORT_FUNC as the sorting function name before including sort_main.h"
#endif
/* Declare the sorting function (the including file must provide it) */
void SORT_FUNC(int arr[], int n);

double sortAndTime(int arr[], int n) {
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
    int random[SIZE];

    srand((unsigned)time(NULL));
    generateRandomArray(random, SIZE);

    printf("Original Ordered Array:\n");
    printArray(ordered, SIZE);
    printf("Original Reverse Array:\n");
    printArray(reverse, SIZE);
    printf("Original Random Array:\n");
    printArray(random, SIZE);

    printf("\nSorted Ordered Array:\n");
    int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof(tmp1)); SORT_FUNC(tmp1, SIZE); printArray(tmp1, SIZE);

    printf("Sorted Reverse Array:\n");
    int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof(tmp2)); SORT_FUNC(tmp2, SIZE); printArray(tmp2, SIZE);

    printf("Sorted Random Array:\n");
    int tmp3[SIZE]; memcpy(tmp3, random, sizeof(tmp3)); SORT_FUNC(tmp3, SIZE); printArray(tmp3, SIZE);

    printf("\nAverage execution time per sort (nanoseconds, approximate):\n");
    printf("Ordered : %.0f\n", sortAndTime(ordered, SIZE));
    printf("Reverse : %.0f\n", sortAndTime(reverse, SIZE));
    printf("Random  : %.0f\n", sortAndTime(random, SIZE));
    return 0;
}
#endif // SORT_MAIN_H