#define Firstindex 0
void printarray(int l[],int len);
int  min(int l[], int len);
void swap(int l[], int i, int j);
void insert(int l[], int j, int k);

main()
{
  int l[]={21,11,3,67,43};
  int len=(int)(sizeof(l)/sizeof(int));
  int minind = min(l,len);
  
  printarray(l,len);
  printf("selection pass 1\n");
  swap(l,Firstindex,minind);
  
  printarray(l,len);
  
}

int min(int l[], int len)
// returns index of minimum element
{
  int i=0;
  int min = 0;
  for(i=0; i < len; i++)
    {if( l[i] < l[min]) {min = i;}}
  return(min);
}

void printarray(int l[],int len)
{
  int i=0;
  for (i=0;i < len; i++)
    printf("%d\n", l[i]);
}

void swap(int l[], int i, int j)
{
  int t = l[i];
  l[i]=l[j];
  l[j]=t;
}

void insert(int l[], int j, int k)
{
  int temp = l[k];
  int i;
  for(i = k-1;i>j ;k--, i--)
    l[k] = l[i];
  l[i]= temp;
}
