#include <stdio.h>
main()
{
char *x= "Azim Permji University";

 printf("%d %d %s\n", lengthstring(x),sizeof('a' ),x);
}

int lengthstring(char * a)
{
  int i = 0;
  while (a[i++] !='\0');
  return(i);
}
