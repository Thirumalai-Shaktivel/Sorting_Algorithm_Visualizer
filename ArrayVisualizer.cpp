#include "GL/glut.h"
#include "GL/gl.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
int length, choice;
std::string SortingName;
int* arr;
void (*sort)(int*, int, int);

void randomizeArray(int* arr, int length) {
	for(int i = length - 1; i > 0; --i)
		std::swap(arr[i], arr[rand() % (i+1)]);
}

void renderFunction() {

}

void keyboardEvent(unsigned char c, int x, int y) {
	switch(c) {
		case 27:
		// Exit on `Esc` key pressed
			free(arr);
			exit(0);
		case 'S':
		case 's':
		// start on `s` or `S` key pressed
			sort(arr, length, choice);
			break;
	}
}

int setUpGlutAndArray(int argc, char** argv, void (*sortingAlgorithm)(int*, int, int)) {
	std::cout << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";
	std::cout <<"Select the Sorting algorithm to Visualize:\n\n";
	std::cout <<"\t1. Cycle Sort\n\t2. Selection Sort\n\t3. Radix Sort\n\t"
	"4. Quick Sort\n\t5. Heap Sort\n\t6. Merge Sort\n\t7. Bubble Sort\n\t"
	"8. Insertion Sort\n\t9. Cocktail Sort\n\t10. Gnome Sort\n\n";
	std::cout <<"Enter your Choice: ";
	scanf("%d", &choice);
	std::cout << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";

	sort = sortingAlgorithm;
	arr = (int*) malloc(sizeof(int) * length);

	for(int i = 0; i < length; ++i)
		arr[i] = i;
	randomizeArray(arr, length);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1500, 750);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Sorting Algorithm Visualization");

	glutDisplayFunc(renderFunction);
	glutKeyboardFunc(keyboardEvent);
	gluOrtho2D(-1.025,1.005,-1,1.35);
	glutMainLoop();
	return 0;
}
