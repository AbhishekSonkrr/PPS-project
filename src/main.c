#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define SIZE 11
#define MAX 1000
// #include <linux/time.h>


//FUNCTION TO PRINT ARRAY
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
}

//To generate random number
void generate_random(int arr[], int n)
{
    srand (time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX;
    }
    
}

int main()
{
    struct timespec start, end;
    long nanoseconds;

    int ordered[] = {5, 6, 9, 36, 54, 80, 85, 102, 103, 104, 108};
    int reverse[] = {108, 104, 103, 102, 85, 80, 54, 36, 9, 6, 5};
    int randomArr[SIZE];

    generate_random(randomArr, SIZE);

    // Example: Use bubbleSort
    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(ordered, SIZE);
    clock_gettime(CLOCK_REALTIME, &end);
    nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
    printf("ORIGINAL Array:\n");
    printArray(ordered, SIZE);
    printf("Time taken: %ld nanoseconds\n\n", nanoseconds);

    // Repeat for reverse and random arrays as in your sample code
    // You can also call selectionSort, insertionSort, etc., here

    return 0;
}