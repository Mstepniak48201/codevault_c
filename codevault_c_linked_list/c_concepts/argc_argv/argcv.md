#Understanding argc and argv

## Vocabulary  
- *null-terminated character array*: A string in C. This is an array of chars terminated by the null character "\0". From Geeks for Geeks:
  - The null character "\0" marks the end of the string.
  - C does not have a built-in string data type.
  - Strings are implemented using arrays of chars.
  
  - For example, the string "Geeks" would be like so: {"G", "e", "e", "k", "s" "\0"}


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





