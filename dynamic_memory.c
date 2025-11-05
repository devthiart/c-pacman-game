#include <stdio.h>
#include <stdlib.h>

int main()
{

  // Dynamically allocating memory
  int *v = malloc(sizeof(int)); // alloc 4 bites
  *v = 10;
  printf("int allocated %d\n", *v);
  free(v);

  // Creating an int matrix dynamically
  int **m = malloc(sizeof(int *) * 5); // 5 columns
  for (int i = 0; i < 5; i++)
  {
    m[i] = malloc(sizeof(int) * 10); // 10 lines
  }
  m[0][0] = 10;
  m[1][2] = 12;
  printf("Allocated int matrix:\nposition [0][0]: %d\nposition[1][2]: %d\n", m[0][0], m[1][2]);

  // Free spaces
  for (int i = 0; i < 5; i++)
  {
    free(m[i]);
  }
  free(m);

  return 0;
}