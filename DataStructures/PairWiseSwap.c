/*Sahaana Iyer
SE Comps
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int info;
  struct node *next;
}node;

typedef struct
{
  node *START;
}LL;

void insert(LL *ptr, int X)
{
  node *new;
  new = (node*)malloc(sizeof(node));
  new->info = X;
  new->next = NULL;

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
  }
}

void PairWiseSwap(LL *ptr)
{
  int temp;
  node *p;
  p = ptr->START;

  while(p != NULL && p->next != NULL)
  {
     temp = p->info;
     p->info = p->next->info;
     p->next->info = temp;

     p = p->next->next;
  }
}

void display(LL *l)
{

node *p;
p = l->START;
while(p != NULL)
{
printf("%d\t",p->info);
p = p->next;
}
printf("\n");
}

int main()
{
  LL ptr;
  ptr.START = NULL;
  int ch,x;
  while(1)
  {
     printf("1: Insert an element \n2: Pair Wise Swap \n3: Exit \n");
     printf("Enter your choice\n ");
     scanf("%d",&ch);

    switch(ch)
    {
        case 1: 
		         printf("Enter the element to be inserted\n ");
                 scanf("%d",&x);
                 insert(&ptr,x);
                 break;

        case 2: 
		         printf("Before Swapping : \n");
                 display(&ptr);
                 PairWiseSwap(&ptr);
                 printf("After Swapping : \n");
                 display(&ptr);
                 break;

        case 3:
        	     exit(0); 
    }
}
return 0;
}

/*OUTPUT :

1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
1
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
2
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
3
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
4
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
5
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
6
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
7
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
1
Enter the element to be inserted
1
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
2
Before Swapping :
1 2 3 4 5 6 7
After Swapping :
2 1 4 3 6 5 7
1: Insert an element 
2: Pair Wise Swap 
3: Exit 
Enter your choice
3
