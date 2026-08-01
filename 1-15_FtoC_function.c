#include <stdio.h>

// K and R exercise 1-15
// Print Fahrenheit-Celsius table using a function
// 	for fahr = 0, 20, ..., 300; Floating point version

float FtoC(float F)
{
  return((5.0/9.0) * (F - 32.0));
}

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
	while (fahr <= upper)
	{
      celsius = FtoC(fahr);
		printf("%3.0f %6.1F\n", fahr, celsius);
		fahr = fahr + step;
	}
}
