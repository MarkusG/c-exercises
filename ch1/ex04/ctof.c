#include <stdio.h>

int main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("Celsius to Fahrenheit Conversion Table\n");

	while (celsius <= upper)
	{
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.2f %3.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
