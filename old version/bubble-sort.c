#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fills the array with random numbers from -50 to 49
void randomize_array(int *array, int length) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 100) - 50;
    }
}

// Bubble sort algorithm
void bubble_sort(int *array, int length) {
    int swapped;
    for (int pass = 0; pass < length - 1; pass++) {
        swapped = 0;
        for (int i = 0; i < length - pass - 1; i++) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break; // Stop if already sorted
    }
}

// Prints the array elements
void print_array(const int *array, int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *data = malloc(n * sizeof(int));
    if (!data) {
        printf("Allocation failed.\n");
        return 1;
    }

    randomize_array(data, n);

    printf("Before sorting:\n");
    print_array(data, n);

    clock_t begin = clock();
    bubble_sort(data, n);
    clock_t end = clock();

    printf("After sorting:\n");
    print_array(data, n);

    printf("Time: %.6f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

    free(data);
    return 0;
}