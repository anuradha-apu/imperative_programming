#include <stdio.h>
#include <string.h>
int number = 1234;
#define SIZE 7

int pos = 6;
char str[7] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};

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
