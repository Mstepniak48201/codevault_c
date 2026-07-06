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

  // Test: sizeof(arr) = 8 when called from sum()
  // This is because it is a pointer, and a pointer's size is 8 bytes.
  printf("Size of arr from sum() function: %llu\n", sizeof(arr));
  return result;
}

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int s = sum(arr, 7);
  printf("The Sum is: %d\n", s);
  printf("The value at arr[0]: %d\n", arr[0]);

  // Called from main(), sizeof(arr) is 28: it contains 7 4-byte integers.
  printf("Size of arr from main(): %llu\n", sizeof(arr));
  return 0;
}
