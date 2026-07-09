#include <stdio.h>
#include <stdlib.h>

void print_int_arr(int *arr, size_t size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]) ;
  }
  printf("\n");
}

void print_char_arr(char **char_arr, size_t size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%s ", char_arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int arr[] = {5, 22, 17};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  char *char_arr[] = {"example", "killing it bro!", "doing great!"};

  char *el = "my element";

  print_int_arr(arr, size);
  print_char_arr(char_arr, 3);
  print_char_arr(&el, 1);

  return 0;
}
