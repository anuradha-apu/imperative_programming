/* If a is a global array, why pass it?
   Variant 1: sum does not need arguments, it can directly acess globals*/

int a[]={1,2,3,4,5};
int len = 5;
int sum(void);
void main()
// void describes a procedure as against a function
{
  int s;
  s = sum();
}

int sum(void)
{ int i = 0;
  int s = 0;
  while(i < len)
  {
    s = s + a[i];
    i = i + 1;
  }
  return(s);
}
    
