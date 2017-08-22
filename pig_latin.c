// pig_latin.c
#include <stdio.h>

void convert(char [], char []);

int main(void) {
	char sent[81];
	char converted[80*81];

	printf("Enter sentence: ");
	fgets(sent,81,stdin);
	
	convert(sent, converted);

	printf("\nConverted: %s\n", converted);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char src[], char dest[]) 
{
	char str[81*81], a;
	int len = strlen(src), i,n, count = 0, new;
	for(i = 0; i< len;i++)
	{
		while(!isspace(src[i]))
		{
			str[count++] = src[i++];
		}
		a = str[0];
		if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		{
			strcat(str, "way ");
			strcat(dest, str);
		}
		else if(!isspace(a))
		{
			new = strlen(str);
			for(n = 0; n < new-1;n++)
				str[n] = str[n+1];
			str[new-1] = a;
			strcat(str, "ay ");
			strcat(dest, str);
		}
		count = 0;
		new = strlen(str);
		for(n = 0;n<new;n++)
			str[n] = NULL;
	}
}
