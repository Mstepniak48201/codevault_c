#include <stdlib.h>
#include <stdio.h>

// Prototypes
int sum(int n);

int main(int argc, char *argv[])
{
  // Test odd number.
  int odd_input = 7;
  int odd_result = sum(odd_input);
  printf("The sum of odd numbers between 0 - %d is %d\n", odd_input, odd_result);


  // Test even number.
  int even_input = 8;
  int even_result = sum(even_input);
  printf("The sum of the even numbers between 0 - %d is %d\n", even_input, even_result);
  return 0;  
}

int sum(int n)
{
  int is_odd = n % 2;
  if (is_odd)
  {
    if (n < 1) 
    {
      return 0; 
    }
    printf("Hello from sum(n) where n = %d\n", n);
    return n + sum(n - 2);
  }
  else
  {
    if (n == 0) 
    {
      return 0; 
    }
    printf("Hello from sum(n) where n = %d\n", n);
    return n + sum(n - 2);
  }
}


