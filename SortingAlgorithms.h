#include "ArrayVisualizer.cpp"

void swap (int* A, int* B) {
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

// >>>>>>>>>>>>>>>>  Selection Sort  >>>>>>>>>>>>>>>>
void SelectionSort (int* arr, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i+1; j <= n; j++)
            if(arr[k] > arr[j]) {
                k = j; cmp++;
            }
        swap(&arr[i], &arr[k]);
    }
}
// <<<<<<<<<<<<<<<<  Selection Sort  <<<<<<<<<<<<<<<<
