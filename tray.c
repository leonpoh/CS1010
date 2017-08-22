// CS1010 AY2013/4 Semester 1
// PE1 Ex1: tray.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <stdio.h>

int min_unused_area(int, int, int, int);
float min_perimeter(float, float);

int main(void) {
	int trayHeight, trayWidth, slabHeight, slabWidth;

	printf("Enter size of tray: ");
	scanf("%d %d", &trayHeight, &trayWidth);

	printf("Enter size of slab: ");
	scanf("%d %d", &slabHeight, &slabWidth);

	printf("Minimum unused area = %d\n",min_unused_area(trayHeight, trayWidth, slabHeight, slabWidth)); // incomplete

	printf("Minimum perimeter after folding = %.2f\n",min_perimeter(trayHeight,trayWidth)); // incomplete

	return 0;
}

int min_unused_area(int trayHeight, int trayWidth, int slabHeight, int slabWidth)
{
	int area, maxLength, maxWidth, length, width;

	maxLength = trayHeight/ slabHeight;
	maxWidth = trayWidth/ slabWidth;
	length = maxLength * maxWidth;

	maxLength = trayHeight / slabWidth;
	maxWidth = trayWidth / slabHeight;
	width = maxLength * maxWidth;

	if(length > width)
		area = (trayHeight * trayWidth) - length*(slabHeight * slabWidth); 
	else
		area = (trayHeight * trayWidth) - width*(slabHeight * slabWidth);

	return area;
}

float min_perimeter(float trayHeight, float trayWidth)
{
	int i;
	float perimeter;

	for(i=1;i<=3;i++)
	{
		if(trayHeight >= trayWidth)
			trayHeight /=2;
		else
			trayWidth /=2;
	}
	
	return perimeter = 2*trayHeight + 2*trayWidth;
}
