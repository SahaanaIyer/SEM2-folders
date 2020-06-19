/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int info;
  struct node *next,*prev;
}node;

typedef struct
{
  node *START;
}LL;

void insert(LL *ptr, int X)
{
  node *new;
  new = (node* ) malloc ( sizeof(node) );
  new->info = X;
  new->next = NULL;
  new->prev = NULL;

  if(ptr->START == NULL)
  {
     ptr->START = new;
     return;
  }
  else
  {
     node *p;
     p = ptr->START;
     while(p->next != NULL)
     {
	     p = p->next;
     }
     p->next = new;  
     new->prev = p;
  }
}

void Pair(LL *ptr, int x)
{
  node *p, *q;
  p = ptr->START;
  q = ptr->START;

  while(q->next != NULL)
  {
     q = q->next;	  
  }

  int flag = 0;

  while(p != q && q->next != p)
  { 
    if(p->info + q->info == x)
    {
        flag = 1; 
        printf("(%d,%d) ",q->info,p->info);
        p = p->next;
        q = q->prev;
    }
    else if(p->info + q->info < x)
    {
        p = p->next;
    }
    else
    {
    	q = q->prev;
	}
  }

  if(flag == 0)
  {
      printf("No pair found");
  }
  printf("\n");
}

void display(LL *ptr)
{
  node *p;
  p = ptr->START;
  while(p != NULL)
  {
     printf("%d\t", p->info);
     p = p->next;
  }
  printf("\n");
}

int main()
{
  LL ptr;
  ptr.START = NULL;
  int ch,X,x;
  while(1)
  {
    printf("1: Insert in the DLL \n2: Find the pairs \n3: Exit\n");
    printf("Enter your choice \n");
    scanf("%d",&ch);

    switch(ch)
    {
         case 1: 
		           printf("Enter the element to be inserted in sorted DLL in the increasing order\n");
                   scanf("%d",&X);
                   insert(&ptr, X);
                   printf("Sorted DLL :\n");
                   display(&ptr);
                   break;

         case 2: 
		            printf("Enter the value of x\n ");
                    scanf("%d",&x);
                    Pair(&ptr, x);
                    break;
                    
         case 3:
         	        exit(0);

    }
  }
return 0;
}

/*
OUTPUT :
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
1
Enter the element to be inserted in sorted DLL in the increasing order
1
Sorted DLL :
1
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
1
Enter the element to be inserted in sorted DLL in the increasing order
2
Sorted DLL :
1       2
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
1
Enter the element to be inserted in sorted DLL in the increasing order
3
Sorted DLL :
1       2       3
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
1
Enter the element to be inserted in sorted DLL in the increasing order
4
Sorted DLL :
1       2       3       4
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
2
Enter the value of x
5
(4,1) (3,2)
1: Insert in the DLL
2: Find the pairs
3: Exit
Enter your choice
3*/
