#include <stdio.h>

int main()
{
	int c;
	while (c = (getchar() != EOF))
	{
		printf("A: The value of getchar() != EOF is: %d\n", c);
	};
	printf("B: The value of getchar() != EOF is: %d\n", c);
}
