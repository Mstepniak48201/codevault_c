# Dereferencing

## Syntax
When placed before a variable that is not a pointer, the `*` is known as the "pointer declarator" and creates a reference to the place in memory where the value that is being pointed at resides. Like so:

The `&` is the "address-of operator." It literally produces an address, like so:

```
// The value of a is 16.
int a = 16;

// The value of p is the address in memory where the data stored inside the variable a resides.
// The `&` symbol, the address-of operator, produces the address of a to set equal to the pointer.
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
  printf("The value of *p: %d\n", *p);
  return 0;
}
```

## Array Subscript Operator

### How Does an Array Behave in Memory?  

- In most cases, the array identifier (the array's variable name) decays into a pointer *to the first element in the array*.

**Suppose the Following:**  
```
int main(int argc, char *argv[])
{
  int arr[] = {5, 13, 22};
  printf("%d\n", arr);
  return 0;
}
```

--> The printout will look something like this: `-854657148`. This is the address, in memory, of the first element of the array `arr`.


### Dereference the First Element in the Array
```
int main(int argc, char *argv[])
{
  int arr[] = {5, 13, 22};

  // Remember, the name identifier arr has decayed into a pointer to the first element in arr.
  // Use the referencing operator to dereference it.
  printf("%d\n", *arr);
}
```

--> The printout will be `5` now.

### Bracket notation

- Bracket notation: `arr[0]`, `arr[1]`, etc, is shorthand for the Array Subscript Operator syntax.

- The Concept: "add" to a pointer
- The Formula: the number "added" * size, in bytes of the data type at the address the pointer points to:  
```
// array_name has decayed to a pointer to the address to the first element in the array.
// Adding (n * bytes in data_type) advances the pointer to the next n bytes.
// Dereferencing the new address gives the value stored there.
data_type array_name[n] == *(array_name + (n * bytes in data_type))
```

**Breaking it down**  
- `arr[1]`: this is actually shorthand for `*(arr + 1)` where "1" is equal to 1 unit of the data type in bytes.

- Step by step:  
1. `arr`: the variable name for the array `{5, 13, 22}` that has decayed into a pointer to the first element. It's actual value is `-854657148`.  
  |  
2. `arr + 1`:  `1` in this case is actually "1 * 4 bytes". If the bracket notation were accessing the third element in the array, like so: `arr[2]`, it would mean "2 * 4 bytes". So:  
  |  
  ```
  arr + 1 == -854657148` + (1 * 4)
  ```  
  |  
3. The whole thing breaks down to:  
  |  
  ```
  // 4 bytes in an int, so each number `n` advances the pointer 4 bytes.
  // Dereferencing gives the value 13 for the second element in the array.
  *(-854657148 + (1 * 4))
  ```  

**Recap**  
The array subscript operator is programmed in such a way that it dereferences the array's decay into a pointer and allows the programmer to pass in the desired index to access elements.

I have written a small function in the programs directory illustrating this.
