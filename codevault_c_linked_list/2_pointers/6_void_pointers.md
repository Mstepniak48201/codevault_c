# What are Void Pointers in C?

- In order for this module to be truly useful, some basic knowledge about hexadecimal formatting in C is needed:

`%x`:     Prints a number in hexadecimal

`%08x`:    Prints at least 8 characters wide, and pads with leading 0s.
    |  
    For example:  
    ```
    int x = 16;
    printf("%08x\n", x);

    // prints --> 00000016
    ```

**Why 8 Digits?**  
Suppose a function printing ints such as this:

`int x = 16;`

On a modern system, an int is 4 bytes (32 bits). Each hexadecimal digit is 4 bits:

`32 bits / 4 bits per hexadecimal digit = 8 hexadecimal digits`

**What changes when casting to a char pointer**  
Suppose the following recasting of `void *arr` to a `char *` array:  

  ``` 
  char *bytes = (char *)arr;  
  ```
    |  
When printing it, the same arithmetic needs to be taken into account:
    |  
    `char`: 1 byte (8 bits)  
      |  
      `8 bits / 4 bits per hexadecimal digit = 2 hexadecimal digits`  
      |  
      Therefore the print statement should be modified like so:  

      ```
      printf("%02x\n", bytes[i]);
      ```

**The Long and Short of it**

The length to print will depend on the data type: an int is 4 bytes (32 bits), while a char is 1 byte (8 bits). A hexidecimal digit is 4 bits, and the length required will depend on the data type.
       

- What is a void pointer? How can it be used? How is it different from a a char pointer?

**Starter Code**  
```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arr[] = {16, 31, 32, 65};
  return 0;
}
```

## A Problem to Solve: Take the array and print a hexidecimal representation.

### printf() and hexidecimal
- `printf("%08x\n", n)` --> "08" wherein the "0" says "pad with leading zeros instead of empty spaces," and "8" signifies a minimum width of 8 characters. "x" says "print the value `n` in lowercase letters a-f.

- `printf("%08x\n", n)` --> Wherein:  
  - "08":   "0" says "Where no value exists, pad with zeros instead of spaces."  
             |  
            "8" says "Minimum width of 8 characters."  
  - "x": says "print the value `n` in lowercase letters a-f.
   
- The function `print_bytes()` expects a pointer to an array of ints - remember that the name of the array variable, `arr` in this case, decays to a pointer so there is no need to add a prefix to it when passing it to the function when calling it in main.

```
#include <stdio.h>
#include <stdlib.h>

void print_bytes(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%08x\n", arr[i]);
  }
}

int main(int argc, char *argv[])
{
  int arr[] = {16, 31, 32, 65};
  print_bytes(arr, 4);
}
```

- The printout:  
```
00000010    
0000001f  
00000020  
00000041  
```

- Next, he does something that I'm not sure about. He changes the type of the array `arr` to `long long` and runs it:

```
// A long long has 8 bytes. This will be important later.
long long arr[] = {16, 31, 32, 65};
print_bytes(arr, 4);
```

I understand a `long long` is larger in size - maybe the printouts should be longer or in a different format? Either way, his printout remains as:

```
00000010    
0000001f  
00000020  
00000041  
```

Whereas my code won't even compile when I change the type. I suspect his IDE is doing some extra work, but I'm just using Vim and the terminal. I'm going to move on without getting into these specific weeds.

## Improving the Function to Take Any Type

In order to get the function to take input irrespective of type, the function will take a `void pointer` array.

- But, the code below will not compile. This is because the `printf()` statement is dereferencing the array with the array subscript operator, like so:  
  |  
```
// Remember, arr is a pointer, and bracket notation dereferences it!
printf("%08x\n", arr[i]) == printf("%08x\n", *(arr + i))
```

- The lecturer says: "We are not allowed to dereference a void pointer, because by definition, we don't know what it is. But, the key thing here is that we want that void pointer to be of size 1 when printed on the screen."
  |  
I think I understand in a bare-bones sort of way: He is about to cast the incoming array to a `char` type, and so each element in the array will be 1 byte. This will allow the function to view the memory as a sequence of 1-byte units.

```
#include <stdio.h>
#include <stdlib.h>

// Change the type of input to void pointer
void print_bytes(void *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%08x\n", arr[i]);
  }
}

int main(int argc, char *argv[])
{
  long long arr[] = {16, 31, 32, 65};
  print_bytes(arr, 4);
  return 0;
}
```

## Casting the void pointer array to char

**Syntax Note**  
The updated code that casts the void pointer array to a char array uses the following syntax:  

```
printf("%08x\n", ((char*)arr)[i]);
```

However, I have been using the GNU/K&R style. I find that for the way I see things, looking at  

`int *p` 

is more intuitive than

`int* p`

*Also*: I prefer to use named variables for my own clarity, and I don't mind having an extra line of code. With this in mind, I will be using the following syntax to cast the type of a pointer array:

```
char *bytes = (char *)arr;  
printf("%08x\n", bytes[i]);
```

```
#include <stdio.h>
#include <stdlib.h>

// Change the type of input to void pointer
void print_bytes(void *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    // Cast arr to a char type.
    char *bytes = (char *)arr;
    printf("%08x\n", bytes[i]);
  }
}

int main(int argc, char *argv[])
{  
  long long arr[] = {16, 31, 32, 65};
  print_bytes(arr, 4);
  return 0;
}
```

**The updated function ***still*** doesn't work! Why?**  
- First, we have to decide what we are printing. If we are printing one single byte, that means we are printing 2 base 16 digits. This means that the "8" needs to change to a "2", as the data type `int` was 4 bytes (32 bits), and the 4 bit hexadecimal digit required a length of 8. The char data type is 1 byte (8 bits) and 8 bits / 4 bit hexadecimal digit = 2. So:  

```
char *bytes = (char *)arr;
printf("%02x\n", bytes[i]);
```

- The next issue is the second parameter being passed to `print_bytes()`: `int n`. The type of arr being passed in is no longer the correct type, In `print_bytes()` the contents of the array are being cast to `char` and will be examined 1 byte at a time. If the type was to remain as `int` the function call would be `print_bytes(arr, 32)` but it is more precise to pass the data type to the parameter using `sizeof()` like so:

```
long long arr[] = {16, 31, 32, 65};
print_bytes(arr 4 * sizeof(long long));
```

***Important Module: Add and Subtract Arrays?***

## Advantages and Disadvantages

- `char *arr`: why not just use a char pointer? 
  - There are tradeoffs: a void pointer takes in *anything* which makes it a bit dangerous.
  - On the other hand, the void pointer can take in anything, which makes it useful.

