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
				int tabs = 0;
				while (line[i] == ' ')
				{
					spaces++;
					if ((i + 1) % TABSTOP == 0)
					{
						tabs++;
						putchar('\t');
					}
					i++;
				}
				i--;
				
				if (tabs == 0)
				{
					for (int j = 0; j < spaces; j++)
						putchar(' ');
				}
				else if ((i + 1) % TABSTOP != 0)
				{
					int remainingSpaces = (i + 1) % TABSTOP;
					for (int j = 0; j < remainingSpaces; j++)
						putchar(' ');
				}

			}
			else
				putchar(c);
		}
	}
}
