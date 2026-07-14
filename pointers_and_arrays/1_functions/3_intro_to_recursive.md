# Intro to Recursive Functions

- Suppose the following:

```
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Prototypes
void f();
void g();

int main(int argc, char *argv[])
{
  f();
  g();
  return 0;
}

void f()
{
  printf("hello from f\n");
}

void g()
{
  printf("hello from g\n");
}
```

- Now suppose `g()` needs to be called from `f()`. The following code prints the same thing to the terminal as the previous code:

```
int main(int argc, char *argv[])
{
  f();
  return 0;
}

void g()
{
  printf("hello from g\n");
}

void f()
{
  printf("hello from f\n");
  g();
}
```

- But what if `f()` is called from within itself?

```
void f()
{
  printf("hello from f\n");
  f();
}
```

- `f()` is a recursive function that never stops calling itself, until it crashes the program. 

- Suppose `f()` takes a parameter, and does operations on that parameter, recursively:

```
int main(int argc, char *argv[])
{
  f(20);
  return 0;
}

void f(int x)
{
  printf("hello from f with x = %d\n", x);
  f(x - 1);
}
```

- The function still continues until the program crashes, but this time, the value of `x` changes with each recursive call. The intial call passes in 20, but each subsequent call of `f()` decrements `x` by 1.

## Exit Condition

```
void f(int x)
{
  if (x < 0)
  {
    return;
  }
  printf("hello from f with x = %d\n", x);
  f(x - 1);
}
```

## Return a value

- Start with the following:

```
int main(int argc, char *argv[])
{
  int result = f(20);
  printf("The result of calling f() is %d\n", result);
  return 0;
}

int f(int x)
(
  if (x < 0)
  {
    return 0;
  }
  printf("Hello from f with x = %d\n", x);
  return f(x - 1);
)
```

- The above code will always have a value of 0 when set equal to a variable and called in main(). The recursive call will decrement x until it is worth less than 0 and if statement at the beginning returns `0`.


## Recursive Sum Function

- Write a function that, given a number `n`, sums up all the numbers between 1-n.

- For example sum(4) => 1 + 2 + 3 + 4.

```
#include <stdio.h>
#include <stdlib.h>

// Prototypes
int sum(int n);

int main(int argc, char *argv[])
{
  int input = 4;
  int result = sum(input);
  printf("The sum of the numbers from 1-%d is %d\n", input, result);
  result;
}

int sum(int n)
{
  if (n < 0)
  {
    return 0;
  }
  printf("Hello from f with n = %d\n");
  return n + sum(n - 1);
}
```

- What is Happening?

- Function call:
  - n = 4, not < 0, passes Exit Condition
  - prints "Hello from f with n = 4"
  - return 4 + sum(4 - 1)
    - 1st Recursive Call: returns 3 + sum(3 - 1)
      - 2nd Recursive Call: returns 2 + sum(2 - 1) 
        - 3rd Recursive Call: returns 1 + sum(1 - 1)
          - 4th Recursive Call: returns 0 + sum (0 - 1)
            - 5th Recursive Call: n < 0, Exit condition met
    - return 4 + 3 + 2 + 1 is what remains after the Exit condition is met.

- Another view:
  - Function call:
  - return n + sum(n-1) == 4 + sum(4-1) == 4 + sum(3)  
    |           |  
    |           return 3 + sum(2)  
    |           |           |  
    |           |           return 2 + sum(1)  
    |           |           |           |  
    |           |           |           return 1 + sum(0)  
    |           |           |           |           |  
    |           |           |           |           return 0 + sum(-1)  
    |           |           |           |           |           |  
    |           |           |           |           |           return 0  
    |           |           |           |           |           |  
    4     +     3     +     2     +     1     +     0     +     0

  - Or: 4 + (3 + (2 + (1 + (0 + 0))))

  



