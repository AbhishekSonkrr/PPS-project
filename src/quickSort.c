#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11
#define SORT_FUNC quickSortWrapper
#include "sort_main.h"

// Partition function for Quick Sort
static int partition(int arr[], int low, int high) {
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
static void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Wrapper for convenience
void quickSortWrapper(int arr[], int n) {
    if (n > 0) quickSort(arr, 0, n - 1);
}
