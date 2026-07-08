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
// 16 character string.
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





