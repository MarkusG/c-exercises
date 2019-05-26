#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("Range of char is [%d, %d]\n", CHAR_MIN, CHAR_MAX);

	char i = 0;
	char char_max = 0;
	char char_min = 0;

	while (--i < 0)
		char_min = i;

	i = 0;

	while (++i > 0)
		char_max = i;

	printf("The range of char is [%d, %d]\n", char_min, char_max);
}
