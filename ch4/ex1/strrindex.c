#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char s[], char t[]);

char pattern[] = "foo";

int main()
{
	
}

int getline(char s[], int lim)
{
	int c, i;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	
}
