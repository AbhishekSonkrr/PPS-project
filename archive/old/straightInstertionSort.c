// Legacy wrapper moved here from src/straightInstertionSort.c
// Kept for historical/reference purposes.

// This wrapper used to forward to straightInsertionSort to retain
// compatibility with any code that referenced the misspelled symbol.

// Declare the real function implemented in src/straightInsertionSort.c
void straightInsertionSort(int arr[], int n);

// Forwarding wrapper (legacy)
void straightInstertionSort(int arr[], int n) {
    straightInsertionSort(arr, n);
}

