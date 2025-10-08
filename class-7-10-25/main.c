#include "listlib.h"
void main()
{
  NodePtr hd= (NodePtr) malloc(sizeof(Node));
  hd->val =-1;
  hd->next = NULL;

  inputlst(hd);
  printf("Length:%d\n",length(hd));
  printlst(hd);
  printf("Now reverse\n");
  reverselst(hd);
  printlst(hd);
}
