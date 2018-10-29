#include <stdio.h>
#define MAXLINE 1000

void append_and_remove(char to[], char from[]);
int get_line(char s[], int max);

int main(void)
{
	char line[MAXLINE];
	char final[MAXLINE];

	while (get_line(line, MAXLINE) > 0)
		append_and_remove(final, line);

	printf("%s", final);
	return 0;
}

void append_and_remove(char to[], char from[])
{
	int i, l, c, trail;

	for (i = 0; (c = from[i]) != '\0'; i++)
	{
		if (c == ' ' || c == '\t')
		{
			l = i;
			trail = 1;
			while (from[++l] != '\n')
				if (from[l] != ' ' && from[l] != '\t')
				{
					trail = 0;
					break;
				}
		}
		if (trail)
			to[i] = from[i];
	}
}

int get_line(char s[], int max)
{
	int i, c;
	
	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
