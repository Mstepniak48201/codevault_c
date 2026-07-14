#include <stdio.h>
#include <stdlib.h>

// To play with the error checker, try passing NULL as the value for the &sum or &prod parameters to sum_and_product() when it is being called and its value assigned to int status.

// Prototype
int sum_and_product(int a, int b, int *sum, int *prod);

int main(int argc, char argv[])
{
  int x = 5, y = 12, sum, prod;
  
  // int status = sum_and_product(x, y, NULL, &prod);
  int status = sum_and_product(x, y, &sum, &prod);

  if (status != 0)
  {
    printf("Something went wrong with the function. Error code %d\n", status);
  }
  else
  {
    printf("The sum is %d and the product is %d\n", sum, prod);
  }
  return 0; 
}

int sum_and_product(int a, int b, int *sum, int *prod)
{
  if (sum == NULL || prod == NULL)
  {
    return 1; 
  }
  *sum = a + b;
  *prod = a * b;
  return 0;
}


