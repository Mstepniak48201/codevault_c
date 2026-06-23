# What are Variadic Functions

## What are those, and how can we use them?

Starter Code  
```
#include <stdio.h>
#include <stdlib.h>

// Prototypes
int sum(int a, int b, int c);

int main(int argc, char argv[])
{
  printf("Sum is: %d\n", sum(1, 2, 3));
  return 0;
}

int sum(int a, int b, int c)
{
  return a + b + c;
}
```

- What if I want to pass another parameter? I can't just pass it to the function call like `sum(1 ,2 ,3 ,4)` because this is not going to compile. I could rewrite `sum()` to take an array like so: `sum(int arr[])` but what I want is an array that can take any number of arguments.

- `printf()` is an example of a variadic function. I can pass as many arguments as I want.

## Using stdarg.h and `va_arg`

- First, include `<stdarg.h>` in the headers.

- Next, add `int count` and the ellipsis operator `...` as a parameters to the function.

- Then, define and name `va_list` at the top of the `sum()` function, This is where the arguments will be stored. In this example, `va_list` will be named `args`.

- Then, initialize `va_list` using `va_start()` -> `va_start()` takes the `va_list` variable (`args`, in this case) and the first parameter in the function, `count`.

- Use the `count` parameter to iterate over the `args` list with a for loop.

- In the for loop, use `va_arg()` -> `va_arg()` takes two parameters: the `args` list, and the type to expect from each argument, like so; `va_arg(args, int)`.

- `va_arg()` does a few things:
  - looks at the current parameter being iterated over, and looks at the type
  - In this case, the type is `int` so `va_arg()` looks at the *current 4 bytes*.
  - It treats those 4 bytes as an integer and returns it to a variable that is set equal to it.
  - There is a pointer to `va_list` and with each iteration, `va_arg()` points to the *next 4 bytes*.

- Finally, call `va_end()` before the return statement of the function.

```
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Add `int count` the ellipsis operator `...` as a parameter.
int sum(int count, ...)

int main(int argc, char argv[])
{
  printf("Sum is: %d\n", sum(1, 2, 3));
  return 0;
}

int sum(int count, ...)
{
  // Define va_list and name it: This is where the arguments are stored.
  va_list = args;

  // Initialize va_list by calling va_start().
  // va_start() takes in the va_list variable and the first parameter of the function as arguments.
  va_start(args, count);

  // Sum variable
  int s = 0;

  // Iterate over the args list
  int i;
  for (i = 0; i < count; i++)
  {
    // Set variable x equal to va_arg(args, int) 
    int x = va_arg(args, int);
    s += x;
  }

  // Call va_end().
  va_end();
  return s;
}
```

# Is There a Work-Around to Passing the `count` variable as the First Argument to `va_start()`?

- Instead of passing in the number of arguments, pass in `NULL` and use a while loop.

- This is not safe to use for integers: if  0 is passed in, the program can terminate early since NULL == 0.

- So this method is better for chars.

`--------------------------------------------------------------------------------------------------------------`

- First, change the first parameter from count to `n`: this integer will be *part of the sum*:
  - Initialize the variable `s` to `n`.

- Next, move the declaration and initialization of `int x` outside of the loop.

- Delete the for loop and replace it with a while loop. Remember that `va_arg()` will look to the next item in the list -> set `x` equal to that next item *after* adding `x` to `s`.

- Last, when calling `sum2()` in `main()`, the final parameter must be `NULL`, like so: `sum2(1, 2, 3, 4, 5, 6, NULL)`.

```
while(x != NULL)
{
  s += x;
  x = va_arg(args, int);
}
```

```
int main(int argc, char *argv[])
{
  printf("Sum is: %d\n", sum2(1, 2, 3, 4, 5, 6, NULL));
  return 0;
}

int sum2(int n, ...)
{
  va_list = args;

  // As `n` is the first argument pased to the function, it must be the second parameter passed to `va_start()`.
  va_start(args, count);

  // Initialize s = n.
  int s = n;

  int i;
  
  // Move `int x` outside of the loop.
  int x = va_arg(args, int);
  while (x != NULL)
  {
    s += x;
    x = va_arg(args, int);
  }

  va_end();
  return s; 
}
```










