// CS1010 AY2015/6 Semester 2 PE1 Ex1
//
// line.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>

int determineType(double,double,double);
double computeK(int,int,int,int);
void printMessage(int);

int main(void) {
	int ax, ay, bx, by, cx, cy, dx, dy;
	double kAB, kCD, kAC;

	printf("Enter the coordinates of A: ");
	scanf("%d %d",&ax,&ay);
	printf("Enter the coordinates of B: ");	
	scanf("%d %d",&bx,&by);
	printf("Enter the coordinates of C: ");
	scanf("%d %d",&cx,&cy);
	printf("Enter the coordinates of D: ");
	scanf("%d %d",&dx,&dy);

	kAB = computeK(ax,ay,bx,by);
	kCD = computeK(cx,cy,dx,dy);
	kAC = computeK(ax,ay,cx,cy);
	//printf("%f, %f, %f", kAB, kCD, kAC);
	printMessage(determineType(kAB,kCD,kAC));

	return 0;
}

int determineType(double kAB, double kCD, double kAC)
{
	if(kAB == kCD && kAB != kAC) //if lines are parallel
		return 1;
	else if(kAB != kCD) //if lines intersect
		return 2;
	else if(kAB == kCD && kAB == kAC) //if lines overlap
		return 3;
	else
		return 0;
}

double computeK(int x1, int y1, int x2, int y2)
{
	double k;
	
	return k = (((double)y1-(double)y2)/((double)x1-(double)x2));
}

void printMessage(int type)
{
	switch(type)
	{
		case 1: printf("The two lines are parallel.\n");break;
		case 2: printf("The two lines are intersecting.\n");break;
		case 3: printf("The two lines are overlapping.\n");break;
	}
}
