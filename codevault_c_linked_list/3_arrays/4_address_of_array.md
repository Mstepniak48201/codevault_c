# The Address of an Array

- How to get the address of a variable:

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x = 15;
  
  printf("value = %d\n", x);
  printf("address = %p\n", &x);
}
```

- Now suppose that instead of an int value there is an array of characters like so:

```
// 1"6 character string.
char str[16] = "Example string";

printf("Value: %s\n", str);
```  
  |  
The above code prints out "Value: Example String"

- Now suppose that instead of trying to bring the address of `int x` that the function needs to print the address of the array `char str`.  
  |  
What about doing it like this?  

  ```
  printf("Address %p\n", &str);  
  ```  
  |  
It definitely prints an address, but the problem that becomes apparent is that the name of the variable, `str` should have degraded to a pointer already: it should already be the address of the first element int the array!
  |  
And if I try `printf("Address %p\n", str)` I get the same exact address in memory as when I use the `&` address operator.

- This is because the compiler is interpreting the identifier str as having decayed to a pointer. No matter what, str will mean "The address of the element at str[0]."  

**So: when passed as a pointer `%p` to printf(), `str`, `&str[0]` and `&str` all return the same result: the place in memory where the first element in the string lives.**

***WHERE THINGS GET WEIRD***   
**What does the address &str mean?**  
  |  
  `&str`: str doesn't decay into a pointer when preceeded by the `&` operator! This changes its value.

It's weird, because the same value results from it (the address to the first element in the array), but its *type* is:  
  |  
`pointer to char array of 16 characters`.  
  |  
How can this be ascertained???

- In the first two calls, `str` has decayed to a pointer to the first element in the array, which is 1 byte:  
  |  
  So, when printing the address, the differenc between `str` and `str + 1` are 1 byte.

- In the third call, `&str` is actually of type `pointer to array of 16 chars`.  
  |  
  This means 16 bytes this time, which in hexadecimal is 10.  
  |  
  So the third print statement will have a value 10 greater than the first call of printf().

- the identifier will also not decay into a pointer when passed to `sizeof()`.

```
// str -> pointer to str[0], which is 1 byte
printf("Address: %p\n", str);

// str + 1 -> pointer to str[1], one byte more than str[0]
printf("Address: %p\n", str + 1);

// &str + 1 -> pointer to array of 16 1 byte chars + pointer to array of 16 1 byte chars
printf("Address: %p\n", &str + 1);
```

# Address of an Array: In-Depth

Starter Code:  
```
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
  int arr[] = {5, 22, 17};

  return 0;
}
```

## Intro
- Clarify: take a look at memory structure when working with arrays

- Start with array of ints: create a function that prints every int.

**Write the Function and see how close I am**:  

```
#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, size_t count)
{
  int i;
  for (i = 0; i < count; i++)  
  {
    printf(arr[i]);
  }
}

int main (int argc, char * argv[])
{
  int arr[] = {5, 22, 17};
  size_t count = sizeof(arr);
  print_arr(arr, count);

  return 0;
}
```

## Passing a single element to a function that expects a pointer to array

```
int main(int argc, char *argv[])
{
  int el = 22;

  // Passing in &el, the address reference to int el
  // Within print_arr(), &el will be processed as `arr[i]`, in this case `arr[0]`
  // And `arr[0]` == *arr, dereferencing the referenced variable and accessing the value, 22.
  print_arr(&el, 1);
  return 0;
}
```

## Printing an Array of Strings

- Suppose that instead of an array of ints, there is an array of strings, like so: `{"example", "another one", "doing great!"}`

- Now there is an issue of how to declare the array of strings, and how to pass it to the function:  
  - The variable `arr` is an array of `char *`. When it is passed to the function, it decays to an array of `char **`
  - The address of the first element of that first element is of type `char **`.

**Takeaway**: `char *arr[]` is an *array of pointers*. This means that:
  - When it is passed to a function, it will decay to a pointer to the first element, which is of type `char *`
  - Therefore, a pointer to an element of type `char *` is a double pointer: `char **`
  - `char **` is a pointer to the first pointer (`char *`) that points to the first character in the first element in the array.
  - When dereferenced as `arr[0]` in the first iteration of the for loop, two things happen:
    - `**arr` is dereferenced to `*arr`, giving access to the address of the first element of arr, string "example" is in memory
    - `printf()`, when given `%s` as a parameter, expects a value of type `char *`:
      - `printf()` iterates over the null-terminated string stored at the address at `*arr[i]` and prints it to the console.

```
// Pass the array as a double pointer.
void print_arr(char **arr, size_t size)
{
  int i;
  for (i = 0; i < num; i++) 
  {
    // arr[0] == *arr -> "example"
    printf("%s\n", arr[i]);
  }
}

