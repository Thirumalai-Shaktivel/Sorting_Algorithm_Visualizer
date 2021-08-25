#include "ArrayVisualizer.cpp"

void swap (int* A, int* B) {
    int tmp = *A;
    *A = *B;
    *B = tmp;
    renderFunction();
    usleep(delay);
}


// >>>>>>>>>>>>>>>>  Cycle Sort  >>>>>>>>>>>>>>>>
void CycleSort(int arr[], int n)
{
    int writes = 0;
    for (int cyc = 0; cyc <= n - 2; cyc++) {
        int item = arr[cyc];
        int pos = cyc;
        for (int i = cyc + 1; i < n; i++)
            if (arr[i] < item) {
                pos++;
            }

        if (pos == cyc) continue;

        while (item == arr[pos]){
            pos++;
        }
        if (pos != cyc) {
            swap(&item, &arr[pos]);
            writes++;
        }
        while (pos != cyc) {
            pos = cyc;

            for (int i = cyc + 1; i < n; i++)
                if (arr[i] < item){
                    pos++;
                }

            while (item == arr[pos]){
                    pos++;
                }

            if (item != arr[pos]) {
                swap(&item, &arr[pos]);
                writes++;
            }
        }
    }
}
// <<<<<<<<<<<<<<<<  Cycle Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Selection Sort  >>>>>>>>>>>>>>>>
void SelectionSort (int* arr, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i+1; j <= n; j++)
            if(arr[k] > arr[j]) {
                k = j;
            }
        swap(&arr[i], &arr[k]);
    }
}
// <<<<<<<<<<<<<<<<  Selection Sort  <<<<<<<<<<<<<<<<
