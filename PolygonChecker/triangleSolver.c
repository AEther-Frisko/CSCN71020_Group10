#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2 || side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}
	if (result != "Not a triangle"){
		GetTriangleAngles(side1, side2, side3);
	}

	return result;
}

void GetTriangleAngles(int side1, int side2, int side3){
	double angle1 = ((side2 * side2) + (side3 * side3) - (side1 * side1));
	angle1 = angle1 / (2 * side2 * side3);
	angle1 = acos(angle1);
	angle1 = angle1 * (180 / M_PI);

	double angle2 = ((side1 * side1) + (side3 * side3) - (side2 * side2));
	angle2 = angle2 / (2 * side1 * side3);
	angle2 = acos(angle2);
	angle2 = angle2 * (180 / M_PI);
	
	double angle3 = 180 - angle1 - angle2;


	printf("The angles of this triangle are: %lf, %lf, %lf\n", angle1, angle2, angle3);
}