#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

struct node
{
	int info;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int X)
{
	struct node *new, *p;
	new = (struct node *) malloc (sizeof(struct node));
	new->info = X;
	new->next = NULL;
	
	if(front == NULL && rear == NULL)
	{
	    front = new;
	    rear = new;	
	    new->next = front;
	}
	else
	{
		rear->next = new;
		new->next = front;
		rear = new;
	}
}

void display()
{
	struct node *p;
	if(front == NULL && rear == NULL)
	      printf("List empty\n");
	else
	{
		p = front;
		while(p->next != front)
		{
		     printf("%d  \t", p->info);
		     p = p->next;
		}
		 printf("%d  \t", p->info);
	}
	printf("\n");
}

void dequeue()
{
	struct node *p, *ptr;
	if(front == NULL && rear == NULL)
	      printf("List empty \n");
	else 
	{   
	    p = front;
	    ptr = front;
	    if(front == rear)
	    {
	    	front = rear = NULL;
	    	printf("Deleted element is %d \n",p->info);
            free(p);
		}
		else
		{
			while(p->next != front)
			    p = p->next;
			p->next = front->next;
			front = front->next;
			printf("Deleted element is %d \n",ptr->info);
            free(ptr);
		}
	}
}

int main()
{
	int ch,n,X,E,F;
	
	do{
	    printf("1.Enqueue  2.Dequeue  3.Display  4.Exit \n");
	    printf("Enter your choice \n");
        scanf("%d",&ch);
    
	    switch(ch)
     	{
	        case 1 :
		              printf("Enter the no. to be enqueued \n");
				      scanf("%d",&n);
				      enqueue(n);
				      break;
				  
	       	case 2 :
			          dequeue();
			          break;
				  
	     	case 3 :
			          display();
			          break;
			      
			case 4 :
			          exit(0);
	    }	
    }while(ch != 5);
    
return 0;	
}
