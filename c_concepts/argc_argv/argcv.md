#Understanding argc and argv

## Vocabulary  
- *null-terminated character array*: A string in C. This is an array of chars terminated by the null character "\0". From Geeks for Geeks:
  - The null character "\0" marks the end of the string.
  - C does not have a built-in string data type.
  - Strings are implemented using arrays of chars.
  
  - For example, the string "Geeks" would be like so: {"G", "e", "e", "k", "s" "\0"}

- *pointer*: a variable that stores *the memory address of another variable*. Suppose the following:

  ```
  // My variable
  int var = 10;

  // Pointer variable that stores the address of var
  int *ptr = &var;

  // Will print out the address at which the value of var is stored in memory, something like 7163804068 or such.
  printf("%p", ptr);
  ```

## argv[]
- argv[] is an array of pointers to null-terminated character arrays

- Accessing argv[]  
argv[i] gives the address in memory where the array at the given index is stored.

- The first entry in the argv array is a pointer to the name of the program running.

For example:  
```
#bash  
gcc my_program.c -o my_program
./my_program cmd1 cmd2 cmd3
```

- If the program accesses argv[2], the value is a pointer to the place in memory at which the array `{"c", "m", "d", "2", "\0"}` is stored.

- If the program accesses argv[0], the value is a pointer to the place in memory at which the array containing the char array that spells `my_program` is stored.























```
// The following code does nothing.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  return 0;
}
```

* argc: Argument Count  
* argv: Argument Vector  
  |  
  Vector: meaning, an Array  
    |  
    In order to use an Array, a Count is needed.

So, argc is the number of arguments contained in the argv[] array: the actual argument set of

```
int main(int argc, char *argv[])
```  
means that main() takes, as arguments, `<the number of arguments contained in the argv[] array>`, and `<>`





