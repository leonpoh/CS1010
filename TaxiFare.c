// TaxiFare.c
// This program computes taxi fare.
#include <stdio.h>
#define INCREMENT 0.22

float computeFare(int, int, int);

int main(void) {    
	int dayType; // 0 = weekends and public holidays;
	             // 1 = weekdays and non public holidays
	int boardHour, boardMin; // hour and minute of boarding
	int boardTime;           // converted from boardHour and boardMin
	int distance;            // distance of journey

	printf("Day type: ");
	scanf("%d", &dayType);
	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardHour, &boardMin);
	printf("Distance: ");
	scanf("%d", &distance);

	// complete the next line
	// boardTime = ...
	boardTime = boardHour * 60 + boardMin;
	printf("Boarding time is %d minutes\n", boardTime);

	printf("Total taxi fare is $%.2f\n", 
	       computeFare(dayType, boardTime, distance));

	return 0;
}

// Compute taxi fare based on
//   type: 0 = weekends and PH; 1 = weekdays
//   time: time passenger boarded taxi (in minutes from 0:00hr)
//   dist: distance of journey
// This function is called a stub as it returns a dummy value
float computeFare(int type, int time, int dist) 
{
	float fare, checker;
	if(dist<10200)
	{
		checker = (dist-1000)/400;
		if (((dist-1000)%400)>0) 
			checker++;
	}
	else
	{
		checker = 23 + (dist -10200)/350;
		if (((dist -10200)%350)!=0)checker++;
	}

	fare = 3.4 + checker * 0.22;

	if (time <= 359)
	{
		fare = fare * 1.5;
	}
	else if ((time <= 569 && type ==1) ||(time >= 1080 && time <= 1439))
	{
		fare = fare * 1.25;
	}
	
	return fare;  
}

