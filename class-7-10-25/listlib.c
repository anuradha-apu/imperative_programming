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
int length(NodePtr l)
{
  int len=0;
  l = l->next;
  while(l)
  {
    len++;
    l = l->next;
  }
  return(len);  
}

void printlst(NodePtr l)
{
  while(l)
  {
    printf("%d\n", l->val);
    l=l->next;
  }
}

void reverselst(NodePtr hd)
{
  NodePtr ncur,cur,prev;

  cur =hd->next;
  prev = NULL;

  while(cur!=NULL)
  {
    ncur = cur->next;
    cur->next = prev;
    prev = cur;
    cur = ncur;
  }

  hd->next = prev;
 }
