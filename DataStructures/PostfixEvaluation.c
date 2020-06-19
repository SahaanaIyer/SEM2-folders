#include<stdio.h>
#include<stdlib.h>
#define max 30

struct stack
{
	int top;
	int exp[max];
};

void push(struct stack *p, int X)
{
    if(p->top == max-1)
	{
		printf("Stack Full\n");
		return;
	}
	else
	{
	    p->exp[++p->top] = X;	
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
		X = p->exp[p->top--];
		return X;
	}
}

int isOperand(int X)
{
	if(X>='0' && X<='9')
	        return 1;
	else
	        return 0;
}

int main()
{
	struct stack s;
	s.top = -1;
	
	int i;
	char n1, n2, exp[max];
	
	printf("Enter a postfix exp \n");
	gets(exp);	
	
	for(i=0; exp[i]!='\0'; i++)
	{
		if(isOperand(exp[i]))
		{
			push(&s, exp[i]-'0');
		}
		else
		{
			n2 = pop(&s);
			n1 = pop(&s);
			switch(exp[i])
			{
				case '+' :
					        push(&s, n1+n2);
					        break;
					        
				case '-' :
					        push(&s, n1-n2);
					        break;
					        
				case '*' :
					        push(&s, n1*n2);
					        break;
					        
				case '/' :
					        push(&s, n1/n2);
					        break;
					        
				case '%' :
					        push(&s, n1%n2);
					        break;
					        
				 default :  printf("Enter a valid operator \n");
				            exit(0);
			}
		} //else
	}//for loop
	printf("Evaluation is %d \n", pop(&s));
	return 0;
}


