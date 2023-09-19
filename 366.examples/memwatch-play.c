
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
