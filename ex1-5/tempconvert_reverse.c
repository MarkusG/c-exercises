#include <stdio.h>

int main()
{
	float fahr, celsius; 
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	for (fahr = upper; fahr >= lower; fahr -= step)
	{
		celsius = (fahr - 32) * (5.0/9.0);
		printf("%3.2f %3.2f\n", fahr, celsius);
	}
}
