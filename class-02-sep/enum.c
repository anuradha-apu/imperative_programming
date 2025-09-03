#include <stdio.h>
enum Direction{N,S,E,W};
enum Direction tr(enum Direction x);

void main()
{
 printf("%d direction",tr(N));
}
enum Direction tr(enum Direction x)
{
  enum Direction d;
  switch(x)
    {
    case (N) : d= E;
      break;
    case (S): d = W;
      break;
    case (W): d = N;
      break;
    case (E): d = S;
      break;
    }

  return d;
}
