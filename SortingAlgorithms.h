#include "ArrayVisualizer.cpp"

void swap (int* A, int* B) {
    int tmp = *A;
    *A = *B;
    *B = tmp;
    renderFunction();
    usleep(delay);
    swaps++;
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
                pos++; cmp++;
            }

        if (pos == cyc) continue;

        while (item == arr[pos]){
            pos++; cmp++;
        }
        if (pos != cyc) {
            swap(&item, &arr[pos]);
            writes++; cmp++;
        }
        while (pos != cyc) {
            pos = cyc;

            for (int i = cyc + 1; i < n; i++)
                if (arr[i] < item){
                    pos++; cmp++;
                }

            while (item == arr[pos]){
                    pos++; cmp++;
                }

            if (item != arr[pos]) {
                swap(&item, &arr[pos]);
                writes++; cmp++;
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
                k = j; cmp++;
            }
        swap(&arr[i], &arr[k]);
    }
}
// <<<<<<<<<<<<<<<<  Selection Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Radix Sort  >>>>>>>>>>>>>>>>
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        swap(&arr[i], &output[i]);
}

void RadixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
// <<<<<<<<<<<<<<<<  Radix Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Quick Sort  >>>>>>>>>>>>>>>>
int Partition(int arr[], int low, int high){
    int i = low - 1;
    int pivot = arr[high];
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++; cmp++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[high], &arr[i+1]);
    return i+1;
}
void QuickSort(int arr[], int low, int high){
    if(low < high) {
        int pivot = Partition(arr, low, high);
        cmp++;
        QuickSort(arr, low, pivot-1);
        QuickSort(arr, pivot+1, high);
    }
}
// <<<<<<<<<<<<<<<<  Quick Sort  <<<<<<<<<<<<<<<<
