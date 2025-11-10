#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

void swap(int *a, int *b) { // Function to swap two integers
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n) { // Selection sort function
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) { // Find the minimum element in the unsorted part
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);// Swap the found minimum with the first element
    }
}
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 200; // Random numbers between 0 and 199
}
int main() {
    int ordered[SIZE] = {5,6,9,36,54,80,85,102,103,104,108};
    int reverse[SIZE] = {108,104,103,103,85,80,54,36,9,6,5};
    int random[SIZE];
    generateRandomArray(random, SIZE);
    printf("Original Ordered Array:\n");
    printArray(ordered, SIZE);
    selectionSort(ordered, SIZE);
    printf("Sorted Ordered Array:\n");
    printArray(ordered, SIZE);
    printf("\nOriginal Reverse Array:\n");
    printArray(reverse, SIZE);
    selectionSort(reverse, SIZE);
    printf("Sorted Reverse Array:\n");
    printArray(reverse, SIZE);
    printf("\nOriginal Random Array:\n");
    printArray(random, SIZE);
    selectionSort(random, SIZE);
    printf("Sorted Random Array:\n");
    printArray(random, SIZE);
    return 0;
}