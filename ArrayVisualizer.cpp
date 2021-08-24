#include <stdlib.h>
#include <iostream>
#include <unistd.h>
int choice;
int main(int argc, char* argv[]) {
	std::cout << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";
	std::cout <<"Select the Sorting algorithm to Visualize:\n\n";
	std::cout <<"\t1. Cycle Sort\n\t2. Selection Sort\n\t3. Radix Sort\n\t"
	"4. Quick Sort\n\t5. Heap Sort\n\t6. Merge Sort\n\t7. Bubble Sort\n\t"
	"8. Insertion Sort\n\t9. Cocktail Sort\n\t10. Gnome Sort\n\n";
	std::cout <<"Enter your Choice: ";
	scanf("%d", &choice);
	std::cout << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";
	return 0;
}
