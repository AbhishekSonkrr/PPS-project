#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 200;
}

// Function to measure time in nanoseconds
long getExecutionTime(void (*sortFunc)(int[], int), int arr[], int n) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    sortFunc(arr, n);
    clock_gettime(CLOCK_MONOTONIC, &end);

    return (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
}

int main() {
    int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
    int random[SIZE];
    generateRandomArray(random, SIZE);

    printf("Original Ordered Array:\n");
    printArray(ordered, SIZE);
    long timeOrdered = getExecutionTime(heapSort, ordered, SIZE);
    printf("Sorted Ordered Array:\n");
    printArray(ordered, SIZE);
    printf("Time taken: %ld nanoseconds\n", timeOrdered);

    printf("\nOriginal Reverse Array:\n");
    printArray(reverse, SIZE);
    long timeReverse = getExecutionTime(heapSort, reverse, SIZE);
    printf("Sorted Reverse Array:\n");
    printArray(reverse, SIZE);
    printf("Time taken: %ld nanoseconds\n", timeReverse);

    printf("\nOriginal Random Array:\n");
    printArray(random, SIZE);
    long timeRandom = getExecutionTime(heapSort, random, SIZE);
    printf("Sorted Random Array:\n");
    printArray(random, SIZE);
    printf("Time taken: %ld nanoseconds\n", timeRandom);

    return 0;
}