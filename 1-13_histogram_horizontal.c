#include <stdio.h>
#include <ctype.h>

// K and R exercise 1-13
// Create a histogram of the length of the words in the input.
//    This version displays the histogram bars horizontally.
//    This can best be tested by redirecting input from a file using:
//       1-13_histogram_horizontal < my_input_file

int main()
{
   int c;               // input chracter
   int word_len = 0;    // length of the current word, set to zero

   while ((c = getchar()) != EOF)
   {
      if (isgraph(c))   // check for any printable character except space
      {
         word_len++;    //    if printable/non-space, increment character count
      } 
      else              // print the bar for the current word
      {
         for (int i = 0; i < word_len; i++)
         {
            putchar('*'); //    else print newline
         };
         putchar('\n');
         word_len = 0;  // reset the word length for the next work
      };
   };
}
