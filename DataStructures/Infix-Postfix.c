/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include <stdio.h>
#define max 50
struct stack
{
int top;
char a[max];
};
int isEmpty(struct stack*);
int isOperand(char);
int priority(char);
int peep(struct stack *);
void push(struct stack *,char);
int pop(struct stack *);
int main()
{
    struct stack s;
	s.top=-1;
	char exp[20];
	char pos[20];
	printf("Enter an expression\n");
	gets(exp);
	int i,j=0,x;
	for(i=0;exp[i]!='\0';i++)
	{
		if(isOperand(exp[i]))
		{
			pos[j]=exp[i];
			j++;
		}
		else if(exp[i]=='(')
			push(&s,exp[i]);
		else if(exp[i]==')')
		{
			while((x=pop(&s))!='(')
			{
				pos[j]=x;
				j++;
			}
		}
		else
		{
			while((priority(exp[i])<=priority(peep(&s))) && !isEmpty(&s))
			{
				x=pop(&s);
				pos[j]=x;
				j++;
			}
			push(&s,exp[i]);
		}
	}
	while(!isEmpty(&s))
	{
		x=pop(&s);
		pos[j]=x;
		j++;
	}
	pos[j]='\0';
	puts(pos);
	return 0;
}

void push(struct stack *s,char x)
{
	if(s->top==max-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	s->top++;
	s->a[s->top]=x;	
}

int isEmpty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}

int pop(struct stack *s)
{
	if(isEmpty(s))
	{
		printf("Stack Underflow\n");
		return -1;
	}
	return s->a[s->top--];
}

int isOperand(char x)
{
	if(x>='0' && x<='9')
		return 1;
	else
		return 0;
}

int priority(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	else if(x=='(')
		return 0;
	else
		return 3;
}

int peep(struct stack *p)
{
	return p->a[p->top];
}
/*
Output :- Enter an expression
          (5+3)*8-(7/8)
          53+8*78/-
*/

