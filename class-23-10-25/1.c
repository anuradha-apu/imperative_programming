#define mklen(x) int len##x(x arr[])\
  {\
    int lenval,i;				\
    lenval =0; i=0;				\
    while(arr[i]!=-1)\
    {i++;}\ return i;
}      
 

mklen(int)
  mklen(char);
main()
{

  printf("%d %s", __LINE__, __FILE__);

}
