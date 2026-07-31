#include <stdio.h>
#include <ctype.h>
#include <sys/ioctl.h>  // Needed to determine the terminal width
#include <unistd.h>
#include <stdlib.h>     // Needed for malloc()
#include <string.h>     // Needed for memset()
#include <unistd.h>     // Needed for sleep. Can be removed after testing.

// K and R exercise 1-13
// Create a histogram of the length of the words in the input.
//    This version displays the histogram bars vertically.
//    This can best be tested by redirecting input from a file using:
//       1-13_histogram_vertical < my_input_file

// I choose to count whitespace as zero lenght words. They are displayed with
// a single asterisk. If this is not the desired behavior, you can check for
// them and change the code to not include them in the array of counts.

// I have only done limited testing on this code. It runs but may still have
// some issues. Please report any that you find and pull requests are welcome.
// There are many ways to improve this coder. I tried to avoid some advanced
// methods, however, some things like the ioctl() and a function ro handle
// printing have been used for simplicity.
// malloc() was used to allow for defining the number of columns at runtime.

// I defined a hard limit to the height of each bar as a sanity check to
// prevent extremely large values for scrolling endlessly. It is possible that
// this is masking some issues in the code with bounds limits. I made the
// decision not to spend more time on it to see if this is the case.
#define HEIGHT_LIMIT 100

int print_screen(int *counts, int num_columns, int screen)
{
   /** Debug code
   for (int i = 0; i < num_columns -1; i++)
   {

      if (i == num_columns - 1)   // The last column
      {
         printf("%d\n", counts[i]);
      }
      else                       // all other columns
      {
         printf("%d:", counts[i]);
      };
   };          
   End debug code **/


   int max_height = 0;  // the maximum size of a vertical bar on current screen 
   // Get the size of the tallest bar.
   for (int i = 0; i <= num_columns - 1; i++) 
   {
      // Set the max height to HEIGHT_LIMIT as a sanity check
      if ((counts[i] > max_height) && (counts[i] <= HEIGHT_LIMIT))
      {
         max_height = counts[i];
      };
   };
   
   // Print the bars
   // Print each bar that is at least as high as the current height
   for (int cur_height = max_height; cur_height >= 0; cur_height--)
   {
      // Build a string to print
      for (int i_col = 0; i_col <= num_columns - 1; i_col++)
      {
         if (counts[i_col] >= cur_height)
            {
               putchar('*');
            }
         else
            {
               putchar(' ');
            };
      };
      putchar('\n');
   };
   printf("Screen: %d\n", screen);
   sleep(2);      // allow for enough time to see the output
   return(0);
}

int main()
{
   int c;               // input character
   int word_len = 0;    // length of the current word
   int cur_word = 0;    // which word on the current screen are we processing
   struct winsize w;    // struct for return data from ioctl(), terminal width
   int *counts;         // pointer to array of word length counts
   int screen = 0;      // which screen are we printing

   // Get the terminal information - we want w.ws_col for terminal columns
   // If we get an error, terminate the program.
   // The most common cause of an error, is redirecting the output to a file
   // because the file does not have a number of columns, so ioctl() gets an 
   // error and the values in w are zeros. This does make manual debugging
   // quite difficult.
   if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != 0)
   {
      printf("Error calling ioctl()\nTerminating program.\n");
      exit(-1);
   };

   // Uncomment the following line, if you want to check the results
   // printf("Terminal width: %d columns\n", w.ws_col);
   // sleep(2);
   
   // If we do not get a valid number of columns, exit the program with an error
   if (w.ws_col == 0)
   {
      printf("Zero column display. Exiting program\n");
      exit(-1);
   };
   
   // Allocate space for the word counts, one screen width at a time.
   // This space will be reused for each page of information.
   counts = (int *) malloc(w.ws_col + 1);
   memset(counts, 0, w.ws_col + 1); // Initialize the memory

   while ((c = getchar()) != EOF)
   {
      if (isgraph(c))   // check for any printable character except space
      {
         word_len++;    //    if printable/non-space, increment character count
      } 
      else              //    else increment the word and see if ready to print
      {
         counts[cur_word] = word_len;
         cur_word++;    // increment to the next word
         word_len = 0;  // reset the word length for the next work

         if (cur_word >= (w.ws_col - 1)) // See if we are ready to print 
         {
            print_screen(counts, cur_word, ++screen);
            cur_word = 0;  // reset the current word to start next screen
            memset(counts, 0, w.ws_col); // reinit the mem for next screen
         };
      };
   };
   
   // We only get here when we have read the EOF
   // Print the last screen (first screen, if there is only one screen)
   print_screen(counts, cur_word, ++screen);
   
   // Cleanup
   free(counts);
}
