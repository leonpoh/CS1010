// check_order.c 
// Repeatedly reads positive integer, until the input value 
// is zero, or the data are not in increasing order.

#include <stdio.h>

int main(void) {
	int flag=0,value,check=0;
	while(flag==0)
	{
		printf("Enter positive integer: ");
		scanf("%d",&value);

		if(value==0 || value <= check)
			flag=1;

		check = value;
	}

	if(value==0)
		printf("Data are in increasing order.\n");
	else
		printf("Data are not in increasing order.\n");

	return 0;
}

