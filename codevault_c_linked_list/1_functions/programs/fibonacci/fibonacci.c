#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n1 = 0;
  int n2 = 1; 
  int temp;

  int i = 0;
  for (i = 0; i < 8; i++)
  {
    temp = n2;
    n2 = n1 + n2;
    n1 = temp; 
  }

  printf("The value of the tenth number in the Fibonacci sequence is: %d\n", n2);
  return 0;
}

//void fibonacci();:q



