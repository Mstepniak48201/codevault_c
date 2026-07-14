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

- ***Takeaway***: Just use a pointer like so: `int sum(int *arr, int count)`

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

## Another proof, with sizeof()

- Add the following line to `sum()`, right before the return statement:
    |  
  `printf("Size of arr from sum() function: %llu\n", sizeof(arr));`

- And this line to `main()`, right before the return statement:
    |  
  `printf("Size of arr from main(): %llu\n", sizeof(arr));`

**Printout**:
Size of arr from sum() function: 8  
Size of arr from main(): 28  

- The reason why the size of `arr` when printed from the `sum()` function is 8 is because it is a pointer. Pointers are 8 bytes.

- The reason why the size of `arr` when printed from `main()` is 28 is because it is an array of 7 ints, and each int is 4 bytes.


