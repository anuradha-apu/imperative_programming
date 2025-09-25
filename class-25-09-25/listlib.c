#include "listlib.h"
void inputlst(NodePtr hd)
{
  int c;
  do
  {
    scanf("%d", &c);
    insert(hd,c);
  }while(c != -1);
}
void insert(NodePtr l, int val)
{
  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  while(l->next !=NULL)
  {
    l = l->next;
  }
  l->next=p;
}

void printlst(NodePtr l)
{
  while(l)
  {
    printf("%d\n", l->val);
    l=l->next;
  }
}
