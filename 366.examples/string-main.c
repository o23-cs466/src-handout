
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
  
