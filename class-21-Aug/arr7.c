/* we saw how the 2 arguments are passed differently
   now check  how they are returned differently

   - Also note the syntax error demonstrates how C uses inconsistent
     syntax for passing and returning arrays. While passing in, it pretends
     whole array. While returning, it has to become a pointer
*/
(int[]) sum(int a[], int len);
void main()
// void describes a procedure as against a function
{
  int ma[]={1,2,3,4,5};
  int mlen = 5;
  int s[];
  s = sum(ma, mlen);
  
}

int[] sum(int a[], int len)
{ 
  int s = 0;
  int b[]={1,2,3,4};
    while(len >0)
      s+= a[--len]; // try combinations len-- , also in condition
    return(b);
}
    
