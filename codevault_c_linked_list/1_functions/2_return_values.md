# Return Values from a Function

## Return a Value from a Function

A function name is preceded by its return type: int, void, etc. "void" indicates that the function doesn't have a return value.

The following function has no return value. Rather, it prints a result.
```
void fibo(int num)
{
  int count = num - 2;
  int n1 = 0;
  int n2 = 1;
  int temp;

  int i;
  for (i = 0; i < count; i++)
  {
    temp = n2;
    n2 = n1 + n2;
    n1 = temp;
  }

  printf("The %d number in the sequence isw %d\n", num, n2);
}
```

However, if fibo() is given a type of "int," it must have a return value.
```
int fibo(int num)
{
  int count = num - 2; int n1 = 0;
  int n2 = 1;
  int temp;

  int i;
  for (i = 0; i < count; i++)
  {
    temp = n2;
    n2 = n1 + n2;
    n1 = temp;
  }

  return n2;
}
```

Now fibo() returns a value that can be stored inside a variable and used:

```
int main(int argc, char *argv[])
{
  int num5 = fibo(5);
  printf("The fifth number in the sequence is %d\n", num5);
  return 0;
}
```

## Returning Multiple Values from a Function

- Goal: Use pointers to return the sum of `a + b` *and* the product of `a * b` from a single function

```
#include <stdio.h>
#include <stdlib.h>

// Prototypes
// int *sum and int *prod: the "*" tells the function to expect a pointer to int:
// which is the address at which the int is located.
void sum_and_product(int a, int b, int *sum, int *prod);

int main(int argc, char argv[])
{
  // Define the inputs x and y, as well as the sum and prod variables.
  int x = 5, y = 12, sum, prod;

  // Use the "&var" syntax to pass in the inputs and the pointers to sum and prod into the function.
  sum_and_product(x, y, &sum, &prod);

  printf("The sum is %d and the product is %d\n", sum, prod);

  return 0;
}

void sum_and_product(int a, int b, int *sum, int *prod)
{
  *sum = a + b;
  *prod = a * b;
}
```

### How the Pointer Syntax Works
1. In `main()`, the variables `sum` and `prod` are declared as ints.

2. Whe `sum_and_product()` is declared, it takes `int *sum` and `int *prod` as parameters. The `*` placed before the variable name lets the function know that the args will be pointers to int variables - the address at which the ints are stored, rather than the ints themselves.

3. When `sum_and_product()` is called in `main()`, a `&` is placed before the `sum` and `prod` variable names. This passes in the pointers to the variables, the *addresses* of the variables, not their values.

4. Within `sum_and_product()` the pointer variables are accessed, and the values of `sum` and `prod` are initialized to the args passed in.

### Note:
If I remember correctly, this will have to do with dereferencing. It's beena while, but I suspect I'm going to have an "oh yeahhhh" moment remembering exactly how this all works.

- Adding Error Codes  
In the tutorial, he is suggesting using 1 to mean success and 0 to mean error, but the convention I learned was that 0 should mean success, while any number greater than that would mean an error, and could be reserved for specific error codes. I'm sticking with this convention.

- To take this out for a spin, change the value of either ints x or y, as declared in `main()` to `NULL`. The error message should display!

- From my original notes, while watching this video for the first time:  
"I think this is a fun and elegant way of writing a function. The function directly alters two pre-existing variables, while it is called when it is set as the value for `int status`, and it's code is only executed if its status is 0."

```
// Modify sum_and_product() to return an int signifying success/error, and add error messaging to main()

#include <stdio.h>
#include <stdlib.h>

// Change the prototype of sum_and_product from void to int.
int sum_and_product(int a, int b, int *sum, int *prod);

int main(int argc, char argv[])
{
  int x = 5, y = 12, sum, prod;

  // Call sum_and_product by setting it equal to a variable that contains its return value.
  int status = sum_and_product(x, y, &sum, &prod);

  if (status != 0)
  {
    printf("Something went wrong in the function. Error code %d\n", status);
  }
  else
  {
    printf("The sum is %d and the product is %d\n", sum, prod);
  }

  return 0;
}

// Change sum_and_product() from a void to an int.
int sum_and_product(int a, int b, int *sum, int *prod)
{
  if (sum == NULL || prod == NULL)
  {
    return 1;
  }  

  *sum = a + b;
  *prod = a * b;
  return 0;
}
```


