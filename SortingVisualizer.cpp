#include "SortingAlgorithms.h"

void visualizeQuickSort(int* arr, int size, int choice)
{
	switch(choice) {
		case 1:
			SortingName = "Cycle Sort";
			CycleSort(arr, size);
			break;
		case 2:
			SortingName = "Selection Sort";
			SelectionSort(arr, size-1);
			break;
		case 3:
			SortingName = "Radix Sort";
			RadixSort(arr, size);
			break;
		case 4:
			SortingName = "Quick Sort";
			QuickSort(arr, 0, size - 1);
			break;
		case 5:
			SortingName = "Heap Sort";
			HeapSort(arr, size-1);
			break;
		case 6:
			SortingName = "Merge Sort";
			MergeSort(arr, 0, size - 1);
			break;
		default:
			std::cout << "Error!! Invalid Input!";
			exit(0);
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	delay = 50000;
	length = 50;
	setUpGlutAndArray(argc, argv, visualizeQuickSort);
	free(arr);
	return 0;
}
