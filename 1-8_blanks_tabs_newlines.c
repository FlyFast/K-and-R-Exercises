#include <stdio.h>

// Count the number of blanks tabs and newlines in the input stream

int main()
{
	int c; 				// The character read in
   int blanks = 0;	// Number of blanks
	int tabs = 0;		// Number of tabs
	int newlines = 0;	// Number of newlines

	c = getchar();
	while (c != EOF)
	{
		switch (c)
		{
			case ' ': 	blanks++;
						 	break;
			case '\t': 	tabs++;
						 	break;
			case '\n': 	newlines++;
							break;
		}
		c = getchar();		
	};
	printf("Blanks: %d  Tabs: %d  Newlines: %d\n", blanks, tabs, newlines);
}
