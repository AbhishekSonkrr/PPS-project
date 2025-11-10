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

// Swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Returns average elapsed time in nanoseconds (approximate, portable)
double sortAndTime(int arr[], int n) {
    int tmp[SIZE];
    clock_t start = clock();
    for (int i = 0; i < REPS; ++i) {
        memcpy(tmp, arr, sizeof(int) * n);
        heapSort(tmp, n);
    }
    clock_t end = clock();
    return ((double)(end - start) * (1e9 / CLOCKS_PER_SEC)) / REPS;
}

int main(void) {
    int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
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
    int tmp1[SIZE]; memcpy(tmp1, ordered, sizeof(tmp1)); heapSort(tmp1, SIZE); printArray(tmp1, SIZE);

    printf("Sorted Reverse Array:\n");
    int tmp2[SIZE]; memcpy(tmp2, reverse, sizeof(tmp2)); heapSort(tmp2, SIZE); printArray(tmp2, SIZE);

    printf("Sorted Random Array:\n");
    int tmp3[SIZE]; memcpy(tmp3, random, sizeof(tmp3)); heapSort(tmp3, SIZE); printArray(tmp3, SIZE);

    printf("\nAverage execution time per sort (nanoseconds, approximate):\n");
    printf("Ordered : %.0f\n", sortAndTime(ordered, SIZE));
    printf("Reverse : %.0f\n", sortAndTime(reverse, SIZE));
    printf("Random  : %.0f\n", sortAndTime(random, SIZE));

    return 0;
}