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
		case 7:
			SortingName = "Bubble Sort";
			BubbleSort(arr, size-1);
			break;
		case 8:
			SortingName = "Insertion Sort";
			InsertionSort(arr, size-1);
			break;
		case 9:
			SortingName = "Cocktail Sort";
			CocktailSort(arr, size);
			break;
		case 10:
			SortingName = "Gnome Sort";
			GnomeSort(arr, size);
			break;
		default:
			std::cout << red <<"Error!! Invalid Input!"<< no_color;
			std::cout << yellow << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n" << no_color;
			exit(0);
		}
		std::cout << "\nSelected Algorithm\t\t: " <<red<< SortingName <<no_color<<"\n";
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	// Decrease the delay to increase the speed.
	delay = 50000; // Delay in milliseconds
	// Length of the columns in the output
	length = 50;
	setUpGlutAndArray(argc, argv, visualizeQuickSort);
	free(arr);
	return 0;
}
