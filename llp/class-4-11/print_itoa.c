#include <stdio.h>
#include <string.h>
int number = 10005;
#define SIZE 10
// char str[SIZE];
int pos = SIZE-1;
char str[SIZE];

void itoa(void);
  int main()
{
  itoa();
  printf("str + pos is %s\n", str+pos+1);

}
void itoa(void)
{

  int quot, rem;
  *(str + 9)= 0;
  pos = 8;
  quot = number;
  do
  {
    pos--;
    rem  = quot % 10;
    quot = quot / 10;
    str[pos] = rem + '0';

  }
   while (quot > 0);
}
