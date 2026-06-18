# Introduction to functions

## Create an algorithm to get the 10th number in the Fibonacci Sequence
The Fibonacci Sequence goes like so:

- 0
- 1
- 1 (0 + 1)
- 2 (1 + 1)
- 3 (2 + 1)
- 5 (2 + 3)

And so on. The sequence starts with 0, 1, and then each number after is the result of adding the previous two numbers together.

### Psuedo Code:  
```
// Find the 10th number.  
// I already know the first two numbers so I need to find the next 8.

int temp
int n1 = 0
int n2 = 1

for (i = 0; i < 8; i++)  
// Find a way to "shift" the numbers, i.e. n1 becomes the current value of n2, and n2 becomes the sum of the current values of n1 + n2.
temp = n2
n2 = n1 + n2
n1 = temp
```

### fibonacci.c
```
#include <stdio.h>  
#include <stdlib.h>  

int main(int argc, char *argv[])
{
  int temp;  
  int n1 = 0;  
  int n2 = 1;  

  int i;  
  for (i = 0; i < 8; i++)  
  {    
    temp = n2;
    n2 = n1 + n2;  
    n1 = temp; 
  }

  printf("The 10th number in the Fibonacci Sequence is %i\n", n2);  
  return 0;
}
```



