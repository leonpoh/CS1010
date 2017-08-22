// count_string.c
// Count the number of times a search string appears in a text.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH_SEARCH 15
#define LENGTH_LINE 80

int count_substr(char [], char [], char);

int main(void) {	
	char str[LENGTH_SEARCH + 1], str_backup[LENGTH_SEARCH + 1]; 
	char line[LENGTH_LINE + 1]; 
	char sensitivity;
	int len, count;

	printf("Enter search string with <= %d characters: ", LENGTH_SEARCH);
	fgets(str, LENGTH_SEARCH+1, stdin);
	len = strlen(str); 
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	printf("search string: \"%s\"\n", str);
	strcpy(str_backup, str); 

	printf("Search with case-sensitive ('y' or 'n')? ");
	scanf("%c%*c", &sensitivity);
	if (sensitivity == 'y')
		printf("Case-sensitivity is on.\n");
	else
		printf("Case-sensitivity is off.\n");

	count = 0;
	printf("Enter lines of text, each with <= %d characters,\n", LENGTH_LINE);
	printf("and end with an empty line.\n");

	while (1) {
		fgets(line, LENGTH_LINE+1, stdin);
		len = strlen(line); 
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		len = strlen(line); 
		printf("Line entered: \"%s\"\n", line);

		if (len == 0) 
			break;

		count += count_substr(line, str, sensitivity);
	}

	printf("Number of times \"%s\" appears: %d\n", str_backup, count);
	return 0;	
}

// Count the number of times str occurs in line, 
// depending on case-sensitivity.
int count_substr(char line[], char str[], char sensitivity) 
{
	int len1 = strlen(line);
	int len2 = strlen(str);
	int i, total = 0;
	char *p;

	if(sensitivity == 'y')
	{
		while((line = strstr(line,str))!= NULL)
		{
			total++;
			line++;
		}
	}
	else
	{
		for(i = 0;i < len1; i++) line[i] = toupper(line[i]);
		for(i = 0; i< len2; i++) str[i] = toupper(str[i]);
		while((line = strstr(line, str)) != NULL)
		{
			total++;
			line++;
		}
	}
	return total;
}
