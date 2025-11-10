#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

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

long long timeDiffNano(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
}

int main() {
    int ordered[] = {5, 6, 9, 36, 54, 80, 85, 102, 103, 104, 108};
    int reverse[] = {108, 104, 103, 102, 85, 80, 54, 36, 9, 6, 5};
    int randomArr[SIZE];

    // Generate random array
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        randomArr[i] = rand() % 200;  // Random numbers between 0 and 199
    }

    printf("Ordered array: ");
    display(ordered, SIZE);

    printf("Reverse array: ");
    display(reverse, SIZE);

    printf("Random array: ");
    display(randomArr, SIZE);

    struct timespec start, end;

    // Measure execution time for ordered array
    clock_gettime(CLOCK_MONOTONIC, &start);
    shell_sort(ordered, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time1_ns = timeDiffNano(start, end);

    // Measure execution time for reverse array
    clock_gettime(CLOCK_MONOTONIC, &start);
    shell_sort(reverse, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time2_ns = timeDiffNano(start, end);

    // Measure execution time for random array
    clock_gettime(CLOCK_MONOTONIC, &start);
    shell_sort(randomArr, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time3_ns = timeDiffNano(start, end);

    // Display sorted arrays
    printf("\nSorted Ordered array: ");
    display(ordered, SIZE);
    printf("Sorted Reverse array: ");
    display(reverse, SIZE);
    printf("Sorted Random array: ");
    display(randomArr, SIZE);

    // Display execution times
    printf("\nExecution Times:\n");
    printf("Ordered array: %lld ns (%.9f seconds)\n", time1_ns, time1_ns / 1e9);
    printf("Reverse array: %lld ns (%.9f seconds)\n", time2_ns, time2_ns / 1e9);
    printf("Random array: %lld ns (%.9f seconds)\n", time3_ns, time3_ns / 1e9);

    return 0;
}