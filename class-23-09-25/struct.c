typedef struct
{
  int a;
  int b;
  char c;
}ms;


typedef Cell *Cellptr;
typedef struct
{
  int a;
  Cellptr next;
}Cell;

void main()
{
  ms msval;
  Cell hd;
  Cellptr ptr;
  hd. a = 1;

  ptr = malloc(sizeof(Cell));
  ptr->a = 2;
  ptr->next = NULL
  hd.next = ptr;
  
  msval.a = 3;
  msval.b = 2;
  msval.c = 'a';

  printf(" Ms is %d %d %c \n%d", msval.a,msval.b,msval.c, sizeof(msval));
}
