#include <stdio.h>

// Print Fahrenheit-Celsius table
// 	for fahr = 0, 20, ..., 300; Floating point version

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		// Lower limit of the temperature table
	upper = 300;	// Upper limit of the temperature table
	step	= 20;		// Step size

	// Print a heading for the table
	printf("%3s %6s\n", "F", "C");
	printf("--- ------\n");

	// Print the table
	fahr = lower;
	// while (fahr <= upper)
	for (fahr = upper; fahr >= lower; fahr = fahr - step)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1F\n", fahr, celsius);
	}
}
