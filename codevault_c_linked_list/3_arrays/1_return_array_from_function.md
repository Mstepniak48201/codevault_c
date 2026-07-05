# Return Array From a Function

- Write a function that gets the next five integers after int n

- I cannot write a function that returns an array.
- `return arr` at the bottom of a function would mean `return the address of the array created *within* this function`.
  | 
`arr` would exist only as a local variable in the stack, and when the function returns, the place in which it is stored has its memory deallocated.  
  |  
If a function tried to return a local array, it would return *an address to something that no longer exists*.

**How to fix this**
- Write a void function that affects external values.
- Parameters: number `n` used to populate the array, pointer to int array

- Remember: the array variable name decays into a pointer to the first element of the array, but the Array Subscript Operator [] dereferences it!

```
#include <stdio.h>
#include <stdlib.h>

void get_next_five(int n, int *result)
{
  int i;
  
  for (i = 0; i < 5; i++)
  {
    // Array Subscript Operator [] dereferences the pointer.
    result[i] = n + i + 1;
  }
}

int main(int argc, char *argv[])
{
  int x = 5;
  int arr[5];

  get_next_five(x, arr);

  int i;
  for (i = 0; i < 5; i++)
  {
    printf("%d\n", arr[i]);
  }

  return 0;
}
```
