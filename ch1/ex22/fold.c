#include <stdio.h>
#define LIMIT 1000
#define WIDTH 8

int getchars(char line[], int lim);
int fold(char line[], char out[], int lim);

int main()
{
	char input[LIMIT];
	char final[LIMIT];

	printf("Enter some characters:\n");
	getchars(input, LIMIT);
	fold(input, final, WIDTH);
	printf("Folded output:\n%s\n", final);

	return 0;
}

int getchars(char line[], int lim)
{
	int c, i, l;

	for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 1)
			line[l++] = c;
	line[l] = '\0';

	return i;
}

int fold(char line[], char out[], int lim)
{
	int i, l, c;

	for (i = 0, l = 0; i < LIMIT - 1 && (c = line[i]) != '\0'; ++i)
	{
		out[l++] = c;
		if (i % lim == 0 && i != 0)
			out[l++] = '\n';
	}

	return l;
}
