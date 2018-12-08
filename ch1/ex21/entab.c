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
	while (get_line(line, MAXLINE) != 0)
	{
		char c;

		for (int i = 0; (c = line[i]) != '\0'; i++)
		{
			if (c == ' ')
			{
				int tabs = 0;
				int remainingSpaces;
				// every time we pass a tab stop, add a tab
				// make sure to not mess up i here
				while (line[++i] == ' ')
				{
					if (i % TABSTOP == 0)
						tabs++;
				}
				remainingSpaces = TABSTOP - ((i) % TABSTOP);
				i -= 2;
				
				for (int j = 0; j < tabs; j++)
					putchar('\t');
				for (int j = 0; j < remainingSpaces; j++)
					putchar(' ');
			}
			else
				putchar(c);
		}
	}
}
