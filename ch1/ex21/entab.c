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
				int spaces = 0;
				int remainingSpaces;
				// every time we pass a tab stop, add a tab
				while (line[i] == ' ')
				{
					spaces++;
					i++;
				}
				i--;

				if (i < TABSTOP)
				{
					for (int j = 0; j < spaces; j++)
						putchar(' ');
					continue;
				}

				int tabs = spaces / TABSTOP + 1;
				for (int j = 0; j < tabs; j++)
					putchar('\t');

				if ((i + 1) % TABSTOP != 0)
				{
					remainingSpaces = (i + 1) % TABSTOP;
					if (i + 1 < TABSTOP)
						remainingSpaces = TABSTOP - remainingSpaces;
					for (int j = 0; j < remainingSpaces; j++)
						putchar(' ');
				}

			}
			else
				putchar(c);
		}
	}
}
