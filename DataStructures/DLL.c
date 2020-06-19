/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include<stdio.h>
#include <stdlib.h>
#define max 20

struct node
{
  int info;
  struct node *next;
  struct node *prev;
};

struct node *START = NULL;

void Insert_begin(int );
void Insert_end(int );
void Insert_after(int , int );
void Insert_before(int , int );
void display();
void delete_begin();
void delete_end();
void delete_specific(int );
void delete_after(int );
void delete_before(int );
int count();

int main()
{
   int ch,n,val,C;
   do
   {
      printf("1: Insert node at beginning\n");  
      printf("2: Insert node at end\n");  
      printf("3: Insert node after a specific node\n");  
      printf("4: Insert node before a specific node\n");  
      printf("5: Delete node at beginning\n");  
      printf("6: Delete node at the end\n");  
      printf("7: Delete a specific node\n");
      printf("8: Delete after a specific node\n");
      printf("9: Delete before a specific node\n");
      printf("10: Count no. of nodes\n");
      printf("11: Display the linked list\n");  
      printf("12: EXIT\n");

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
                    printf("Enter value to be inserted\n");  
                    scanf("%d",&n);
                    printf("Enter value after which new node is to be inserted\n");  
                    scanf("%d",&val);
                    Insert_after(n, val);
                    break;

          case 4 :
                    printf("Enter value to be inserted\n");  
                    scanf("%d",&n);
                    printf("Enter value before which new node is to be inserted\n");  
                    scanf("%d",&val);
                    Insert_before(n, val);
                    break;

          case 5 : 
                    delete_begin();
                    break;

          case 6 :
                    delete_end();
                    break;

          case 7 :
                    printf("Enter value to be deleted\n");  
                    scanf("%d",&val);
                    delete_end(val);
                    break;

          case 8 :
                    printf("Enter value after which the node is to be deleted\n");  
                    scanf("%d",&val);
                    delete_after(val);
                    break;

          case 9 :
                    printf("Enter value before which the node is to be deleted\n");  
                    scanf("%d",&val);
                    delete_before(val);
                    break;
     
          case 10 :
                    C = count();
                    printf("No. of nodes is %d\n", C);
                    break;

          case 11 :
                    display();                     
                    break;

          case 12 : 
                    exit(0);

      }
   }while(ch != 13);

return 0;
}

void Insert_begin(int X)
{
   struct node *newnode;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;
   newnode -> prev = NULL;

   if(START == NULL)
   {
       START = newnode;
       START -> next = newnode;
       START -> prev = newnode;
   }
   else
   {
       newnode -> next = START;
       newnode -> prev = START -> prev;
       newnode -> prev -> next = newnode;
       START -> prev = newnode;
       START = newnode;
   }
}

void Insert_end(int X)
{
   struct node *newnode;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;
   newnode -> prev = NULL;

   if(START == NULL)
   {
       START = newnode;
       START -> next = newnode;
       START -> prev = newnode;
   }
   else
   {
       newnode -> prev = START -> prev;
       START -> prev -> next = newnode;
       newnode -> next = START;
       START -> prev = newnode;
   }
}

void Insert_after(int X, int val)
{
   struct node *newnode, *p;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;
   newnode -> prev = NULL;

   if(START == NULL)
   {
       START = newnode;
   }
   else
   {
       p = START;
       while((p -> info != val) && (p != NULL))
       {
           p = p -> next;
       }
       if(p == NULL)
       {
           printf("Node not found \n");
           
       } 
       /*else if(p -> next == NULL)
       {
           p -> next = newnode;
           newnode -> prev = p;           
       }*/
       else
       {
           newnode -> next = p -> next;
           p -> next -> prev = newnode;
           newnode -> prev = p;
           p -> next = newnode;
       }
   }
}

