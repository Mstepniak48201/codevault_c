#include <stdio.h>
#include <stdlib.h>

int sum(int arr[], int count)
{
  arr[0] = 100;
  int result = 0;
  int i;
  for (i = 0; i < count; i++)
  {
    result += arr[i];
  }
  return result;
}

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int s = sum(arr, 7);
  printf("The Sum is: %d\n", s);
  printf("The value at arr[0]: %d\n", arr[0]);
  return 0;
}
