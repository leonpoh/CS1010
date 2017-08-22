// triangleCentroid.c
// This program computes the centroid (G) of a triangle
// given the coordinates of three vertices.
#include <stdio.h>

void centroid(float, float, float, float, float, float, float *, float *);

int main(void) {
	float x1, y1,    // coordinates of 1st vertex
	      x2, y2,    // coordinates of 2nd vertex
	      x3, y3,    // coordinates of 3rd vertex
		  xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);

	centroid(x1, y1, x2, y2, x3, y3, &xG, &yG);
	printf("Coordinates of centroid = (%.2f, %.2f)\n", xG, yG);

	return  0;
}

void centroid(float x1, float y1, float x2, float y2, float x3, float y3, float *xG, float *yG)
{
	*xG = (x1 + x2 + x3)/3;
	*yG = (y1 + y2 + y3)/3;
}
