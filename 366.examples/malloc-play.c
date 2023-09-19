#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct aPoint
{
  int x;
  int y;
};

int main()
{
  // int *big_array = (int *) malloc(sizeof(int) * MAX_N);

  struct aPoint *point_ptr = (struct aPoint *)malloc(sizeof(struct aPoint));

  //point_ptr.x = 5;
  // *point_ptr.x = 5;
  // *(point_ptr.x) = 5;
  // both generate error: request for member 'x' in something not a structure 

  (*point_ptr).x = 5;
  point_ptr->x = 5;


  // let's see what happens if we don't initialize a pointer
  // "gdb a.out" can help ... but first "gcc -g t.c"
  int *p;
  // p = (int *) malloc(sizeof(int));    /// TRY WITHOUT
  printf("p = %p \n", p);
  *p = 42;
  printf("p = %p *p = %d\n", p, *p);

  return 0;
}
