/* sorts.h - shared header for sorting examples */

#ifndef SORTS_H
#define SORTS_H

#include <time.h>

#define SIZE 11
#define MAX 200

/* Utilities */
void printArray(int arr[], int n);
void generate_random(int arr[], int n);

/* Sorting function prototypes */
void bubbleSort(int arr[], int n);
void heapSort(int arr[], int n);
void quickSortWrapper(int arr[], int n);
void selectionSort(int arr[], int n);
void shell_sort(int arr[], int size);
void straightInsertionSort(int arr[], int n);

#endif /* SORTS_H */
