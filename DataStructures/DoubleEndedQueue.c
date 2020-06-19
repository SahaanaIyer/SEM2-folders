/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>
#define max 20

struct queue
{
   int a[max];
   int front;
   int rear;
};

void Insert_front(struct queue *, int );
void Insert_rear(struct queue *, int );
void delete_front(struct queue *);
void delete_rear(struct queue *);
void display();

int main()
{
   struct queue q;
   int flag = 0, ch, c, x;
   q.front = -1;
   q.rear = -1;

   while(1)
   {
      printf("1: Input restricted \n2: Output restricted \n3: Exit \n");
      printf("Enter your choice \n");
      scanf("%d",&ch);
 
      switch(ch)
      {
         case 1: 
                 flag = 1;
                 while(flag)
                 {
                     printf(" 1: Insert at end \n 2: Delete from beginning \n 3: Delete from end \n 4: Exit \n");
                     printf(" Enter your choice \n");
                     scanf("%d",&c);
                      
                     switch(c)
                     {
                        case 1:    
                                   printf(" Enter the value to be inserted \n");
                                   scanf("%d",&x);
                                   Insert_rear(&q, x);
                                   break;

                        case 2: 
                                   delete_front(&q);
                                   break;
                
                        case 3: 
                                   delete_rear(&q);
                                   break;

                        case 4:
                                   flag = 0;
                                   break;

                     }
                }
                break;

       case 2:  
                flag = 1;
                while(flag)
                {
                     printf(" 1: Insert at beginning \n 2: Insert at end \n 3: Delete from beginning \n 4: Exit \n");
                     printf(" Enter your choice \n");
                     scanf("%d",&ch);

                     switch(ch)
                     {
                        case 1: 
                                   printf("Enter the value to be inserted \n");
                                   scanf("%d",&x);
                                   Insert_front(&q, x);
                                   break;

                        case 2: 
                                   printf("Enter the value to be inserted \n");
                                   scanf("%d",&x);
                                   Insert_rear(&q, x);
                                   break;

                        case 3: 
                                   delete_front(&q);
                                   break;

                        case 4:  
                                   flag = 0;
                                   break;
                     }

               }
               break;

     case 3: 
               exit(0);
     }
  }
return 0;
}

void Insert_front(struct queue *q, int X)
{
   if( (q->front == 0 && q->rear == max - 1) || (q->front == q->rear + 1) )
   {
      printf("Queue Overflow \n");
      return;
   }
   else if(q->front == -1 && q->rear == -1)
   {
      q->front++;
      q->rear++;
      q->a[q->front] = X;
   }
   else if(q->front == 0)
   {
      q->front = max-1;
      q->a[q->front] = X;
   }
   else
   {
      q->front--;
      q->a[q->front] = X;
   }
}

void Insert_rear(struct queue *q, int X)
{
   if (( q->front == 0 && q->rear == max - 1) || (q->front == q->rear + 1) )
   {
      printf("Queue Overflow\n");
      return;
   }
   else if(q->front == -1 && q->rear == -1)
   {
      q->front++;
      q->rear++;
      q->a[q->rear] = X;
   }
   else if( q->rear == max - 1)
   {
      q->rear = 0;
      q->a[q->rear] = X;
   }
   else
   {
   	  q->rear++;
   	  q->a[q->rear] = X;
   }
}

void delete_front(struct queue *q)
{
   int X;

   if ( q->front == -1 && q->rear == -1)
   {
      printf("Queue Underflow\n");
      return;
   }
   else if(q->front == q->rear)
   {
      X = q->a[q->front];
      q->front = -1;
      q->rear = -1;
     
      printf("Deleted element is %d \n", X);
   }
   else
   {
      X = q->a[q->front];
      q->front++;
         
	  printf("Deleted element is %d \n", X);
   }
}

void delete_rear(struct queue *q)
{ 
   int X;

   if( q->front == -1 && q->rear == -1)
   {
      printf("Queue Underflow \n");
      return;
   }
   else if(q->front == q->rear)
   {
      X = q->a[q->rear];
      q->front--;
      q->rear--;
      
      printf("Deleted element is %d \n", X);
   }
   else
   {
   	  X = q->a[q->rear];
   	  q->rear--;
   	  
   	  printf("Deleted element is %d \n", X);
   }
}

/*OUTPUT:
1: Input restricted
2: Output restricted
3: Exit
Enter your choice
1
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 1
 Enter the value to be inserted
 10
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 1
 Enter the value to be inserted
 20
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 1
 Enter the value to be inserted
 30
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 2
 Deleted element is 10
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 3
 Deleted element is 30
 1: Insert at end
 2: Delete from beginning
 3: Delete from end
 4: Exit
 Enter your choice
 4
1: Input restricted
2: Output restricted
3: Exit
Enter your choice
2
 1: Insert at beginning
 2: Insert at end
 3: Delete from beginning
 4: Exit
 Enter your choice
 1
 Enter the value to be inserted
 10
 1: Insert at beginning
 2: Insert at end
 3: Delete from beginning
 4: Exit
 Enter your choice
 2
 Enter the value to be inserted
 30
 1: Insert at beginning
 2: Insert at end
 3: Delete from beginning
 4: Exit
 Enter your choice
 3
 Deleted element is 10
 1: Insert at beginning
 2: Insert at end
 3: Delete from beginning
 4: Exit
 Enter your choice
 3
 Deleted element is 20
 1: Insert at beginning
 2: Insert at end
 3: Delete from beginning
 4: Exit
 Enter your choice
 4
1: Input restricted
2: Output restricted
3: Exit
Enter your choice
3
*/
