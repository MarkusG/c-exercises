#include <stdio.h>

#define MAXLINE 5000
#define TABSTOP 8

int get_line(char s[], int lim)
{
	char c;
	int i;

	for (i = 0; (c = getchar()) != EOF && i < lim - 1; i++)
	{
		s[i] = c;
		if (c == '\n')
			break;
	}
	s[++i] = '\0';
	return i;
}

int main(void)
{
	char line[MAXLINE];
	while (get_line(line, MAXLINE) > 0)
	{
		// i keeps track of where we are in the original string
		// k keeps track of where we are in stdout
		// j is reused every time we encounter \t to keep track of how many spaces to place
		// l is reused every time we encounter \t so that we don't increment k while we're using it
		int i, j, l;
		int k = 0;
		char c;
		
		for (i = 0; (c = line[i]) != '\0'; i++)
		{
			if (c == '\t')
			{
				l = 0;
				for (j = 0; j < TABSTOP - (k % TABSTOP); j++)
				{
					putchar(' ');
					l++;
				}
				k += l;
			}
			else
			{
				putchar(c);
				k++;
			}
		}
	}	
}
