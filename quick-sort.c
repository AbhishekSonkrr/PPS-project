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

// Quick sort partition function
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    return i + 1;
}

// Quick sort algorithm
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
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
    quick_sort(data, 0, n - 1);
    clock_t end = clock();

    printf("After sorting:\n");
    print_array(data, n);

    printf("Time: %.6f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

    free(data);
    return 0;
}