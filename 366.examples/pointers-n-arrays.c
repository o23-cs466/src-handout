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

