#include <stdio.h>

// Print Fahrenheit-Celsius table
// 	for fahr = 0, 20, ..., 300; Floating point version

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;	// Lower limit of the temperature table
	upper = 150;	// Upper limit of the temperature table
	step	= 10;		// Step size

	// Print a heading for the table
	printf("%3s %6s\n", "C", "F");
	printf("--- ------\n");

	// Print the table
	celsius = lower;
	while (celsius <= upper)
	{
		fahr = (9.0/5.0) * (celsius - 32.0);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
