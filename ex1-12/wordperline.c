#include <stdio.h>

int main()
{
	int c;
	int inspace;
	inspace = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (!inspace)
			{
				putchar('\n');
				inspace = 1;
			}
		}
		else
		{
			inspace = 0;
			putchar(c);
		}
	}
}
