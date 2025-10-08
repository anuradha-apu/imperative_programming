#include <malloc.h>
#include <stdio.h>
typedef struct Node *NodePtr;
typedef struct Node
{
  int val;
  NodePtr next;
}Node;

void inputlst(NodePtr hd);
void insert(NodePtr l, int val);
void printlst(NodePtr l);
int length(NodePtr l);
void reverselst(NodePtr hd);
