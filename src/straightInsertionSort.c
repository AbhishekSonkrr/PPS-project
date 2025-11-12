// filepath: /home/abhishek/Desktop/PPS-project/src/straightInsertionSort.c
// Implementation moved here from the misspelled file `straightInstertionSort.c`

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
