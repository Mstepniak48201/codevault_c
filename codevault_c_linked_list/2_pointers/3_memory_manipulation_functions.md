# Memory Manipulation Functions: `memcmp()` | `memcpy()` | `memset()`

**Starter Code**  
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int arr1[] = {1, 2};
  int arr2[] = {1, 2};

  return 0;
}
```

## Using Memory Manipulation and Comparison Functions to Compare Two Arrays

- The functions that will be used are contained in `string.h`.

## `memcmp()`

- `memcmp()`: is similar to `strcmp()` in that it compares strings, but it takes **void pointers** as an input, and doesn't give any warning to indicate if something else has been passed in.

- Parameters: void pointer to array, void pointer to array, depth of comparison (*size of the smallest array*)

  `memcmp(arr1, arr2, n * sizeof(data_type))`

- **Important** Although `memcmp()` takes void pointers, those two pointers must be of the same type, as `memcmp()` is examining the arrays 1 byte at a time. So a `long long` and an `int` that both contain {1, 2} would not be recognized as equal by the function.

- **Return Value:**  
  - if arr1[0] > arr2[0], memcmp() returns a value > 0.
  - if arr1[0] < arr2[0], memcmp() returns a value < 0.
  - if arr1[0] == arr2[0], memcmp() returns 0.

**So:**
```
int main(int argc, char *argv[])
{
  int arr1[] = {1, 2};
  int arr2[] = {1, 2};

  // memcmp(void_pointer_to_arr, void_pointer_to_arr, (n * sizeof(data_type)))
  if (memcmp(arr1, arr2, 2 * sizeof(int)) == 0)
  {
    printf("Arrays are the same.\n");
  }
  else
  {
    printf("Arrays are not the same.\n");
  }

  return 0;
}
```

## `memcpy()`

- Suppose the following arrays. They are different, but the goal is to make them the same. How can one be copied on top of the other without doing a for loop?

```
int arr1[] = {3, 4};
int arr2[] = {1, 2};
```

- Parameters: destination array, source array, depth to copy *in bytes*:

  `memcpy(array_copy_to, array_copy_from, n * sizeof(data_type))`

So:

```
int arr1[] = {3, 4};
int arr2[] = {1, 2};

memcpy(arr1, arr2, 2 * sizeof(int));
printf("arr1[] = {%d, %d}\n", arr1[0], arr1[1]);
```

## `memset()`
- The section on `memset()` is sparse, I suspect, because this is an introduction to the concept. `memset()` will come up again and again.
- Use Case: zeroing out arrays -> initializing structs, clearing buffers, preparing arrays for reuse
- There will be more advanced use cases, and it sounds like `memset()` is pretty core to C.

- Sets every single byte in an array to a value
- Parameters: void pointer to array, value, depth to set, in bytes

- This one gets tricky, as it has unexpected interactions with printf

```
int arr1[] = {3, 4};
int arr2[] = {1, 2};

memcpy(arr1, 0, 2 * sizeof(int));
```
