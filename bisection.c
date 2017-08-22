/**
 * CS1010 AY2016/7 Semester 1 Lab2 Ex3
 * bisection.c
 * Li Liwei
 * C1B
 * Uses the bisection method to return a root from a polynomial and endpoints given by user
 */

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001

// Given function prototype must not be changed
double polynomial(double point, int c3, int c2, int c1, int c0);

int main(void) 
{
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
	       pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");//Gather user input
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);
	
	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a , &b);
	
	while (pM !=0)//Makes sure pM not equals to 0
	{
		pA = polynomial(a, c3, c2, c1, c0);//Calculates pA,pB,midpoint and pM
		pB = polynomial(b, c3, c2, c1, c0);
		m = (a+b)/2.0;
		pM = polynomial(m, c3, c2, c1, c0);

		//printf("a = %lf, b = %lf, m = %lf, pA = %lf, pB = %lf, pM = %lf\n", a, b, m, pA, pB, pM); //Un-comment this line to check flow

		if(fabs(a-b)<THRESHOLD)//Check if distance between the two endpoints fall below the threshold
			break;
		else if (pM > 0 && pB > 0)//If both pM and pB are positive, replace point b with midpoint
			b = m;
		else
			a = m;
	}
	printf("root = %f\n", m);
	printf("p(root) = %f\n", pM);

	return 0;
}

double polynomial(double point, int c3, int c2, int c1, int c0)//Computes and returns the value of a given point in a polynomial
{
	double functionValue;

	return functionValue = c3*(pow(point,3)) + c2*(pow(point,2)) + c1*point + c0;
}
