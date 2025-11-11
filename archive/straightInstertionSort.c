#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11
#define SORT_FUNC straightInsertionSort
#include "sort_main.h"

void straightInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// No local main — `sort_main.h` supplies a common main that will call straightInsertionSort
