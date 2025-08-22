/* We have a as a global array, likewise len is a global variable
   the invariant of the array is that length(a) == len  at all times*/
int a[]={1,2,3,4,5};
int len = 5;
int sum(int arr[], int len);
void main(void)
/* void describes a procedure as against a function, void in the argument position indicates it has no arguments*/
{
  int s;
  s = sum(a, len);
}

int sum(int sa[], int slen)
/* function sum has been written to take an array and its length as its arguments and return the sum of its elements */
{ int i = 0;
  int s = 0;
  while(i < slen)
  {
    s = s + sa[i];
    i = i + 1;
  }
  return(s);
}

Exercise 1. Trace the execution of this program, verifying the value of a[] and len at the end of its execution.
