#include <stdio.h>
#include <math.h>

unsigned long htoi(char s[], int len)
{
	unsigned long result = 0;
	int i = 0;
	/* if the string begins with 0x, start parsing after it */
	if (s[1] == 'x' || s[1] == 'X')
		i = 2;

	for (; i < len - 1; i++)
	{
		char offset;
		if (s[i] > 47 && s[i] < 58) /* char is 0-9 */
			offset = 48;
		if (s[i] > 64 && s[i] < 71) /* char is A-F */
			offset = 65 - 10; /* 65 to get to A, 10 because we already went through 0-9 */
		if (s[i] > 96 && s[i] < 103) /* char is a-f */
			offset = 97 - 10; /* see above */
		char dec = s[i] - offset;
		printf("position: %ld\n", i);
		printf("character: %c\n", s[i]);
		printf("decimal value: %ld\n", dec);
		printf("place: %ld\n", len - 2 - i);
		printf("addend: %ld\n", dec * (unsigned int)pow(16.0, len - 2 - i));
		result += (dec * (unsigned int)pow(16.0, len - 2 - i));
		printf("new result: %ld\n\n", result);
	}

	return result;
}

int main(void)
{
	printf("%ld\n", htoi("0xf00ff0f0", 11));
}

