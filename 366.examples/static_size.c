// a motivation for dynamic allocation of memory

#include "stdio.h"
#include "stdlib.h"

// use gcc -DMAX_N=10
// #define MAX_N 10
// #define MAX_N 2000000
// #define MAX_N 2250000

int main() 
{
  printf("\nallocating an array of size %ld %ldMB\n", MAX_N*sizeof(int), 
          (MAX_N*sizeof(int))/(1024*1024));
  int i, n;
  int stack_array[MAX_N];
  int *heap_array = (int *) malloc(sizeof(int) * MAX_N);

  printf("  address of i %p  stack array %p  heap array %p\n", &i, stack_array, heap_array);

  return 0;
}
