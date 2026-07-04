#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int arr1[] = {2 ,1};
  int arr2[] = {1, 2};

  int memcmp_output = memcmp(arr1, arr2, 2 * sizeof(int));

  // memcmp() return depends on the comparison of the first element of the arrays.
  // If arr1[0] > arr2[0], memcmp() outputs a number > 0.
  // If arr1[0] < arr2[0], memcmp() outputs a number < 0.
  printf("memcmp() output: %d\n", memcmp_output);

  if (memcmp(arr1, arr2, 2 * sizeof(int)) == 0)
  {
    printf("Arrays are the same\n");
  }
  else
  {
    printf("Arrays are not the same\n");
  }
 
  return 0;
}
