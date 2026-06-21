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
