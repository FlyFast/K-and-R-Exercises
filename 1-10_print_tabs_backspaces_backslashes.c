#include <stdio.h>

// Copy input to output and replace tabs, backspaces, and backslashes
//   with thier printable equivilents.
// K and R exercise 1-10
// Note: This would be greatly imporoved by using a switch statment.

int main()
{
   int c;                  // input chracter

   while ((c = getchar()) != EOF)
   {
      if (c == '\t')       
      {
         putchar('\\');
         putchar('t');
      } 
      else
      { 
         if (c == '\b')
         {
            putchar('\\');
            putchar('b');
         }
         else 
         {
            if (c == '\\')
            {
               putchar('\\');
               putchar('\\');
            }
            else
            {
               putchar(c);
            };
         };
      };
   };
}
