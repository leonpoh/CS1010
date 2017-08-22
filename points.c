// points.c
// Read points data and find the area of the smallest
// circle that encloses all the points.
// This is a skeleton program for students.

typedef struct{
	int x;
	int y;
}point_t;

#include <stdio.h>
#define MAX_POINTS 10
#define PI 3.14159

int read_points(point_t []);
void print_points(point_t [], int);
float circle_area(point_t [], int);

int main(void) {
	point_t points[MAX_POINTS];
	int size;

	size = read_points(points);
	// print_points(points, size); // for checking

	printf("Area of smallest circle = %.2f\n", 
			circle_area(points, size));

	return 0;
}

// Read input data
// Return the number of points read
int read_points(point_t points[]) 
{
	int size, i;
	
	printf("Enter number of points: ");
	scanf("%d",&size);
	printf("Enter data for %d points:\n",size);
	for(i = 0; i < size; i ++)
		scanf("%d %d", &points[i].x, &points[i].y);
	return size;
}

// Print points data
void print_points(point_t points[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("(%d, %d)\n", points[i].x, points[i].y);
}

// Compute area of the smallest circle that encloses
// all the points.
// This is a stub.
float circle_area(point_t points[], int size) 
{
	int i;
	float area;
	for(i = 0; i < size; i++)
	{
		if(PI*(points[i].x*points[i].x + points[i].y*points[i].y) > area)
			area = PI*(points[i].x*points[i].x + points[i].y*points[i].y);
	}
	return area;
}

