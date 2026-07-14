#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int arr1[] = {3, 4};
  int arr2[] = {1, 2};
  
  // initial values in arr1
  printf("arr1[] = {%d, %d}\n", arr1[0], arr1[1]);

  memcpy(arr1, arr2, 2 * sizeof(int));

  // changed values in arr1
  printf("arr1[] = {%d, %d}\n", arr1[0], arr1[1]);

  return 0;
}
