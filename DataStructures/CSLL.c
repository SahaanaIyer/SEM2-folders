/*Sahaana Iyer
SE Comps
Batch B
8609*/


#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define max 20

struct node
{
  int info;
  struct node *next;
};

struct node *START = NULL;

void Insert_begin(int );
void Insert_end(int );
void display();
void delete_begin();
void delete_end();

int main()
{
   int ch,n,val,C;
   do
   {
      printf("1: Insert node at beginning\n");  
      printf("2: Insert node at end\n"); 
      printf("3: Delete node at beginning\n");  
      printf("4: Delete node at the end\n");  
      printf("5: Display the circular linked list\n");  
      printf("6: EXIT\n");

      printf("Enter the choice\n");
      scanf("%d",&ch);

      switch(ch)
      {
          case 1 :
                    printf("Enter value to be inserted\n");  
                    scanf("%d",&n);
                    Insert_begin(n);
                    break;

          case 2 :
                    printf("Enter value to be inserted\n");  
                    scanf("%d",&n);
                    Insert_end(n);
                    break;
           
          case 3 : 
                    delete_begin();
                    break;

          case 4 :
                    delete_end();
                    break;

          
          case 5 :
                    display();                     
                    break;

          case 6 : 
                    exit(0);

      }
   }while(ch != 7);

return 0;
}

void Insert_begin(int X)
{
   struct node *newnode, *ptr;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;

   if(START == NULL)
   {
       START = newnode;
       START->next=newnode;
   }
   else
   {
       ptr = START;
       while(ptr -> next != START)
       {
          ptr = ptr -> next;
       }
       ptr -> next = newnode;
       newnode -> next = START;
       START = newnode;
   }
}

void Insert_end(int X)
{ 
   struct node *newnode,*p;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;

   if(START == NULL)
   {
       START = newnode;
       START -> next = newnode;
   }
   else
   {
       p = START;
       while(p -> next != START)
       {
           p = p -> next;
       }
       p -> next = newnode;
       newnode -> next = START;
      
   }
}

void display()
{
    struct node *p;
    if(START == NULL)
    {
       printf("List is Empty\n");
       return;
    }
    else
    {
       p = START;
       while(p->next != START)
       {
           printf("%d\n", p->info);
           p = p -> next;
       }
    }
}

void delete_begin()
{
   struct node *p;
     if(START == NULL)
     {
        printf("List is Empty\n");
        return;
     }
     else
     {
        p = START;
        while(p -> next != START)
        {
           p = p -> next;
        }
        p -> next = START -> next;
        p = p -> next;
        START = START -> next;
        printf("Deleted node is %d\n", p->info);
        free(p);
     }
}

void delete_end()
{
   struct node *p, *prev;
     if(START == NULL)
     {
        printf("List is Empty\n");
        return;
     }
     else
     {
        prev = START;
        p = START;
        while(p -> next != START)
        {
            prev = p;
            p = p -> next;
        }
        prev -> next = START;
        printf("Deleted node is %d\n", p->info);
        free(p);
     }
}
/*

OUTPUT :

1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
1
Enter value to be inserted
20
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
2
Enter value to be inserted
30
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
1
Enter value to be inserted
10
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
3
Deleted node is 10
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
4
Deleted node is 30
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
5
20
1: Insert node at beginning
2: Insert node at end
3: Delete node at beginning
4: Delete node at the end
5: Display the circular linked list 
6: EXIT
Enter the choice
6
*/
