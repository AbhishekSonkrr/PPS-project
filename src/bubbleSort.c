/*-------------------------------HEADER FILE----------------------------*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <linux/time.h>
#include <SORT_FUNC.h>


// #define SIZE 11
// #define MAX 1000

/*----------------------------------LOGIC--------------------------------*/

//FUNCTION TO PRINT ARRAY
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
}

// BUBBLE SORT LOGIC
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
        } 
        
    }
}

/*TO GENERATE RANDOM ARRAY*/
void generate_random(int arr[], int n)
{
    srand (time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX;
    }
    
}

/*---------------------------------TO PRINT-----------------------------------*/
int main()
{
    struct timespec start, end;
    long nanoseconds;

    int ordered[] = {5, 6, 9, 36, 54, 80, 85, 102, 103, 104, 108};
    int reverse[] = {108, 104, 103, 102, 85, 80, 54, 36, 9, 6, 5};
    int randomArr[SIZE];

    generate_random(randomArr, SIZE);

    // Measure time for ordered array
    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(ordered, SIZE);
    clock_gettime(CLOCK_REALTIME, &end);

    nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);

    printf("ORIGINAL Array:\n");
    printArray(ordered, SIZE);

    printf("Time taken: %ld nanoseconds\n\n", nanoseconds);

    // Measure time for reverse array
    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(reverse, SIZE);
    clock_gettime(CLOCK_REALTIME, &end);

    nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);

    printf("REVERSE Array:\n");
    printArray(reverse, SIZE);

    printf("Time taken: %ld nanoseconds\n\n", nanoseconds);

    // Measure time for random array
    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(randomArr, SIZE);
    clock_gettime(CLOCK_REALTIME, &end);

    nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);

    printf("RANDOM Array:\n");
    printArray(randomArr, SIZE);
    
    printf("Time taken: %ld nanoseconds\n", nanoseconds);

    return 0;
}
