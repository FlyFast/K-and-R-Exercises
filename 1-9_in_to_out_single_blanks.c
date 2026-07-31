#include <stdio.h>

// Copy input to output and replace repeating spaces with single spaces.
// K and R exercise 1-9

int main()
{
   int c;                  // input chracter
   int prev_c = 'a';       // previous input character initialized to non-space.

   while ((c = getchar()) != EOF)
   {
      if (c != prev_c)     // if not == to last character, send to output
      {
         putchar(c);
      } 
      else // c == prev_c  // if == to last character, check if blank
      {
         if (c != ' ')     // if not blank, send to output. Else ignore.   
         {
            putchar(c);
         }
      }
      prev_c = c;          // update the previous character for next loop
   }
}
