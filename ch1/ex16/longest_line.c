#include <stdio.h>
#define MAXLINE 20

int get_line(char dest[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
	{
		printf("The longest line with a length of %d characters is:\n", max);
		printf("%s", longest);
	}
	return 0;
}

int get_line(char dest[], int max)
{
	int i, l, c;

	for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; i++)
		if (l < max - 1)
			dest[l++] = c;
	dest[l] = '\0';

	return i;
}

void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
