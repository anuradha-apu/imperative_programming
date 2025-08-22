/* nitty gritty tweaks - we can add up elements backwards */
   
int a[]={1,2,3,4,5};
int len = 5;
int sum(void);
void main(void )
/* void in return type describes a procedure as against a function
  void as argument indicates there are no arguments */
{
  int s;
  s = sum();
}

int sum(void )
{ 
  int s = 0;
  len = len - 1;
  while(len >0)
  {
    s = s + a[len];
    len = len - 1;
  }
  return(s);
}
    
