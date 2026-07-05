#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n = 16;
  
  // Use the pointer declarator (*) to set `p` equal to the address at which the value of `n` is stored.
  // This sets the type of p to `int pointer`, getting a reference to the address.
  int *p = &n;

  printf("The initial value of n: %d\n", n);
  printf("The initial value of pointer to n: %d\n", *p);

  // Use the referencing operator (*) to dereference to the address at which the value of 'n' is a stored.
  // This accesses the *value* stored at the address and allows the program to change that value.
  *p = 17;
  printf("The new value of n: %d\n", n);
  printf("The new value of pointer to n: %d\n", *p);
  return 0;
}
