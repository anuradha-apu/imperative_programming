#include <stdio.h>
typedef struct tnode *Treeptr;
typedef struct tnode
{ int val;
  Treeptr lt;
  Treeptr rt;
}tnode;
void mkitree(Treeptr t);
#define Val(t) t->val
#define Rt(t)  t->rt
#define Lt(t)  t->lt
main()
{
  Treeptr root=NULL;
  mkitree(root);
}

void mkitree(Treeptr t)
{
  t = (Treeptr)malloc(sizeof(tnode));
  Val(t) = 1
  Lt(t)= (Treeptr)malloc(sizeof(tnode));
  Rt(t) = (Treeptr)malloc(sizeof(tnode));
  Val(Lt(t)) = 2;
  Lt(Lt(t))= NULL;
  Rt(Lt(t)) = NULL;
  Val(Rt(t)) = 3;
  Lt(Rt(t)) = NULL;
  Rt(Rt(t)) = NULL;
}

/*Treeptr mirrornc(Treeptr t)*/
void mirrorc(Treeptr t)
{
  if (t!=NULL)
  {
    mirrorc(Lt(t));
    mirrorc(Rt(t));
    swp(Rt(t), Lt(t));
  }
}
  
    
  
