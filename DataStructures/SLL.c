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
void delete_all_occurences(int );
int count();
void sort();

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
      printf("8: Delete all occurences\n");
      printf("9: Delete after a specific node\n");
      printf("10: Delete before a specific node\n");
      printf("11: Count no. of nodes\n");
      printf("12: Sort the list\n");
      printf("13: Display the linked list\n");  
      printf("14: EXIT\n");

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
                    printf("Enter value to be deleted\n");  
                    scanf("%d",&val);
                    delete_all_occurences(val);
                    break;

          case 9 :
                    printf("Enter value after which the node is to be deleted\n");  
                    scanf("%d",&val);
                    delete_after(val);
                    break;

          case 10 :
                    printf("Enter value before which the node is to be deleted\n");  
                    scanf("%d",&val);
                    delete_before(val);
                    break;
     
          case 11 :
                    C = count();
                    printf("No. of nodes is %d\n", C);
                    break;

          case 12 :
                    sort();
                    break;

          case 13 :
                    display();                     
                    break;

         case 14 : 
                    exit(0);

      }
   }while(ch != 15);

return 0;
}

void Insert_begin(int X)
{
   struct node *newnode;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;

   if(START == NULL)
   {
       START = newnode;
   }
   else
   {
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
   }
   else
   {
       p = START;
       while(p -> next != NULL)
       {
           p = p -> next;
       }
       p -> next = newnode;
   }
}

void Insert_after(int X, int val)
{
   struct node *newnode, *p;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;

   if(START == NULL)
   {
       START = newnode;
   }
   else
   {
       p = START;
       while((p -> info != val)&&(p != NULL))
       {
           p = p -> next;
       }
       if(p != NULL)
       {
           newnode -> next = p -> next;
           p -> next = newnode;
       } 
       else
       {
           printf("Node not found\n");
       }
   }
}

void Insert_before(int X, int val)
{
   struct node *newnode, *p, *prev;
   newnode = (struct node *) malloc (sizeof (struct node));
   newnode -> info = X;
   newnode -> next = NULL;

   if(START == NULL)
   {
       START = newnode;
   }
   else if(START -> info == val)
        {
            newnode -> next = START;
            START = newnode;
        }
       else
       {
           prev = START;
           p = START;
           while((p -> info != val)&&(p != NULL))
           {
               prev = p;
               p = p -> next;
           }
           if(p != NULL)
           {
               prev -> next = newnode;
               newnode -> next = p;
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
       while(p != NULL)
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
        while(p -> next != NULL)
        {
            prev = p;
            p = p -> next;
        }
        prev -> next = NULL;
        printf("Deleted node is %d\n", p->info);
        free(p);
     }
}

void delete_specific(int val)
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
        while((p -> info != val) && (p != NULL))
        {
            prev = p;
            p = p -> next;
        }
        if(p == NULL)
        {
            printf("Node not found\n");
        }
        else if(START -> info == val)
             {
                  p = START;
                  START = START -> next;
                  printf("Deleted node is %d\n", p->info);
                  free(p);
             }
             else
             {
                  prev -> next = p -> next;
                  printf("Deleted node is %d\n", p->info);
                  free(p);
             }
     }
}

void delete_before(int val)
{
   struct node *ptr, *prev, *temp;
   if(START == NULL)
   {
      printf("Link is Empty\n");
   }
   else
   {
      temp = START;
      ptr = START;
      prev = START;
      while((ptr->info !=  val) && (ptr != NULL))
      {
         temp = prev;
         prev = ptr;
         ptr = ptr->next;
      }
      if(ptr != NULL)
      {
        temp->next = ptr;
        printf("Deleted node is %d\n", prev->info);
        free(prev);
      }
      else
      {
         printf("Node not found\n");
      }
 }

}

void delete_after(int val)
{
   struct node *ptr, *prev;
   if(START == NULL)
   {
      printf("Link is Empty\n");
   }
   else
   {
      ptr = START;
      prev = START;
      while((ptr->info !=  val) && (ptr != NULL))
      {
         ptr = ptr->next;
      }
      if(ptr != NULL)
      {
         prev = ptr->next;
         ptr->next = prev->next;
         printf("Deleted node is %d\n", prev->info);
         free(prev);
      }
      else
      {
         printf("Node not found\n");
      }
   }
}

void delete_all_occurences(int val)
{
    struct node *p, *prev, *temp;
    if(START == NULL)
    {
       printf("List is Empty\n");
       return;
    }
    else
    {
       prev = START;
       p = START;
       while(p != NULL)
       {
          while((p -> info != val) && (p != NULL))
          {
              prev = p;
              p = p -> next;
          }

          if(START -> info == val)
          {
              p = START;
              START = START -> next;
              printf("Deleted node is %d\n", p->info);
              free(p);
          }
          else
          {
              prev -> next = p -> next;
              temp = p;
              p = p -> next;
              printf("Deleted node is %d\n", temp->info);
              free(temp);
          }
       }
    }
}

int count()
{
  int count = 0;
  struct node *ptr;
  ptr = START;

  while(ptr != NULL)
  {
     count++;
     ptr = ptr->next;
  }
  return count; 
}

void sort()
{
  int temp;
  struct node *ptr1, *ptr2;
  if(START == NULL)
  {
     printf("List is Empty\n");
     return;
  }
  else if(START->next == NULL)
  {
     printf("List is already sorted\n");
     return;
  }
  else
  {
     ptr1 = START;
     ptr2 = ptr1->next;
     while(ptr1->next != NULL)
     {
        while(ptr2 != NULL)
        {
           if(ptr1->info > ptr2->info)
           {
              temp = ptr1->info;
              ptr1->info = ptr2->info;
              ptr2->info = temp;
           }
           ptr1 = ptr1->next;
           ptr2 = ptr2->next;
        }
     }
  }
}


/*
OUTPUT:
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
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
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
2
Enter value to be inserted
20                                                                                                                                   0
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
3
Enter value to be inserted
30
Enter value after which new node is to be inserted
10
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
4
Enter value to be inserted
40
Enter value before which new node is to be inserted
20
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
11
No. of nodes is 4
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
10
Enter value before which new node is to be deleted
40
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
6
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
13
10
40
1: Insert node at beginning  
2: Insert node at end 
3: Insert node after a specific node 
4: Insert node before a specific node  
5: Delete node at beginning  
6: Delete node at the end 
7: Delete a specific node
8: Delete all occurences
9: Delete after a specific node
10: Delete before a specific node
11: Count no. of nodes
12: Sort the list
13: Display the linked list 
14: EXIT
Enter the choice
14
*/
