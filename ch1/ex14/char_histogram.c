#include <stdio.h>

int main()
{
	int freq[26];
	int c, i, j;

	for (i = 0; i < 26; i++)
		freq[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c >= 65 && c <= 90) // Uppercase letter
			freq[c - 65]++;
		if (c >= 97 && c <= 122)
			freq[c - 97]++;
	}

	printf("Histogram of word length:\n");
	for (i = 0; i < 26; i++)
	{
		printf("%c: ", i + 65);
		for (j = 0; j < freq[i]; j++)
			putchar('|');
		putchar('\n');
	}
}
