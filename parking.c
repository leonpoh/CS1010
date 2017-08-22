// CS1010 AY2014/5 Semester 1
// PE1 Ex1: parking.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <stdio.h>
#include <math.h>

double computeFee(int, int, int);

int main(void){
	int day, timeIn, timeOut;
	double fee;

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter time-in: ");
	scanf("%d", &timeIn);

	printf("Enter time-out: ");
	scanf("%d", &timeOut);

	fee = computeFee(day, timeIn, timeOut);

	printf("Parking fee is $%.2f.\n", fee);

	return 0;
}

double computeFee(int day, int timeIn, int timeOut)
{
	double fee=0, time;
	
	timeIn = (timeIn/100)*60 + timeIn%100;
	timeOut = (timeOut/100)*60 + timeOut%100;
	time = timeOut - timeIn;

	if(time <= 10)
		return 0;
	else
	{	
		if(day == 7)
			fee += 5;
		else if (day == 6)
		{
			if(timeIn >= 240 && timeIn <= 420)
			{
				fee = (3 - (timeIn - 240)/60)*2.5;
				if(timeOut > 1080)
					fee += (22*1.5 + 7);
				else
					fee += ceil(((float)timeOut-420.0)/30.0)*1.5;
			}
			else if(timeIn > 420 && timeIn <= 1080)
			{
				fee = (22 - (timeIn - 420)/30)*1.5;
				if(timeOut > 1080)
					fee += 7;
			}
			else
				fee = 7;
			if(time > 600)
				fee *= 1.2;
		}
		else
		{
			if(timeIn >= 240 && timeIn <= 420)
			{
				fee = (3 - (timeIn - 240)/60)*2;
				if(timeOut > 1080)
					fee += (22*1.2 + 5);
				else
					fee += (ceil(((float)timeOut-420.0)/30.0))*1.2;
					//printf("%f",ceil(((float)timeOut-420.0)/30.0));
			}
			else if(timeIn > 420 && timeIn <= 1080)
			{
				fee = (22 - (timeIn -420)/30)*1.2;
				if(timeOut > 1080)
					fee+=5;
			}
			else
				fee=5;
			if(time > 600)
				fee *= 1.1;
		}
	}
	if(timeOut > 1320)
		fee += 3;
	
	return fee;
}
