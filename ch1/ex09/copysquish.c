#include <stdio.h>

int main()
{
	int c;
	int blank;
	blank = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (!blank)
			{
				putchar(c);
				blank = 1;
			}
		}
		else
		{
			putchar(c);
			blank = 0;
		}
	}
}
