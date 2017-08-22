/**
 * CS1010 AY2016/7 Semester 1 Lab1 Ex2
 * box.c
 * Reads three positive integers representing the length, width and height of a box, and computes its surface area, and the length of the diagonal between two vertices of the box that are furthest apart
 * Li Liwei
 * C1B
 */

#include <stdio.h>
#include <math.h>

int surArea(int length, int width, int height);
double diaLength(int length, int width, int height);

int main(void) 
{
	int length, width, height, area;
	double diagonal;

	printf("Enter length: ");
	scanf("%d",&length);
	printf("Enter width : ");
	scanf("%d",&width);
	printf("Enter height: ");
	scanf("%d",&height);

	area = surArea(length, width, height);
	diagonal = diaLength(length, width, height);

	printf("Surface area = %d\n", area);
	printf("Diagonal = %.2lf\n", diagonal);

	return 0;
}

int surArea(int length, int width, int height) //Reads three positive integers representing length, width and
{                                      //height of a box and computes the surface area
	int area;

	area = 2 * length * width + 2 * length * height + 2 * width * height;

	return area;
}

double diaLength(int length, int width, int height) //Reads three positive integers representing length, width and 
{                                           //height of a box and computes the length of the diagonal between two vertices of the box that are the furthest apart
	double diagonal;

	diagonal = sqrt(pow(sqrt(pow(width,2) + pow(length,2)),2) + pow(height,2));
	
	return diagonal;
}

