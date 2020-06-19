
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

struct node
{
	int info;
	struct node *next;
};

struct node *top = NULL;

void push(int X)
{	
	struct node *new, *p;
	new = (struct node *) malloc (sizeof(struct node));
	new->info = X;
	new->next = NULL;
	
	if(top == NULL)
	{
		top = new;
	    new->next = top;
    }
	else 
	{
		p = top;
		new->next = top;
	    while(p->next != top)
	    {
	    	p = p->next;	
		}
		p->next = new;
		top = new;
	}
}

void pop()
{
	struct node *p, *ptr;
	if(top == NULL)
	      printf("List empty \n");
	else 
	{   
	    p = top;
	    ptr = top;
	    while(p->next != top)
	    {
	    	p = p->next;	
		}
		p->next = top->next;
	    top = top->next;
		printf("Node deleted is %d \n", ptr->info);
		free(ptr);
	}
}

void display()
{
	struct node *p;
	if(top == NULL)
	      printf("List empty\n");
	else
	{
		p = top;
		while(p->next != top)
		{
		     printf("%d  \t", p->info);
		     p = p->next;
		}
        printf("%d  \t", p->info);
	}
	printf("\n");
}

void peep()
{
	if(top == NULL)
	      printf("List empty \n");
	else 
		printf("Peeped element is %d \n", top->info);
}

int main()
{
	int ch,n,X,E,F;
	
	do{
	    printf("1.Push  2.Pop  3.Display  4.Peep  5.Exit \n");
	    printf("Enter your choice \n");
        scanf("%d",&ch);
    
	    switch(ch)
     	{
	        case 1 :
		              printf("Enter the no. to be pushed \n");
				      scanf("%d",&n);
				      push(n);
				      break;
				  
	       	case 2 :
	       		      pop();
				      break;
				  
	     	case 3 :
			          display();
			          break;
			          
			case 4 :
				      peep();
				      break;
			
			case 5 :
			          exit(0);
	    }	
    }while(ch != 6);
    
return 0;
}

