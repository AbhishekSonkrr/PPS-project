#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // random number between 0–99
    }
}

void selection_sort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    generate(a, n);

    printf("\nUnsorted array:\n");
    print(a, n);

    clock_t start, end;
    double time_used;

    start = clock();           // start time
    selection_sort(a, n);
    end = clock();             // end time

    time_used = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    print(a, n);

    printf("\nTime taken: %f seconds\n", time_used);

    return 0;
}