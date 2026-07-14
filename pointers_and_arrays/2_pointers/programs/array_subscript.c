#include <stdio.h>
#include <stdlib.h>

// Prototypes
void array_subscript(int *arr, int i);


int main(int argc, char *argv[])
{
  int arr[] = {5, 13, 22};
  int *p = arr;
  int i = 1;
  
  // The variable name "arr" decays into a pointer (address) of the first element of the array.
  printf("The address of the first element of arr[] is %p\n", p);

  // Dereferencing it provides the actual element.
  printf("The first element of the array is %d\n", *p);

  // Remember that `n` is an int pointer, and doesn't need the pointer declarator `*`.
  array_subscript(p, i);
  return 0;
}

void array_subscript(int *arr, int i)
{
  printf("\nFunction call: array_subscript():\n");
  printf("The %dth element of the array is %d\n", i + 1, *(arr + i));
  printf("The address of the %dth element of the array is %p\n", i + 1, arr + i);

}

