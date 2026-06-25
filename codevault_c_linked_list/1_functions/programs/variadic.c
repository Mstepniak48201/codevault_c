#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Prototypes
int sum(int count, ...);
// int chars(c, ...);

int main(int argc, char *argv[])
{
  printf("The sum is: %d\n", sum(3, 1, 2, 3));
  return 0;
}

// Use the ellipsis operator: this is where all other arguments will be entered after the first parameter.
int sum(int count, ...)
{
  // Define and initialize va_list from stdarg.h: these are the arguments passed in after the first parameter.
  va_list args;
  va_start(args, count);

  int sum = 0;

  int i;
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

  // End the process began with va_start() Be sure to add the list parameter (args) that the process started with.
  va_end(args);
  return sum;
}
