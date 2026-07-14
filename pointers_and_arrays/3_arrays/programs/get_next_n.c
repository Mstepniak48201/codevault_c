#include <stdio.h>
#include <stdlib.h>

// Parameters: start number x, number to get next n, pointer to array
// Array Subscript Operator [] dereferences the pointer to arr.
void get_next_n(int x, int next_n, int *arr)
{
  int i;
  for (i = 0; i < next_n; i++) 
  {
    arr[i] = i + x + 1;
  }
}

int main(int argc, char *argv)
{
  int x = 5;
  int next_n = 5;
  int arr[5];

  get_next_n(x, next_n, arr);

  int i;
  for (i = 0; i < next_n; i++)
  {
    printf("%d\n", arr[i]);
  }
  return 0;
}



