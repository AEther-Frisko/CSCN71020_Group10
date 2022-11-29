#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;
int rows, cols, i, j;
int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			int rectPoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectPointsPtr = getRectanglePoints(rectPoints);
			result = analyzeRect(rectPointsPtr);
			printf_s("%s\n", result);
			
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	switch (scanf("%d", &shapeChoice)) {
	case 1:
		break;
	case 0:
		printf("ERROR - input not an integer\n");
		exit(EXIT_FAILURE);
	case 2:
		break;
	default:
		printf("ERROR - input validation failure\n");
		exit(EXIT_FAILURE);
	}
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int* getRectanglePoints(int* rectPoints) {
	printf_s("Enter the four points of the rectangle (each input should be the x and y of the point, seperated by a space): ");
	for (int i = 0; i < 8; i = i + 2) {
		scanf_s("%d %d", &rectPoints[i], &rectPoints[i + 1]);
	}
	return rectPoints;
}