#include <stdio.h>

float ftoc(float f);

int main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Farenheit/Celsius Conversion Table\n");
	while (fahr <= upper)
	{
		printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
		fahr = fahr + step;
	}
}

float ftoc(float f)
{
	return (5.0/9.0) * (f - 32.0);
}
