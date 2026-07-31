#include <stdio.h>
#include <ctype.h>

// Copy input to output, printing one word per line.
// K and R exercise 1-12

int main()
{
   int c;               // input chracter

   while ((c = getchar()) != EOF)
   {
      if (isgraph(c))   // check for any printable character except space
      {
         putchar(c);  //    if printable/non-space, print it 
      } 
      else
      { 
         putchar('\n'); //    else print newline
      };
   };
}
