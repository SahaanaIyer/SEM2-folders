/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

struct node
{
  int info;
  struct node *left, *right;
};

struct stack
{
  int top;
  struct node *post[max];
};

struct node *ROOT = NULL;
 
void Inorder(struct node *);	
void push(struct stack *, struct node *);
struct node *pop(struct stack *);
int isOperand(char );

int main()
{
    struct node *p;
    struct stack s;

    s.top = -1;
	
    char post[100];
    int i, len;
    struct node *newnode, *t1, *t2;
    
    printf("Enter postfix expression \n");
    gets(post);
    len = strlen(post);
   
    for(i=0; post[i]!='\0'; i++)
    {
    	newnode = (struct node *) malloc (sizeof (struct node));
        newnode -> info = post[i];
        newnode -> left = NULL;
        newnode -> right = NULL;
        
        if( isOperand( post[i] ))
        {
         	push(&s, newnode);
	    }
	    else
	    {
	        t1 = pop(&s);
		    t2 = pop(&s);
		    newnode->right = t1;
		    newnode->left = t2;
	        push(&s, newnode);
	    }
	}
	Inorder(pop(&s));
	return 0;
}


void Inorder(struct node *t)
{
	if(t != NULL)
	{
        Inorder (t->left);
        printf("%d \n", t->info);
		Inorder(t->right);
	}
}

void push(struct stack *s, struct node *p)
{
     s->post[++s->top] = p;
}

struct node* pop(struct stack *s)
{
     return (s->post[s->top--]);
}

int isOperand(char X)
{
   if(X >= '0' && X <= '9')
              return 1;
   else
              return 0;
}


