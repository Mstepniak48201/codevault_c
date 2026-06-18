# Introduction to functions

## Syntax Note
- I will use Allman syntax (curly braces on separate lines) because I like it.
- The tutorial using the following syntax for pointers:

```
int main(int argc, char* argv[])
```

But GNU's syntax makes more sense to me. Understanding that argv[] is an array of pointers that point to chars, placing the * before argv[] is more intuitive to me personally:

```
int main(int argc, char *argv[])
```

## Get the 10th number in the Fibonacci Sequence

The nth number in the Fibonacci Sequence:

- 0
- 1
- 1   (0 + 1)
- 2   (1 + 1)
- 3   (1 + 2)
- 5   (2 + 3)
- 8   (3 + 5)
- 13  (5 + 8)
- 21  (8 + 13)
- 34  (13 + 21)

Because I know the first two numbers of the sequence, and I want the tenth number, I need to loop 8 times.

```
int main(int argc, char *argv)
{
  int num_1 = 0;
  int num_2 = 1; 
  int temp;

  int i;
  for (i = 0; i < 8; i++)
  {
    temp = num_2;
    num_2 = num_1 + num_2;
    num_1 = temp; 
  }

  printf("%d\n", num_2);
  return 0;
}
```

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

* LEFT OFF AT 3:23


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



