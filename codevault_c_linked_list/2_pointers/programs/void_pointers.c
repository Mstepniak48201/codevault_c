#include <stdio.h>
#include <stdlib.h>

// Prototypes
void print_int_bytes(int *arr, int n);
void print_bytes(void *arr, int n);

int main(int argc, char *argv[])
{
  int arr[] = {16, 31, 32, 65};

  // Remember that the array's variable name, "arr" has decayed to a pointer.
  // Internally, the function uses the array subscript operator to dereference it: arr[i] == *(arr + i)!
  print_int_bytes(arr, 4);

  // Pass this long long array as the void pointer to print_bytes().
  long long long_arr[] = {16, 31, 32, 65};

  // Since print_bytes() takes a void pointer, the size of the data type is unknown. 
  // Pass size_of_array * sizeof(data_type) to get the correct number in bytes.
  print_bytes(long_arr, 4 * sizeof(long long));

  return 0;
}

void print_int_bytes(int *arr, int n)
{
  printf("print_int_bytes(int *arr, int n):\n");
  int i;
  for (i = 0; i < n; i++)
  {
    // Print the array element as a hexadecimal:
    // 0 - leading zeros instead of empty space
    // 8 - sizeof(int) = 4 bytes (32 bits) -> required length for printout: 32 bits / 4 bit hexadecimal digit -> 8!
    // x - hexadecimal format
    printf("%08x\n", arr[i]);
  }
}

void print_bytes(void *arr, int n)
{
  printf("print_bytes(void *arr, int n):\n");
  int i;
  for (i = 0; i < n; i++)
  {
    // As the data type of the incoming array is unknown, cast the void pointer arr to a char pointer.
    // This allows the function to examine arr, 1 byte at a time.
    char *bytes = (char *)arr;

    // Change the print input length from 8 to 2:
    // The char data type is 1 byte (8 bits): 8 bits / 4 bit hexadecimal digit = 2
    printf("%02x\n", bytes[i]);
  }
}
