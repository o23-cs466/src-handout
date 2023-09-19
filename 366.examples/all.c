:::::::::::::: define.c ::::::::::::::

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



:::::::::::::: static_size.c ::::::::::::::

// a motivation for dynamic allocation of memory

#include "stdio.h"
#include "stdlib.h"

// use gcc -DMAX_N=10
// #define MAX_N 10

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



:::::::::::::: pointers-n-arrays.c ::::::::::::::

#include <stdio.h>

int main()
{
  int a[] = {1,3,5,7,-1};
  int i;
  int *p;

  for(i=0; a[i] > 0; i++)
    printf("%d, ", a[i]);
  printf("\n");

  //p = &a[0] 
  for(p=a; *p > 0; p++)
    printf("%d, ", *p);
  printf("\n");

  printf("%d\n", a[3]);
  printf("%d\n", *(a+3));
  printf("%d\n", *(3+a));
  printf("%d\n", 3[a]);

  int b = 3;
  printf("%d\n", a[b]);
  printf("%d\n", b[a]);

  printf("& and * with a  %p %p %p\n", a, *(&a), &(*a)); //  &a[0]  

  p = a;
  printf("& and * with a  %p %p %p\n", p, *(&p), &(*p));

  return 0;
}

/*
 * 1, 3, 5, 7, 
 * 1, 3, 5, 7, 
 * 7
 * 7
 * 7
 * 7
 * 7
 * 7
 * & and * with a  0x7ffee5a05b60 0x7ffee5a05b60 0x7ffee5a05b60
 * & and * with a  0x7ffee5a05b60 0x7ffee5a05b60 0x7ffee5a05b60
 */


:::::::::::::: pointer-n-const.c ::::::::::::::

void foo( int       *       ptr,
          int const *       ptr_to_const,
          int       * const const_ptr,
          int const * const const_ptr_to_const )
{
  *ptr = 0; // OK: modifies the pointee
  ptr  = 0; // OK: modifies the pointer
 
  *ptr_to_const = 0; // Error! Cannot modify the pointee
  ptr_to_const  = 0; // OK: modifies the pointer
 
  *const_ptr = 0; // OK: modifies the pointee
  const_ptr  = 0; // Error! Cannot modify the pointer
 
  *const_ptr_to_const = 0; // Error! Cannot modify the pointee
  const_ptr_to_const  = 0; // Error! Cannot modify the pointer
}


int main()
{
  return 0;
}


/*
 * gcc -Wall t.c
 * In function 'foo':
 *   14: error: assignment of read-only location '*ptr_to_const'
 *   18: error: assignment of read-only parameter 'const_ptr'
 *   20: error: assignment of read-only location '*const_ptr_to_const'
 *   21: error: assignment of read-only parameter 'const_ptr_to_const'
 */



:::::::::::::: malloc-play.c ::::::::::::::

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


:::::::::::::: memwatch-play.c ::::::::::::::

#include "memwatch.h"

int main()
{
  char *p = (char *) malloc(sizeof(char)*100);
  char *q = (char *) malloc(sizeof(char)*400);

  free(p);
  free(p);   // oops :) 2023 - memwatch dumps core :(

  // free(q);      // try without this line

  p = (char *) 0x12345678;
  free(p);      // oops (wild free) 2023 - memwatch dumps core :(

  return 0;
}


:::::::::::::: string-main.c ::::::::::::::

#include "stdio.h"


int main(int argc, char **argv)
{

  for(; *argv != NULL; argv++)
    printf("%p %s\n", argv, *argv);


  return 0;

  char s[10];

  int i;
  for(i=0; i<9; i++)
    s[i] = 'A' + i;
  s[i] = '\0';

  printf("s = %s\n", s);

  char *cp;

  for(cp=s; *cp != '\0'; cp++)
    printf("%p\n", cp);

  return 0;
}
  
