#include <stdio.h>
typedef struct Node *NodePtr;
typedef struct Node
{
  int val;
  NodePtr next;
}Node;
//typedef NodePtr Lst;

void inputlst(Node hd);
int main(void)
{
  Node hd;

  inputlst(hd);

}

void inputlst(Node hd)
{
  int c;
  do
  {
    scanf("%d", &c);
  }while(c !=-1);
    //....
}

  
