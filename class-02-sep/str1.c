#include <stdio.h>

typedef struct
{
  int a;
  float b;
}rec;
main()
{
char *x= "Azim Permji University";

 rec x1;
 rec *p=&x1;
 x1.a=1;
 x1.b=2.3;
 // printf("%d", lengthstring(x) );
 
 printf("%d direction x1:a %d x1:b%.2f",te(N), x1.a, x1.b);
 p->a= 4;
 p->b= 7.7;
 printf("x1:a %d x1:b%2f",te(N), x1.a, x1.b);
}

int lengthstring(char * a)
{
  int i = 0;
  while (a[i] !='\0')
    i++;
  return(i);
}




