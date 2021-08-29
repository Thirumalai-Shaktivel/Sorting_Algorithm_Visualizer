#include "GL/glut.h"
#include "GL/gl.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::seconds;

auto red = "\033[1;31m";
auto yellow = "\033[1;33m";
auto green = "\033[1;32m";
auto white = "\033[1;37m";
auto purple = "\033[1;35m";
auto cyan = "\033[1;36m";
auto no_color = "\033[0m";

int length, delay, choice, swaps, cmp;
std::string SortingName;
int* arr;

void (*sort)(int*, int, int);

void randomizeArray(int* arr, int length) {
	for(int i = length - 1; i > 0; --i)
		std::swap(arr[i], arr[rand() % (i+1)]);
}

void drawBitmapString(float x,float y,std::string s) {
	glColor3f(1,1,1);
	glRasterPos2f(x, y);
	for(int i=0;i<s.size();i++)
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

void renderFunction() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawBitmapString(-0.1, 1.25, SortingName);
	drawBitmapString(-1, 1.17,"Comparisons : "+std::to_string(cmp));
	drawBitmapString(-1, 1.06,"Swaps            : "+std::to_string(swaps));
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	float l = (float) length;
	float widthAdder = 1/l;

	for(int i = 0; i < length; ++i) {
		glBegin(GL_POLYGON);

		float arrayIndexHeightRation = 2*(arr[i] + 1)/l;
		float widthIndexAdder = 2*i/l;

		float leftX   = -1 + widthIndexAdder;
		float rightX  = leftX + widthAdder;
		float bottomY = -1;
		float topY    = bottomY + arrayIndexHeightRation;

		glColor4f(1,0,0,0);
		glVertex2f(leftX, bottomY);

		glColor4f(0,1,0,0);
		glVertex2f(rightX, bottomY);

		glColor4f(0,0,1,0);
		glVertex2f(rightX, topY);

		glColor4f(0,0,0,1);
		glVertex2f(leftX, topY);

		glEnd();
	}

	glFlush();
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
			auto t1 = high_resolution_clock::now();
			sort(arr, length, choice);
			auto t2 = high_resolution_clock::now();
			auto ms_int = duration_cast<seconds>(t2 - t1);
			std::cout << "Time taken for "<< cyan << length  << no_color << " items\t\t: ";
			std::cout << red << ms_int.count() << " seconds" << no_color;
			std::cout << yellow << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n" << no_color;
			break;
	}
}

int setUpGlutAndArray(int argc, char** argv, void (*sortingAlgorithm)(int*, int, int)) {
	std::cout << yellow << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";
	std::cout << green <<"Select the Sorting algorithm to Visualize:\n\n";
	std::cout << white <<"\t1. Cycle Sort\n\t2. Selection Sort\n\t3. Radix Sort\n\t"
	"4. Quick Sort\n\t5. Heap Sort\n\t6. Merge Sort\n\t7. Bubble Sort\n\t"
	"8. Insertion Sort\n\t9. Cocktail Sort\n\t10. Gnome Sort\n\n";
	std::cout << cyan <<"Enter your Choice: " << no_color;
	scanf("%d", &choice);
	std::cout << yellow << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n";
	std::cout << green << "Instructions:\n" << no_color
			  <<"\tPress"<< purple <<" s" << white
			  <<" | "<< purple <<"S "<< white <<"-> Start the Sorting\n"
			    "\tPress "<< purple <<"Esc   "<< white <<"-> Exit the Visualizer";
	std::cout << yellow << "\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n" << no_color;
	swaps = cmp = 0;

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
