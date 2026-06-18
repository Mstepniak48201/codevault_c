#Understanding argc and argv

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





