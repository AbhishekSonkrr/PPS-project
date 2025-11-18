/* heap.c - heap sort implementation */
#include "sorts.h"
#include <stddef.h>

static void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap_int(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap_int(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
