/**
 * CS1010 AY2016/7 Semester 1 Lab1 Ex3
 * packing.c
 * Read in the dimensions of a tray and a slab, and to compute the maximum possible number of slabs that could be packed onto the tray
 * Li Liwei
 * C1B
 */

#include <stdio.h>

int compute_max_slabs(int trayLength, int trayWidth, int slabLength, int slabWidth);

int main(void) 
{
	int max_slabs, trayLength, trayWidth, slabLength, slabWidth;
	
	printf("Enter dimension of tray: ");//Gather user input
	scanf("%d %d",&trayLength,&trayWidth);
	printf("Enter dimension of slab: ");
	scanf("%d %d",&slabLength,&slabWidth);

	max_slabs = compute_max_slabs(trayLength, trayWidth, slabLength, slabWidth);//Compute max slabs

	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

int compute_max_slabs(int trayLength, int trayWidth, int slabLength, int slabWidth) //Read in the dimensions of a tray and a slab
{                                                                                   //and computes and returns the maximum possible number of slabs that could be packed onto the tray
	int maxLength, maxWidth, maxSlabs1, maxSlabs2;

	maxLength = trayLength / slabLength;//First orientation
	maxWidth = trayWidth / slabWidth;
	maxSlabs1 = maxLength * maxWidth;

	maxLength = trayLength / slabWidth;//Second orientation
	maxWidth = trayWidth / slabLength;
	maxSlabs2 = maxLength * maxWidth;

	if(maxSlabs1 >= maxSlabs2)//Determine which orientation has more slabs
		return maxSlabs1;
	else
		return maxSlabs2;
}
