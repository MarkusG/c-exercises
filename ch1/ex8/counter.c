#include <stdio.h>

int main()
{
	int c;
	int blank, tab, newline;
	blank = tab = newline = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			blank++;
		if (c == '\t')
			tab++;
		if (c == '\n')
			newline++;
	}

	printf("%d blanks\n%d tabs\n%d newlines\n", blank, tab, newline);
}