void Insert_before(int X, int val)
{
   struct node *newnode, *p;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;
   newnode -> prev = NULL;

   if(START == NULL)
   {
       START = newnode;
   }
   else if(START -> info == val)
        {
            newnode -> next = START;
            newnode -> prev = START -> prev;
            START -> prev -> next = newnode;
            START -> prev = newnode;
            START = newnode;
        }
       else
       {
           p = START;
           while((p -> info != val) && (p != NULL))
           {
               p = p -> next;
           }
           if(p != NULL)
           {
               newnode -> next = p;
               newnode -> prev = p -> prev;
               p -> prev -> next = newnode;
               p -> prev = newnode;
           } 
           else
           {
               printf("Node not found\n");
           }
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
       printf("%d\n", p->info);
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
        START -> next -> prev = START -> prev;  
        START -> prev -> next = START -> next;    
        START = START -> next;
        printf("Deleted node is %d\n", p->info);
        free(p);
     }
}

void delete_end()
{
   struct node *p;
     if(START == NULL)
     {
        printf("List is Empty\n");
        return;
     }
     else
     {
        p = START -> prev;
        START -> prev -> prev -> next = START;
        START -> prev = START -> prev -> prev;
		printf("Deleted node is %d\n", p->info);
        free(p);
     }
}

void delete_specific(int val)
{
   struct node *ptr, *p ;
     if(START == NULL)
     {
        printf("List is Empty\n");
        return;
     }
     else if(START -> info == val)
     {
        p = START;
       	ptr = START -> prev;
       	START -> next -> prev = ptr;
       	START -> prev -> next = START -> next;
        START = START -> next;
	    printf("Deleted node is %d\n", p -> info);
        free(p);
     }
     else
     {
       	ptr = START;
       	while( (ptr -> next != START) && (ptr -> info != val))
        {
       	    ptr = ptr -> next;
   	    }   
		if( (ptr -> info != val) && (ptr -> next == START) )
		{
			ptr -> prev -> next = START;
			START -> prev = ptr -> prev;
			printf("Deleted node is %d\n", ptr->info);
			free (ptr);
		}
		else if(ptr -> next != START)
		{
			ptr -> next -> prev = ptr -> prev;
            ptr -> prev -> next = ptr -> next;
            printf("Deleted node is %d\n", ptr->info);
            free(ptr);
	    }   
		else
		{
			printf("Node not found \n");
		}    
     }
}

void delete_before(int val)
{
   struct node *ptr, *temp;
   if(START == NULL)
   {
      printf("Link is Empty\n");
      return;
   }
   else
   {
      ptr = START;
      while((ptr->info !=  val) && (ptr != NULL))
      {
         ptr = ptr->next;
      }
      if(ptr != NULL)
      {
        temp = ptr -> prev;
        temp -> prev -> next = ptr ;
        ptr -> prev = temp -> prev;
        printf("Deleted node is %d\n", temp->info);
        free(temp);
      }
      else
      {
         printf("Node not found\n");
      }
 }

}

void delete_after(int val)
{
   struct node *ptr, *temp;
   if(START == NULL)
   {
      printf("Link is Empty\n");
      return;
   }
   else
   {
      ptr = START;
      while((ptr->info !=  val) && (ptr != NULL))
      {
         ptr = ptr->next;
      }
      if(ptr != NULL)
      {
         temp = ptr->next;
         ptr->next = temp->next;
         temp -> next -> prev = ptr;
         printf("Deleted node is %d\n", temp->info);
         free(temp);
      }
      else
      {
         printf("Node not found\n");
      }
   }
}

int count()
{
  int count = 0;
  struct node *ptr;
  ptr = START;

  while(ptr->next != START)
  {
     count++;
     ptr = ptr->next;
  }
  count++;
  return count; 
}

/*OUTPUT :
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
1
Enter value to be inserted
10
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
2
Enter value to be inserted
40
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
3
Enter value to be inserted
20
Enter value after which new node is to be inserted
10
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
4
Enter value to be inserted
30
Enter value after which new node is to be inserted
40
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
5
Deleted node is 10
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
6
Deleted node is 40
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
7
Enter value to be deleted
20
Deleted node is 20
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
11
30
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
10
No. of nodes is 1
1: Insert node at beginning 
2: Insert node at end  
3: Insert node after a specific node  
4: Insert node before a specific node  
5: Delete node at beginning
6: Delete node at the end  
7: Delete a specific node
8: Delete after a specific node
9: Delete before a specific node
10: Count no. of nodes
11: Display the linked list  
12: EXIT
Enter the choice
12
*/

