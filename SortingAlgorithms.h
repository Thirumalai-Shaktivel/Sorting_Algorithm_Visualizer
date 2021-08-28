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

// >>>>>>>>>>>>>>>>  Heap Sort  >>>>>>>>>>>>>>>>
void heapify(int* arr, int n, int i) {
    int largest = i;
    int left    = 2*i+1;
    int right   = 2*i+2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left; cmp++;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right; cmp++;
    }
    if(largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}
void HeapSort (int* arr, int n) {
    for (int i = n/2; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
// <<<<<<<<<<<<<<<<  Heap Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Merge Sort  >>>>>>>>>>>>>>>>
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k; i = j = 0; k = p;

    while (i < n1 && j < n2) {
        cmp++;
        if (L[i] <= M[j]) {
            swap(&arr[k], &L[i]);
            cmp++; i++;
        } else {
            swap(&arr[k], &M[j]);
            j++;
        }
        k++;
    }
    while (i < n1) {
        swap(&arr[k], &L[i]);
        i++; k++; cmp++;
    }

    while (j < n2) {
        swap(&arr[k], &M[j]);
        j++; k++; cmp++;
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        cmp++;
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// <<<<<<<<<<<<<<<<  Merge Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Bubble Sort  >>>>>>>>>>>>>>>>
void BubbleSort(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        int flag = 0;
        for(int j = 0; j < n-i; j++)
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
                cmp++;
            }
        if (flag == 0) break;
    }
}
// <<<<<<<<<<<<<<<<  Bubble Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Insertion Sort  >>>>>>>>>>>>>>>>
void InsertionSort (int* arr, int n) {
    int value, tmp;
    for (int i = 1; i <= n; i++) {
        tmp = i; value = arr[i];
        while (tmp > 0 && arr[tmp-1] > value){
            swap(&arr[tmp--], &arr[tmp-1]);
            cmp++;
        }
        arr[tmp--] = value;
    }
}
// <<<<<<<<<<<<<<<<  Insertion Sort  <<<<<<<<<<<<<<<<

// >>>>>>>>>>>>>>>>  Cocktail Sort  >>>>>>>>>>>>>>>>
void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = true; cmp++;
            }
        }
        if (!swapped) break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = true; cmp++;
            }
        }
    }
}
// <<<<<<<<<<<<<<<<  Cocktail Sort  <<<<<<<<<<<<<<<<
