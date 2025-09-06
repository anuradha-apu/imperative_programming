void bs(int a[], int len);
main()
{
  int i;
  int a[]={1,0,1,0,1,1,1,1,0};
  int len = 9;
  bs(a,len);
  for(i=0;i <len; i++)
    printf("%d\n",a[i]);
}
void bs(int a[], int len)
{
  int i = 0;
  int t;
  int j = len-1;
  while(i<j)
  {
    if(a[i] == 0) i++;
    if (a[j] == 1) j--;
    if(i < j && a[i]==1 && a[j]==0 )
	{
	  t=a[i];
	  a[i] = a[j];
	  a[j] =t;
	}

   }
}

 
