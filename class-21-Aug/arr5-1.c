/* instruction set optimizations, associated syntactic cleanups */
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
{ 
  int s = 0;
  while(--len >=0)
    s += a[len];
  // try combinations len--(postdecrement) , also in condition
  // also try combinations of using pre and post increment
  return(s);
}
    
