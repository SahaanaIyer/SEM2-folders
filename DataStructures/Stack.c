#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack
{
  int a[max];
  int top;
};
void push(struct stack *, int);
int pop(struct stack *);
void peep(struct stack *);
int isFull(struct stack *);
int isEmpty(struct stack *);
void display(struct stack *);
int main()
{
  struct stack S;
  S.top=-1;
  int choice,n, P, E, F;

  while(1)
  {
    printf(" Enter 1:Push 2:Pop 3:Peep 4:Full 5:Empty 6:Display 7:Exit\n");
    scanf("%d", &choice);
    
   switch(choice)
   {
     case 1 : printf("Enter no. to be pushed\n");
              scanf("%d",&n);
              push(&S, n);
              break;

     case 2 : P = pop(&S);
              if(P!=-1)
                      printf("Popped element is %d\n", P);
              break;
    
     case 3 : peep(&S);
              break;

     case 4 : F = isFull(&S);

              if(F == 1)
                 printf("Stack full\n");
              break;

     case 5 : E = isEmpty(&S);

              if(E == 1)
                  printf("Stack empty\n");
              break;

     case 6 : display(&S);
              break;
  
     case 7 : exit(0);
    }
  }
  return 0;
}

void push(struct stack *p, int X)
{
  if( p->top == max-1)
  {
     printf("Stack overflow\n");
  }
  else
  {
     ++p->top;
     p->a[p->top] = X;
  }
}

int pop(struct stack *p)
{
  int q;
  if(p->top == -1)
  {
    printf("Stack underflow\n");
    return -1;
  }
  else
  {
    q = p->a[p->top];
    p->top--;
    return q;
  }
}

void peep(struct stack *p)
{
  if(p->top == -1)
  {
    printf("Stack empty\n");
  }
  else
  {
    printf("%d\n", p->a[p->top]);
  }
}

int isFull(struct stack *p)
{
  if(p->top == max-1)
      return 1;
  else
      return -1;
}

int isEmpty(struct stack *p)
{
  if(p->top == -1)
      return 1;
  else
      return -1;
}

void display(struct stack *p)
{
  int i;
  if(p->top == -1)
       printf("Stack empty\n");
  
  for(i=0 ; i<=p->top ; i++)
  {
      printf("%d\n", p->a[i]);
  }
}
