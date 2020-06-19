/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int info, priority;
  struct queue *next;
};

struct queue *START = NULL;

void Insert(int );
void delete();
void display();
int main()
{
  struct queue s[100];
  
  struct queue *new;
  new = (struct queue * ) malloc (sizeof (struct queue));
  struct queue *getnode (int, int);
 
  int choice,x;

  while(1)
  {
     printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
     printf("Enter your choice:\n");
     scanf("%d", &choice);
 
     switch(choice)
     {
         case 1:  
                 printf("Enter the value to be inserted\n");
                 scanf("%d", &x);
                 Insert(x);
                 break;

         case 2:  
                 delete();
                 break;
 
         case 3:  
                 display();
                 break;

         case 4:  
                 exit(0);
     }
   }
}

struct queue *getnode(int x,int y)
{
   struct queue *p;
   p = (struct queue*)malloc(sizeof(struct queue));
   p-> info = x;
   p-> priority = y;
   p-> next = NULL;
   return p;
}

void Insert(int x)
{
   struct queue *new, *ptr, *prev;
   int y;
   printf("Insert priority of element\n");
   scanf("%d", &y);
   new = getnode(x,y);

   if(START==NULL)
   {
      START = new;
   }
   else if(new->priority < START->priority)
   {
      new->next = START;
      START = new;
   }
   else
   {
      prev = START;
      ptr = START;
      while(ptr!=NULL && ptr->priority <= new->priority)
      {
         ptr = ptr->next;
      }
      if(ptr != NULL)
      {
         new->next = ptr;
         prev->next = new;
      }
      else
      {
         prev->next=new;
      }
   }
}

void delete()
{
   struct queue *ptr;
   if(START == NULL)
   {
      printf("List is empty\n");
      return;
   }
   else
   {
      ptr= START;
      START = START->next;
      printf("Deleted element is %d\n", ptr->info);
      free(ptr);
   }
}

void display()
{
   struct queue *p;
   if (START== NULL)
   {
      printf("List is empty\n");
   }
   else
   {
      p=START;
      while(p!=NULL)
      {
         printf("%d\n", p->info);
         p=p->next;
      }
   }
}


/*OUTPUT :
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
1
Enter the value to be inserted
10
Insert priority of element
2
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
1
Enter the value to be inserted
20
Insert priority of element
3
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
3
10
20
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
2
Deleted element is 10
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
1
Enter the value to be inserted
40
Insert priority of element
2
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
3
40
20
 1.Insert
 2.Delete
 3.Display
 4.Exit
Enter your choice:
4
*/
