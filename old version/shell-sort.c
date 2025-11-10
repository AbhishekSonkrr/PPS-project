#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random numbers in the array
void fill_random(int arr[], int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 200 - 100; // random number between -100 and 99
    }
}

// Shell Sort implementation
void shell_sort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Print the array
void display(const int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Input array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    fill_random(arr, n);
    printf("\nOriginal array:\n");
    display(arr, n);
    clock_t t1 = clock();
    shell_sort(arr, n);
    clock_t t2 = clock();
    printf("\nSorted array:\n");
    display(arr, n);
    printf("\nElapsed time: %.6f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}