# Why are Function Pointers Useful?

Suppose a program with two functions: sum() and prd():  
```
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Prototypes
int sum(int x, int y);
int prod(int x, int y);

int main(int argc, char *argv[])
{
  // Initialize the randomizer using the current timestamp as a seed.
  // time() is from the <time.h> header.
  srand(time(NULL));

  // Create two "random" numbers.
  int a = rand() % 100;
  int b = rand() % 100;

  printf("The result of the operation between  %d and %d is %d\n", a, b, sum(a, b)); 
  return 0;
}

int sum(int x, int y)
{
  return x + y;
}

int prod(int x, int y)
{
  return x * y;
}
```

- Suppose this code lives in a library somewhere, and I am importing it into a project, and I want to be able to change something. Speicifically, I want to be able to change the operation completecd in the printf() statement.

- In my original notes I had a difficult time following the logic in this part, and when I ended up understanding I wrote the following: "Okay, it was just a quirk of language, and honestly, an insightful way of looking at things. The function `should_not_be_changed()` is not being 'changed,' but instead will take a function as a parameter, and he is using pointers to do this." I thought it would be worth including here to remind myself that learning to communicate requires efforts made not just to be understood, but to understand others, and that concepts transcend languages.

- Move the randomizer, variables, and printf() statement into the new function `should_not_be_changed()`.

- next, add the parameters to the function: `should_not_be_changed(int (*operation) (int, int))`

- then, pass in `operation(a, b)` to the third parameter (the "result") of the `printf()` statement like so:  
  ```
  printf("The result of the operation between %d and %d is %d\n", a, b, operation(a, b)); 
  ```
  - This is cool.
  - Now `should_not_be_changed()` can swap out the function that performs the operation on `a` and `b`.

- Finally, call `should_not_be_changed()` in `main()`. Pass in either `&sum()` or `&prod()`.

```
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Prototypes
int sum(int x, int y);
int prod(int x, int y);
void should_not_be_changed((*operation)(int, int));

int main(int argc, char *argv[])
{
  should_not_be_changed(&sum);
  return 0;
}

int sum(int x, int y)
{
  return x + y;
}

int prod(int x, int y)
{
  return x * y;
}

void should_not_be_changed((*operation)(int, int))
{
  srand(time(NULL));

  int a = rand() % 100;
  int b = rand() % 100;

  printf("The result of the operation between  %d and %d is %d\n", a, b, operation(a, b)); 
}
```
