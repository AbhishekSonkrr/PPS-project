/* utils.c - printing and random array generation */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void generate_random(int arr[], int n)
{
    /* Seed once. If program calls this multiple times quickly,
       seeding here is acceptable for this simple demo. */
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX;
    }
}
