#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11
#define SORT_FUNC bubbleSort
#include "sort_main.h"

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// No local main — `sort_main.h` supplies a common main that will call bubbleSort
