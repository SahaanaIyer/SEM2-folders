#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack
{
  int a[max];
  int topA;
  int topB;
};
void pushA(struct stack *, int);
void pushB(struct stack *, int);
void popA(struct stack *);
void popB(struct stack *);
void displayA(struct stack *);
void displayB(struct stack *);
int main()
{
  struct stack S;
  S.topA=-1;
  S.topB=max;
  int X;
  
  pushA(&S,10);
  pushB(&S,20);
  pushA(&S,30);
  pushB(&S,40);
  popA(&S);
  popB(&S);
  displayA(&S);
  displayB(&S);

  return 0;
}

void pushA(struct stack *P, int X)
{
  if(P->topB-1 == P->topA)
    printf("Overflow\n");
  else
    {
       P->topA++;
       P->a[P->topA] = X;
    }
}

void pushB(struct stack *P, int X)
{
  if(P->topA+1 == P->topB)
    printf("Overflow\n");
  else
    {
       P->topB--;
       P->a[P->topB] = X;
    }
}

void popA(struct stack *P)
{
  int q;
  if(P->topA == -1)
    printf("Stack underflow\n");
  
  else
    {
      q = P->a[P->topA];
      P->topA--;
      printf("Popped element is %d\n", q);
    }
}

void popB(struct stack *P)
{
  int q;
  if(P->topB == -1)
    printf("Stack underflow\n");
  
  else
    {
      q = P->a[P->topB];
      P->topB--;
      printf("Popped element is %d\n", q);
    }
}

void displayA(struct stack *P)
{
  int i;
  if(P->topA == -1)
       printf("Stack empty\n");

  for(i=0; i<=P->topA; i++)
       printf("%d\n", P->a[i]);
}

void displayB(struct stack *P)
{
  int i;
  if(P->topB == -1)
       printf("Stack empty\n");

  for(i=0; i<=P->topB; i++)
       printf("%d\n", P->a[i]);
}

