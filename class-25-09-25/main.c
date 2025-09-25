#include "listlib.h"
void main()
{
  NodePtr hd= (NodePtr) malloc(sizeof(Node));
  hd->val =-1;
  hd->next = NULL;

  inputlst(hd);
  printlst(hd);
}
