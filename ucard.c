// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
#include <stdio.h>

int luhnah(int);
void issued(int);

int main(void) {
	int uCardNo; 

	printf("Enter uCard Number: ");
	scanf("%d",&uCardNo);

	if(luhnah(uCardNo))
	{
		printf("Valid\n");

		for(;uCardNo>=100;uCardNo/=10);
		//printf("%d",uCardNo);
		issued(uCardNo);
	}
	else
		printf("Invalid\n");

	return 0;
}

void issued(int uCardNo)
{
	if(uCardNo >= 31 && uCardNo <= 35)
	    printf("Issued by East branch\n");
	else if (uCardNo >= 51 && uCardNo <= 55)
		printf("Issued by West branch\n");
	else
		printf("Issued by Central branch\n");
}
int luhnah(int uCardNo)
{
	int total;

	while (uCardNo)
	{
		total = total + uCardNo%10 + (((uCardNo/10)%10) * 2)%10 + (((uCardNo/10)%10) * 2)/10;
		//printf("%d",total);
		uCardNo =uCardNo/100;
	}
	
	printf("The check number is %d\n",total);

	if(total % 7 ==0)
		return 1;
	else 
		return 0;
}
