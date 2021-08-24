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
		default:
			std::cout << "Error!! Invalid Input!";
			exit(0);
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	length = 50;
	setUpGlutAndArray(argc, argv, visualizeQuickSort);
	free(arr);
	return 0;
}
