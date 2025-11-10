#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
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
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        randomArr[i] = rand() % 200;  // Random numbers between 0 and 199
    }
    printf("Ordered array: ");
    displayArray(ordered, SIZE);
    printf("Reverse array: ");
    displayArray(reverse, SIZE);
    printf("Random array: ");
    displayArray(randomArr, SIZE);
    struct timespec start, end;
    int arr1[SIZE];
    for (int i = 0; i < SIZE; i++) arr1[i] = ordered[i];
    clock_gettime(CLOCK_MONOTONIC, &start);
    bubbleSort(arr1, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time1_ns = timeDiffNano(start, end);
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++) arr2[i] = reverse[i];
    clock_gettime(CLOCK_MONOTONIC, &start);
    bubbleSort(arr2, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time2_ns = timeDiffNano(start, end);
    int arr3[SIZE];
    for (int i = 0; i < SIZE; i++) arr3[i] = randomArr[i];
    clock_gettime(CLOCK_MONOTONIC, &start);
    bubbleSort(arr3, SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long time3_ns = timeDiffNano(start, end);
    printf("\nSorted Ordered array: ");
    displayArray(arr1, SIZE);
    printf("Sorted Reverse array: ");
    displayArray(arr2, SIZE);
    printf("Sorted Random array: ");
    displayArray(arr3, SIZE);
    printf("\nExecution Times:\n");
    printf("Ordered array: %lld ns (%.9f seconds)\n", time1_ns, time1_ns / 1e9);
    printf("Reverse array: %lld ns (%.9f seconds)\n", time2_ns, time2_ns / 1e9);
    printf("Random array: %lld ns (%.9f seconds)\n", time3_ns, time3_ns / 1e9);

    return 0;
}
