#include "sort.h"
#include <stdlib.h>

int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
int random_arr[SIZE];

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 200;
}