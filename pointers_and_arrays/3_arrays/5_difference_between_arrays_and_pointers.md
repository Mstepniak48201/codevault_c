# The Difference Between Arrays and Pointers

- **In the code below, what is the difference between using bracket notation to instantiate an array and using a pointer to initialize a dynamically allocated array?**

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, 3};

  int *p = malloc(3 * sizeof(int));
  p[0] = 1;
  p[1] = 2;
  p[2] = 3;

  return 0;
}
```

The two arrays above,`arr` and `p` respectively, are essentially the same thing in memory. Besides the fact that `p` is dynamically allocated, what is different about them?

## Similarities:  
- Both are allocated blocks of memory 12 bytes long (3 4-byte integers)

## Differences:
- They are referred to differently:  
  - `arr` is an array identifier, and `p` is a pointer.

*But*: `arr` will decay to a pointer in most cases, and can be referred to as a pointer by using the following:

  ```
  // arr decays to a pointer, and is implicity cast to an int pointer variable.
  int *arrp = arr;
  ```

* Are there differences in what I can and cannot do with `arr` and `p`?

- Cannot use bracket notation to define *dynamically allocated arrays*:  
  |  
  Bracket notation has the property of *allocating memory*  
  |  
  Behind the scenes, the compiler reads `int arr[] = {1, 2, 3}` as "an array of 3 integers."  
  |  
  Bracket notation is syntactic sugar for initializing an statically allocated array.

- A pointer *doesn't allocate memory all by itself*.  
  |  
  In the case of `p` the memory is allocated dynamically by `malloc()`.  

- Suppose I run the program with a print statement like so, two addresses will print out.

```
printf("%p %p\n", arr, p);
```

- Remember, pointers have the property of, when added to like so: `p + 1`, where this really means `p + 1 * sizeof(data_type)`

- So if I change p like so, the print statement will reflect the change, and add 4 bytes:

```
p = p + 1;
printf("%p %p\n", arr, p);
```

- But, if I try to do the same thing to arr: `arr + 1`, the program will not compile, and it will give an error, as *I cannot assign another value to the statically allocated array*.

**But: Can I Get a Pointer to a Statically Allocated Array and Add to That?**

```
int arr[] = {1, 2, 3};

// arr decays to a pointer. setting the pointer equal to the identifier is copying the address.
int *arrp = arr;

// Because arr is, functionally, an address, it can be added to!
arrp = arr + 1;
```

## A Reminder on sizeof() and Array Identifiers!

- Suppose the following:

```
printf("%llu %llu\n", arr, p);
```

**The printout will be: 12 8**  
- This is because array identifiers *do not* decay to a pointer when passed to `sizeof()`!
  - arr is allocated to 12 bytes
  - p is literally a pointer, so it is 8 bytes.
 






