#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 11
#define REPS 100000  // Number of repetitions for averaging

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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            int t = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = t;
        }
    }
}

// Returns average elapsed time in nanoseconds (approximate, portable)
double sortAndTime(int arr[], int n) {
    int tmp[SIZE];
    clock_t start = clock();
    for (int i = 0; i < REPS; ++i) {
        memcpy(tmp, arr, sizeof(int) * n);
        selectionSort(tmp, n);
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
    int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof(tmp1)); selectionSort(tmp1, SIZE); printArray(tmp1, SIZE);

    printf("Sorted Reverse Array:\n");
    int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof(tmp2)); selectionSort(tmp2, SIZE); printArray(tmp2, SIZE);

    printf("Sorted Random Array:\n");
    int tmp3[SIZE]; memcpy(tmp3, random, sizeof(tmp3)); selectionSort(tmp3, SIZE); printArray(tmp3, SIZE);

    printf("\nAverage execution time per sort (nanoseconds, approximate):\n");
    printf("Ordered : %.0f\n", sortAndTime(ordered, SIZE));
    printf("Reverse : %.0f\n", sortAndTime(reverse, SIZE));
    printf("Random  : %.0f\n", sortAndTime(random, SIZE));

    return 0;
}