#include <stdlib.h>
#include <stdio.h>

// Prototypes
int sum_of_digits(int n);

int main(int argc, char *argv[])
{
  int input = 12345;
  int result = sum_of_digits(input);
  printf("The sum of the digits in the number %d is %d\n", input, result);
  return 0;
}

int sum_of_digits(int n)
{
  if (n == 0)
  {
    return 0; 
  }
  // Remember the C rule that nobody tells you about when doing this type of problem: C truncates division of ints.
  // Therefore, 1234 / 10 != 1234.5, but instead it = 1234.
  // First addend: n % 10 -> This will get the final digit of n.
  // Second addend: recursive call of sum_of_digits(n / 10).
  printf("Hello from sum_of_digits() where n = %d\n", n);
  return n % 10 + sum_of_digits(n / 10) ;
}


