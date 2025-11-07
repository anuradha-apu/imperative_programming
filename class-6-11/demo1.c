#include <stdio.h>
#define f(a) f##a
#define g(a,b) (#a"<"#b )

int f(2);


/*int intcmp(int x, int y);
int floatcmp(float x, float y);
int charcmp(char x, char y);*/
int main()
{
  printf("cmp is:%d %d ", intcmp(3,4), floatcmp(2.3,7.1));
}

/*
int intcmp(int x, int y)
{
  return(x < y);
}

int floatcmp(float x, float y)
{
  return(x < y);
}


int charcmp(char x, char y)
{
  return(x < y);
}
*/
