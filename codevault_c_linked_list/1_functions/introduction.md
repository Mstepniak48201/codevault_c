# Introduction to functions

## Create an algorithm to get the 10th number in the Fibonacci Sequence

### Psuedo Code:
```
int n1 = 0
int n2 = 1

// Need a temp variable to store a value in?
int temp

// Already know the first 2 numbers in the 10 number sequence, so loop 8 times.
int i;
for (i = 0; i < 8; i++)
{
  // Shift the numbers to the right
  // n2 must become the current value of n1 + n2
  // n1 must become the old value of n2
  // So:
  
  // store current val of n2 in temp
  temp = n2
  
  // change value of n2 to current val of n1 + n2
  n2 = n1 + n2

  // change val of n1 to old val of n2
  n1 = temp
}

```

```
#include <stdio.h>
#include <stidlib.h>

int main(int argc, char *argv[])
{
  return 0;
}
```



