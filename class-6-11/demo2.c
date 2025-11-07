#define ONE 1
#define FLOAT 
#define makecmp(a) int a##cmp(a x, a y)		\
                   {\
		     return(x < y);\
		     }
makecmp(int)
makecmp(char)
#ifdef FLOAT
  makecmp(float)
#endif

#define makenodelib(a) typedef struct Node *Nodeptr;	\
struct Node\
{\
  a val;\
  Nodeptr next;\
} Node;\
\
Nodeptr insert##a(Nodeptr hd, a val)\
{\
  Nodeptr p = malloc(sizeof (struct Node));\
  p->val = val;\
  p->next = hd;\
  return(p);\
}

makenodelib(int)
makenodelib(float)

int main()
{
  printf("cmp is:%d %d %d", intcmp(3,4), floatcmp(2.3,7.1),ONE);
}

