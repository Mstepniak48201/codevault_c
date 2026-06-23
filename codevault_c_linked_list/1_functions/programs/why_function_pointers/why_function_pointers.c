#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Prototypes
int sum(int x, int y);
int prod(int x, int y);
void should_not_be_changed(int (*operation)(int, int));

int main(int argc, char *argv[])
{
  // Try it out using pointers to both sum() and prod():
  printf("The result when calling sum():");
  should_not_be_changed(&sum);
  printf("The result when calling prod():");
  should_not_be_changed(&prod);
  return 0;
}

int sum(int x, int y)
{
  return x + y;
}

int prod(int x, int y)
{
  return x * y;
}

// Pass in a pointer to a function
void should_not_be_changed(int (*operation)(int, int))
{
  // Initialize randomizer using current timestamp as a seed.
  srand(time(NULL));

  // Create two "random" numbers:
  int a = rand() % 100;
  int b = rand() % 100;

  printf("The result of the operation between %d and %d is %d\n", a, b, operation(a, b));
}
