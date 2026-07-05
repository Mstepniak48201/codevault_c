# Iterating Over an Array Using Pointers

- How can pointers be used to iterate over an array? Instead of a for loop?

1. How does `int arr[] = {7, 8, 9, 10, 11};` look in memory?

- Starter Code
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int arr[] = {7, 8, 9, 10, 11};

  // 1. How `arr` looks in memory:
  // Use the address operator `&` to get a reference to the place in memory where the given values exist.
  printf("Start address: %d\nEnd address: %d\n", &arr[0], &arr[4]);

  return 0;
}
```

**Function Printout**:  
Start address:  1306026912  
End address:    1306026928  

- The Start and End addresses are 16 bytes apart.
  - There are 5 integers, each 4 bytes
  - So imagine arr[0] is at an address of 0:
    - Addresses: 0, 4, 8, 12, 16

- Knowing this makes it possible to iterate over an array using a pointer.

```
int arr[] = {7, 8, 9, 10, 11};

int *p;

// C automatically does the pointer arithmetic, and knows that `p++` is p + 1 * sizeof(data_type)
for (p = &arr[0]; p <= arr[4]; p++)
{
  // Here, p = the address of the current element.
  // `*` is now the dereferencing operator, accessing the value at the address.
  printf("%d ", *p);
}
```
