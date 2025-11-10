// #ifndef SORT_H
// #define SORT_H

// #include <stdlib.h>

// #define SIZE 11

// /* data definitions are in sort.c */
// extern int ordered[SIZE];
// extern int reverse[SIZE];
// extern int random_arr[SIZE];

// /* helper to fill random_arr */
// void generateRandomArray(int arr[], int n);

// #endif /* SORT_H */



#ifndef SORT_H
#define SORT_H

#define SIZE 11

extern int ordered[SIZE];
extern int reverse[SIZE];
extern int random_arr[SIZE];

void generateRandomArray(int arr[], int n);

#endif /* SORT_H */