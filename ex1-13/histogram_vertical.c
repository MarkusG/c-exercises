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
	// Find maximum word length to know height of our histogram
	int max;
	max = 0;
	for (i = 1; i < 20; i++)
		if (length[i] > max)
			max = length[i];

	for (i = 0; i < max; i++)
	{
		for (j = 1; j < 20; j++)
		{
			if (length[j] >= max - i)
				printf("|| ");
			else
				printf("   ");
		}
		
		putchar('\n');
	}
	// Print footer
	for (i = 1; i < 20; i++)
		printf("%02d ", i);
}
