# How to Pass an Array as a Parameter to a Function

**Use a Pointer**

- It's time to write another sum() function! This one will add all the elements of an array and return the sum.

- While the instinct may be to pass in an array like so:
  |  
`int sum(int arr[], int count)`

**But**: The compiler degrades `arr[]` to a pointer to arr, which means that `int arr[]` is passed like so:
  |  
`int sum(int *arr, int count)`

## How Do We Know it's a pointer?

- In the below code, the function sum() takes in the parameter arr[]. 

- The function accesses arr[0], and changes its value to 100.

- But when the original array's first value is printed from within `main()`, the value is also altered. This means that the scope was not local to the function. It was not a copy of `arr` being altered, but the original, which means that the parameter `int arr[]` was pointing to the place in memory where the actual array lives.

```
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
```
