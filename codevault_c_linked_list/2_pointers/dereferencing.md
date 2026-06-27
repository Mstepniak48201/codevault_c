# Dereferencing

## Syntax
When placed before a variable that is not a pointer, the `*` is known as the "pointer declarator" and creates a reference to the place in memory where the value that is being pointed at resides. Like so:

```
// The value of a is 16.
int a = 16;

// The value of p is the address in memory where the data stored inside the variable a resides.
int *p = &a;
```

Again, I will be changing the style a bit, and placing the `*` before the variable instead of after the data type `int` for my own clarity.

## What Does Dereferencing Mean?  
When placed before a variable that represents a pointer, such as `p` in the above example, the `*` becomes the "referencing operator":

- The `*` works like a toggle: pointer declarator/referencing operator.

- The pointer declarator is part of the typing system. it signifies that the type of `p` is "int pointer."
  - Setting `&a` as the value of `p` gets a "reference" to the *address* of the value stored within the variable `int a`.

- When the syntax is repeated in the print statement `printf("%d\n", *p)` the `*` dereferences `p` from the address and provides access to the value at that address, which is currently 16.

```
int main(int argc, char argv[])
{
  int a = 16;
  
  int *p = &a;

  // In this case, p is not dereferenced. The printout will be the address, not a usable number.
  printf("%d\n", p);

  // Here, p is dereferenced, and the printout will be 16, which is the value stored at the address.
  printf("%d\n", *p)
  return 0;
}
```

## Using Dereferencing to Set a Value  
```
// The following uses a dereferenced pointer to alter the value at the address in memory.
int main(int argc, char *argv[])
{
  int a = 16;
  int *p = &a;
  printf("Initial value of a: %d\n", a);
  *p = 17
  printf("New value of a: %d\n", a);
  return 0;
}
```

## Array Subscript Operator

