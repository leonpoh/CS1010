// DaysSince1Jan2016.c
// This program reads the day and month of 2016 and computes
// the number of days since 1st January 2016.
#include <stdio.h>

int computeDays(int, int);

int main(void) {    
	int day, month;

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	printf("Day %d of month %d is the %dth day of 2016.\n", 
	       day, month, computeDays(day, month));

	return 0;
}

// This function computes the number of days that have elapsed 
// for the given day and month since 1st January 2016.
int computeDays(int day, int mth) 
{
	switch(mth)
	{
		case 1 : day = day; break;
		case 2 : day = day + 31; break;
		case 3 : day = day + 60; break;
		case 4 : day = day + 91; break;
		case 5 : day = day + 121; break;
		case 6 : day = day + 152; break;
		case 7 : day = day + 182; break;
		case 8 : day = day + 213; break;
		case 9 : day = day + 243; break;
		case 10: day = day + 274; break;
		case 11: day = day + 304; break;
		case 12: day = day + 335; break;
	}
	
	return day;
}

