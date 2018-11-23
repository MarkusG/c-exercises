#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int get_line(char s[], int max)
{
	char c;
	int i;

	for (i = 0; (c = getchar()) != EOF && i < max - 1; i++)
	{
		s[i] = c;
		if (c == '\n')
			break;
	}
	s[i + 1] = '\0';
	return i;
}

int main(void)
{
	char line[MAXLINE];
	char c;
	while (get_line(line, MAXLINE) != 0)
	{
		for (int i = 0; (c = line[i]) != '\0'; i++);
	}
}
