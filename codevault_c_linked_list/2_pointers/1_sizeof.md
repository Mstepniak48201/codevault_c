# The `sizeof()` Operator

- What does `sizeof()` do? It returns the number of bytes in a specific type.

- Use `sizeof()` to find the size of an int:

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // Check the size of an int
  printf("%d\n", sizeof(int));


  // Check the size of a specific int
  int x = 5;
  printf("%d\n", sizeof(x));
  return 0;
}
```

Both of the above print statements will return 4, as each int as 4 bytes.

## Format Specifier
- `sizeof()` returns a `size_t` data type. I have added `size_t` to the project map and will go into it in more depth in the near future.

- For now, when printing `sizeof()` I will be using %llu (long-long unsigned integer) in accordance with the tutorial like so:

```
printf("%llu\n", sizeof(int));
```

## Using sizeof() with arrays

- Arrays usually decay into pointers. So:

- It might seem like, in the following, that when `arr` is passed to `sizeof(arr)`, that arr would decay to a pointer.

- In this case it would be an `int*` which has a size of 8 bytes. But when the value is printed, the value is 12, which is the value of the 3 ints within the array.

- This is because `sizeof()` is built in such as way where arrays do not decay into pointers.
```
int main(int argc, char *argv[])
{
  int arr[3] = {3, 9, 10}; 
  printf("%llu\n", sizeof(arr));
  return 0;
}
```

- This means that `sizeof()` can be used to find the length of an array, like so:

```
int arr[3] = {1 ,2 ,3};
int length = sizeof(arr) / sizeof(int);
```

- `sizeof()` can also be used to get the size of `size_t`:

```
// sizeof(int) returns a value of type `size_t` and then sizeof() gets the size of `size_t` data type.
printf("%llu\n", sizeof(sizeof(int)));
```






