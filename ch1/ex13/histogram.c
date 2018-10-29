#include <stdio.h>

int main()
{
	int length[20];
	int i, j, c;

	for (i = 0; i < 20; i++)
		length[i] = 0;

	i = 0;

	while ((c = getchar()) != EOF)
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) // c is a letter
			i++;
		else
		{
			length[i]++;
			i = 0;
		}
	}

	printf("Histogram of word length:\n");
	for (i = 1; i < 20; i++)
	{
		printf("%2d: ", i);
		for (j = 0; j < length[i]; j++)
			putchar('|');
		putchar('\n');
	}
}