int main(int argc, char *argv[])
{
  // Declare as a char * array.
  char *arr = {"example", "another one", "doing great!"};

  // arr is an array of pointers to char, it decays to a pointer to the first pointer (which points to the first character).
  print_arr(arr, 3);

  return 0;
}
```

- Now, can I do the same trick where I print a single string as I did with the single int element?


```
int main(int argc, char *argv[])
{
  char *el = "example";

  // Passing in &el, the address reference to int el
  // Within print_arr(), &el will be processed as `arr[i]`, in this case `arr[0]`
  // And `arr[0]` == *arr, dereferencing the referenced variable and accessing the value, 22.
  print_arr(&el, 1);
  return 0;
}
```

## The Stack

Midway through the test on whether it is possible to print out a single element stored in a `char *` variable, he begins to discuss the stack, saying:

"Remember these are not actually stored in the stack, we are storing them in the read-only memory for strings. But we have an array of character pointers that point to a place in memory that just stores character after character.

In memory, how does this look like: if this was the beginning of the stack:"

```
// This is a theoretical stack. The current structure uses read-only memory, not on the stack.

// -- begin stack
// ... other things between the beginning and the array
// arr[] - What are we storing here, exactly? --> Pointers to strings:
// 8 byte - char* - arr[0]
// 8 byte - char* - arr[1]
// 8 byte - char* - arr[2]
// ... other things between array and end of stack
//  end of stack
```

Now suppose the following:
```
int main(int argc, char *argv[])
{
  char el[7] = "example";

  print_arr(&el, 1);
  return 0;
}
```
The above does not work -> it seems like it should:  
  - `el` is an identifier that decays to a pointer to the first char in "example".
  - Does the `&` address operator indicate that this is a double pointer passed to the function?
    |  
    No! `el` and `&el` are the same thing.

**Trying to Make Sense of it**:  
  - Is an array of strings multidimensional char  array, and this is a single dimension?

  - `char el[7] = "example"`  
      |  
      `el` -> decays to a pointer to `el[0]` -> "e".  
      |  
      Why is &el not of type `char **`? Why isn't it a double pointer?

  - There doesn't seem to be anything else to point to.  
    |  
    `el` has decayed to a pointer to the first character in the string "example"
    |  
    Since `el` is the same exact thing as `&el`, the only way to make this a double pointer would be `&&el`.  
    |  
    And this doesn't make any sense: `&el[0]` is a value that doesn't have a place in memory. It isn't stored anywhere.  
    |       |  
    |       `&el` is just being passed to the function! This isn't a variable inside memory.  
    |  
    Therefore, there is no address to reference!

**So, Passing `&el` when `char el[7] = "exampele"` DOESN'T WORK.**  
**How can it be made to work??**  
- It must be stored in a variable, and have an actual address where it lives in memory, like so:

```
int main(int argc, char *argv[])
{
  char el[7] = "example";
  char *ref = &el[0];

  print_array(&ref, 1);
  return 0;
}
```

- Now what happens? -->
  - `&ref` --> references `ref`, which is an address --> which references el[0]
  - So when `print_array()` dereferences the double pointer, it passes `*el` to `printf()`
  - `printf()` expects a pointer to char, as `%s` is the parameter, and it prints the entire string: "example".

**Takeaways**  
* Arrays are a continguous place in mememory where multiples of the same type are stored.

* If I need to get a reference to the place in memory at which an array is stored, I have to do that myself. I won't exist without being set equal to a variable.

