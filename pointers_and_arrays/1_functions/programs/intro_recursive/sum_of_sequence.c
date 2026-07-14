#include <stdlib.h>
#include <stdio.h>

// Prototypes
int sum(int n);

int main(int argc, char *argv[])
{
  int input = 4;
  int result = sum(input);
  printf("The sum of the numbers from 1-%d is %d\n", input, result);
  return 0;
}

int sum(int n)
{
  if (n < 0)
  {
    return 0; 
  }
  printf("Hello from sum() where n = %d\n", n);
  return n + sum(n - 1);
}
