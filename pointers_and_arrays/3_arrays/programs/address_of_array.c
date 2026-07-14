#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char str[16] = "Example string";
  printf("Value of str: %s\n", str);
  printf("Value of str passed as a pointer: %p\n", str);
  printf("Value of &str: %p\n", &str);
  printf("Value of &str[0]: %p\n", &str[0]);

  // Test the difference between the printout of the following three addresses.
  // The difference between the first two should be 1 byte, as the type is char.
  // The difference between the first and third printf() statement is 10 - or, in hexadecimal, 16 bytes!
  // This is because `&str` is of the type "pointer to char array of 16", and when dereferenced, this is 16 bytes.
  printf("Address: %p\n", str);
  printf("Address: %p\n", str + 1);
  printf("Address: %p\n", &str + 1);


  printf("Size of str passed as a pointer: %llu\n", sizeof(&str));
  return 0;
}
