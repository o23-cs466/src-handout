// define.c
// compile with 'gcc -DB=42'

#include "stdio.h"

#define A 10

#ifndef B
#define B 42
#endif

int main()
{
  printf("A = %d, B = %d\n", A, B);
  return A+B;
}
