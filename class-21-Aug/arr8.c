/* -Fixed return syntax for sum
    Explicitly made a pointer - ie an address of the array
   -For consistency, do the same with the argument - after all it is also a
   pointer with pretty syntax
   -Note the warning about returning an address from the callee stack frame
    Dwell on why it is wrong, convince yourself why this program crashes
*/
int  *sum(int a[], int len);
void main()
// void describes a procedure as against a function
{
  int ma[]={1,2,3,4,5};
  int mlen = 5;
  int *s;
  s = sum(ma, mlen);
  printf("%d", *s);
 }

int *sum(int a[], int len)
{ 
  int s = 0;
  int b[]={1,2,3,4};
    while(len >0)
      s+= a[--len]; // try combinations len-- , also in condition
    return(b);
}
    
