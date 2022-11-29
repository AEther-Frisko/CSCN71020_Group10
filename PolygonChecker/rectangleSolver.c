#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include "rectangleSolver.h"

char* analyzeRect(int points[]) {
	char* result = "";
	int point1[2] = {points[0], points[1]}; //top left
	int point2[2] = {points[2], points[3]}; //top right
	int point3[2] = {points[4], points[5]}; //bottom right
	int point4[2] = {points[6], points[7]}; //bottom left

 	int dist1 = (point2[0] - point1[0]) * (point2[0] - point1[0]);
	dist1 = dist1 + ((point2[1] - point1[1]) * (point2[1] - point1[1]));
	dist1 = sqrt(dist1);
	//distance between top two points

	int dist2 = (point4[0] - point1[0]) * (point4[0] - point1[0]);
	dist2 = dist2 + ((point4[1] - point1[1]) * (point4[1] - point1[1]));
	dist2 = sqrt(dist2);
	//distance between left two points

	if (point1[1] == point2[1] && point2[0] == point3[0] && point3[1] == point4[1] && point4[0] == point1[0]) {
		if (dist2 == dist1){ 
			result = "Input is a square.";
		}
		else {
		result = "Input is a rectangle.";
		}
	}
	else{
		result = "Input is not a rectangle.";
	}
	if (result != "Input is not a rectangle."){
		GetRectArea(dist2, dist1);
	}
	GetPerimeter(dist2, dist1);

	return result;
}

void GetRectArea(int length, int width) {
	int area = length * width;
	printf("The area of the rectangle is: %d\n", area);
}

void GetPerimeter(int length, int width){
	int perimeter = length + width + length + width;
	printf("The perimeter of the shape is: %d\n", perimeter);
}