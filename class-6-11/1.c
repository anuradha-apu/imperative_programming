#define f(a) f##a
#define g(a,b) (#a"<"#b )

int f(2);

/* main1() */
/* { */
/*   printf("%s",g(3,4));  */
/* } */
/*
extern int cmp(int,int);
extern int cmpchar(char x, char y);
extern float cmpfloat(float x, float y);
*/

#define makecmp(a) int cmp##a(#a x, #a y)\
  {\
    return(x <y);\
    }
main()
{
  cmpint(3,4);
  cmpchar('a','b');
  cmpfloat(1.4, 2.4);
}
/*
int cmpint(int x, int y)
{
  return x<y;
}

int cmpchar(char x, char y)
{
  return(x < y);
}

float cmpfloat(float x, float y)
{
  return(x<y);
}
*/

makecmp(float)
