#include <stdio.h>
int main ()
{
  unsigned int xval = 0x12345678;
  char *cval = (char*) &xval;
 
  printf ("*c is: 0x%x\n", *cval);
  if (*cval == 0x78)
  {
    printf ("Little Endian\n");
  } 
  return 0;
}
