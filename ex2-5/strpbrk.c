#include <stdio.h>
#define MAXLEN 5000

int my_strpbrk(char source[], char selectors[]);
int match(char c, char selectors[]);

int main()
{
	char source[MAXLEN] = "Hello world! This should return the first occurrence of 's'.";
	char selectors[4] = "trs";

	int index = my_strpbrk(source, selectors);

	printf("%s\n%i\n", source, index);
}

int my_strpbrk(char source[], char selectors[])
{
	int i, j;

	for (i = 0; source[i] != '\0'; i++)
		if (match(source[i], selectors))
				return i;
	return -1;
}

int match(char c, char selectors[])
{
	int i;

	for (i = 0; selectors[i] != '\0'; i++)
		if (selectors[i] == c)
			return 1;
	return 0;
}
