#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10

struct queue
{
	int a[max];
	int front, rear;
};

void enqueue(struct queue *s,int x)
{
  if (((s->rear + 1)%max) == s->front)
    {
     printf("Queue Overflow\n");
     return;
    }
  else if(s->front==-1 && s->rear==-1)
    {
     s->front = (s->front + 1) % max;
     s->rear = (s->rear + 1) % max;
     s->a[s->rear]=x;
    }
  else
    {
     s->rear = (s->rear + 1) % max;
     s->a[s->rear]=x;
    }
}

int dequeue(struct queue *s)
{
  int y;
  if (s->front==-1 && s->rear==-1)
    {
      printf("Queue Underflow\n");
      return 0;
    }
  else if(s->front==s->rear)
    {
      y=s->a[s->front];
      s->front=-1;
      s->rear=-1;
     
      return y;
    }
  else
    {
     y=s->a[s->front];
     s->front= (s->front + 1) % max;
     
     return y;
    }
}

void display(struct queue *p)
{
	int i;
    if(p->front==-1 && p->rear==-1)
        printf("Queue Underflow\n");
    else
    {
       for(i = p->front; i != p->rear; i = (i+1) % max)
       {
          printf("%d  \t",p->a[i]);
       }
       printf("%d  \t",p->a[i]);
    }
    printf("\n");
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
    if(((q->rear + 1) % max) == q->front)
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
