#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n = 16;
  int *p = &n;

  printf("The initial value of n: %d\n", n);
  printf("The initial value of pointer to n: %d\n", *p);

  *p = 17;
  printf("The new value of n: %d\n", n);
  printf("The new value of pointer to n: %d\n", *p);
  return 0;
}
