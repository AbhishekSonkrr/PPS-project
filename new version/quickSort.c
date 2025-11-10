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

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
    return i + 1;
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Wrapper for convenience
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

// Returns average elapsed time in nanoseconds (approximate, portable)
double sortAndTime(int arr[], int n) {
    int tmp[SIZE];
    clock_t start = clock();
    for (int i = 0; i < REPS; ++i) {
        memcpy(tmp, arr, sizeof(int) * n);
        quickSortWrapper(tmp, n);
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
    int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof(tmp1)); quickSortWrapper(tmp1, SIZE); printArray(tmp1, SIZE);

    printf("Sorted Reverse Array:\n");
    int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof(tmp2)); quickSortWrapper(tmp2, SIZE); printArray(tmp2, SIZE);

    printf("Sorted Random Array:\n");
    int tmp3[SIZE]; memcpy(tmp3, random, sizeof(tmp3)); quickSortWrapper(tmp3, SIZE); printArray(tmp3, SIZE);

    printf("\nAverage execution time per sort (nanoseconds, approximate):\n");
    printf("Ordered : %.0f\n", sortAndTime(ordered, SIZE));
    printf("Reverse : %.0f\n", sortAndTime(reverse, SIZE));
    printf("Random  : %.0f\n", sortAndTime(random, SIZE));

    return 0;
}