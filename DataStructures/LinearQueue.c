#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

struct queue
{
	int a[max];
	int front, rear;
};

void enqueue(struct queue *q, int X)
{
	if(q->rear == max-1)
	     printf("Queue full \n");
	else if(q->front == -1 && q->rear == -1)
	{
		q->front++;
		q->rear++;
	    q->a[q->rear] = X;	
	}
	else 
	{
	    q->rear++;
		q->a[q->rear] = X;	
	}
}

int dequeue(struct queue *q)
{
	int X;
	if(q->front == -1 && q->rear == -1)
   		 printf("Queue empty \n");
	else if(q->front == q->rear)
	{
		X = q->a[q->front];
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		X = q->a[q->front];
		q->front++;
	}
	return X;
}

void display(struct queue *q)
{
	int i;
	if(q->front == -1 && q->rear == -1)
   		 printf("Queue empty \n");
    else
    {
    	for(i = q->front; i <= q->rear; i++)
	    {
		    printf("%d  \t", q->a[i]);
	    }
	    printf("\n");
	}
}

int isEmpty(struct queue *q)
{
    if(q->front == -1 && q->rear == -1)
	      return 1;
	else
	      return 0;	
}

int isFull(struct queue *q)
{
    if(q->rear == max-1)
	      return 1;
	else
	      return 0;	
}

int main()
{
	struct queue q;
	q.front = -1;
	q.rear = -1;

	int ch,n,X,E,F;
	
	do{
	    printf("1.Enqueue  2.Dequeue  3.Display  4.isFull  5.isEmpty  6.Exit \n");
	    printf("Enter your choice \n");
        scanf("%d",&ch);
    
	    switch(ch)
     	{
	        case 1 :
		              printf("Enter the no. to be enqueued \n");
				      scanf("%d",&n);
				      enqueue(&q, n);
				      break;
				  
	       	case 2 :
			          X = dequeue(&q);
			          printf("The dequeued element is %d  \n",X);
				      break;
				  
	     	case 3 :
			          display(&q);
			          break;
			      
			case 4 :
				      F = isFull(&q);
				      if(F)
				          printf("Queue is Full\n");
				      else
				          printf("Queue is not full\n");
				      break;
				      
	    	case 5 :
				      E = isEmpty(&q);
				      if(E)
				          printf("Queue is Empty\n");
				      else
				          printf("Queue is not empty\n");
				      break;
	    	
			case 6 :
			          exit(0);
	    }	
    }while(ch != 7);
    
return 0;	
}
