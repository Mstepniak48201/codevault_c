#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arr[] = {7, 8, 9, 10, 11};
  int n = 5;
  
  printf("Printing values with an indexed for loop:\n");
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  printf("Start address: %d\nEnd address: %d\n", &arr[0], &arr[4]);
  printf("\n");
  printf("Printing values with pointers in increments of bytes:\n");
  
  int *p;

  // Use the address operator & to get a reference to the address of arr[0]
  // C automatically knows that p++ == p + 1 * sizeof(data_type)
  for (p = &arr[0]; p <= &arr[4]; p++)
  {
    // Dereference p using the dereferencing operator: *p
    printf("%d ", *p);
  }
  printf("\n");
 
  return 0;
}
