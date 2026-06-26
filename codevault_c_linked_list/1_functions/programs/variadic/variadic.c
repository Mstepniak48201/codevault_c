#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Prototypes
int sum(int count, ...);
void chars(char x, ...);
void my_chars(char c, char d);

int main(int argc, char *argv[])
{
  printf("The sum is: %d\n", sum(3, 1, 2, 3));
  chars('m', 'y', ' ', 'c', 'h', 'a', 'r', 's', '\0');
  my_chars('x', 'y');
  return 0;
}

// Use the ellipsis operator: this is where all other arguments will be entered after the first parameter.
int sum(int count, ...)
{
  // Define and initialize va_list from stdarg.h: these are the arguments passed in after the first parameter.
  va_list args;
  va_start(args, count);

  int sum = 0;

  int i = 0;
  for (i = 0; i < count; i++)
  {
    // In this case, `i` only controls the number of times the loop will run, based on the count parameter.
    // va_arg() takes two parameters: the args list, and the data type to expect for each argument.
    // In this case, the type passed to va_arg() is `int`, so va_arg() returns the value of the next 4 bytes.
    // At the same time, va_arg() points to *the next 4 bytes*
    // The next time va_arg() is called, it returns the value that it was pointing to and advances the pointer.
    int x = va_arg(args, int);
    sum += x;
  }

  // End the process began with va_start()
  va_end(args);
  return sum;
}

// Using va_list in a different way: sentinel value instead of the `count` parameter.
// The method in the tutorial discussed using ints and terminating with NULL, but this could be a problem,
// since NULL = 0: a zero value passed to the function could cause it to exit earlier than intended.
// While there are certainly ways around this, I chose to adapt it to, instead of returning the sum of ints,
// to print a sequence of chars.
void chars(char x, ...)
{
  va_list args;
  va_start(args, x);
  char el = x;
  while (el != '\0')
  {
    // Remember that in C chars are ints that are 1 byte.
    // va_arg() promotes chars to ints -> If I try to call va_arg() with a char as the type input
    // it will result in an error. 
    // va_arg recognizes the char data type and promotes them to 4 byte ints.
    printf("%c", el);
    el = va_arg(args, int);
  }
  va_end(args);
  printf("\n");
}


void my_chars(char c, char d)
{
  printf("c: %c and d: %c\n", c, d);
}
