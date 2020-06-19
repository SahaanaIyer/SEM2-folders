#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

struct stack
{
	int top;
	char b[max];
};

void push(struct stack *p, char X)
{
    if(p->top == max-1)
	{
		printf("Stack Full\n");
		return;
	}
	else
	{
		p->top++;
	    p->b[p->top] = X;	
	}
}

int pop(struct stack *p)
{
	int X;
	if(p->top == -1)
	{
		printf("Stack Empty\n");
		return 0;
	}
	else
	{
		X = p->b[p->top--];
		return X;
	}
}

int peep(struct stack *p)
{
	int X;
	if(p->top == -1)
	{
		printf("Stack Empty\n");
		return 0;
	}
	else
	{
		X = p->b[p->top];
		return X;
	}
}

int isEmpty(struct stack *p)
{
    if(p->top == -1)
	      return 1;
	else
	      return 0;	
}

int isOperand(char X)
{
	if(X>='0' && X<='9')
	        return 1;
	else
	        return 0;
}

int priority(char X)
{
	if(X=='(')
	     return 0;
    else if(X=='+' || X=='-')
	     return 1;
	else if(X=='*' || X=='/')
	     return 2;
	else 
	     return 3;
}

int main()
{
	struct stack s;
	s.top = -1;
	
	char exp[max], a[max], pre[max], in[max];
	int j=0, i, X, x;
	
	printf("Enter infix exp\n");
	gets(in);

	int len = strlen(in);
	for(i=len-1; i>=0; i--)	
	{
		exp[j] = in[i];
		j++;
	}
	exp[j] = '\0';
	printf("Reversed infix string is  ");
	puts(exp);

	for(i=0; exp[i] != '\0'; i++)
	{
		if(exp[i] == ')')
		       exp[i] = '(';
		       
		else if(exp[i] == '(')
		       exp[i] = ')';
    }
    puts(exp);
    
    int k=0;
		for(i=0;exp[i]!='\0';i++)
	{
		if(isOperand(exp[i]))
		{
			a[k]=exp[i];
			k++;
		}
		else if(exp[i]=='(')
			push(&s,exp[i]);
		else if(exp[i]==')')
		{
			while((x=pop(&s))!='(')
			{
				a[k]=x;
				k++;
			}
		}
		else
		{
			while((priority(exp[i])<=priority(peep(&s))) && !isEmpty(&s))
			{
				x=pop(&s);
				a[k]=x;
				k++;
			}
			push(&s,exp[i]);
		}
	}
	while(!isEmpty(&s))
	{
		x=pop(&s);
		a[k]=x;
		k++;
	}
	a[k]='\0';
	printf("Postfix exp  ");
	puts(a);

    int l=0;
    len = strlen(a);
	for(i=len-1; i>=0; i--)	
	{
		pre[l] = a[i];
		l++;
	}
	pre[l] = '\0';
	printf("Final prefix string is  ");
	puts(pre);
	
    return 0;
}


