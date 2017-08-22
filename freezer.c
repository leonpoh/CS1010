/*
 *  freezer.c
 *  Unit 3 Exercise 5: Estimate temperature in a freezer
 *  given the elapsed time since power failure.
 *  Formula: T = (4*t^2 / (t+2)) - 20
 */
#include <stdio.h>
#include <math.h>

int main(void) {
	int hours, minutes;
	float temperature;  // Temperature in freezer

	// Get the hours and minutes
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	temperature = ((4.0*(pow((hours+(minutes/60.0)),2)))/(hours+(minutes/60.0)+2))-20;
	
	printf("Temperature in freezer = %.2f\n",temperature);

	return 0;
}

