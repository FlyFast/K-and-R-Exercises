#include <stdio.h>
#include <ctype.h>
#include <stdbool.h> // for booleans
#include <unistd.h>  // for sleep()

// K and R exercise 1-14
// Create a histogram of the frequency of characters in the input.
//    This version displays the histogram bars horizontally.
//    The characters are not sorted but are displayed as the occur in the file.
//    This can best be tested by redirecting input from a file using:
//       1-14_histogram_characters < my_input_file

#define NUM_CHARS 512
#define CHAR_POS  0
#define COUNT_POS 1

int main()
{
   int c;                     // input chracter
   int chars[NUM_CHARS][2];   // array of character types stored char and count
   int char_count = 0;        // count of unique characters in input
   bool match = false;        // to indicate if matched

   // Get all of the input characters
   while ((c = getchar()) != EOF)
   {
      if (isprint(c))   // check for any printable character including spaces
      {
         // check if character is already in the array
         for (int i = 0; i < char_count; i++)
         {
            if (c == chars[i][CHAR_POS]) // See if this is the character
            {
               // if so, increment the count for that char and set match flag
               chars[i][COUNT_POS]++; 
               match = true;
            }
         };
         // if not, add the character to the array and set count to 1
         if (!match)
         {
            chars[char_count][CHAR_POS] = c;
            chars[char_count][COUNT_POS] = 1;
            char_count++;
         };
         match = false;
      } 
   };

   /* Debug code
   // Check and see if the array looks correct
   for (int i = 0; i < char_count; i++)
   {
      printf("%c: ", chars[i][CHAR_POS]);
      printf("%d\n", chars[i][COUNT_POS]);
   }
   End of debug code */

   // After we have read all of the input characters, use the array to print
   // histograms for each character
   for (int i = 0; i < char_count; i++)
   {
      // print the character
      printf("%c: ", chars[i][CHAR_POS]);
      // print the count for that character as a bar made of *
      for (int bar = 1; bar <= chars[i][COUNT_POS]; bar++)
      {
         printf("*");
      };
      printf("\n");
   };
}
