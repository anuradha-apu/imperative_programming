/* what is the use of a function computing sum for a fixed array?
   we want a function so that we can compute sum for varying inputs.
   Therefore we need to prameterise the function sum.

   Also if we want to be able to call with different args, the definition of the array may be local to the caller function.
   So lets try moving a into locals

   A note about parameter passing:
   - run gdb and put a breakpoint before calling sum and inside sum
   - check the value of ma in main
   - check the value of a in sum.
   - notice how int values are passed as is and arrays are not copied
   - try changing the argument a[] in sum and see if it is reflected in the
     variable ma that it was called with
   - try changing the argument len in sum and see if it is reflected in the
     variable mlen in main
   - Can you state what is the difference?

*/
   

int sum(int a[], int len);
void main()
// void describes a procedure as against a function
{
  int ma[]={1,2,3,4,5};
  int mlen = 5;
  int s;
  s = sum(ma, mlen);
}

int sum(int a[], int len)
{ 
  int s = 0;
    while(--len >=0)
      s+= a[len]; 
    return(s);
}
    
