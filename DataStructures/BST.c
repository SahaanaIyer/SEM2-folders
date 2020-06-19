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
  struct node *left;
  struct node *right;
};

struct node *ROOT = NULL;

void Insert(struct node *, int );
void delete(struct node *, int );
void Inorder(struct node * );
void Preorder(struct node * );
void Postorder(struct node * );

void main()
{
     int ch, x;
     while(1)
	{
		printf("1: Insert an element\n");
		printf("2: Delete an element\n");
		printf("3: Inorder traversal\n");
		printf("4: Preorder Traversal\n");
		printf("5: Postorder Traversal\n");
		printf("6: Exit\n");

		printf("Enter your choice : \n");
		scanf("%d",&ch);

		switch(ch)
		{
		     case 1:   
                     printf("Enter the value to be inserted : \n");
				     scanf("%d",&x);
			  	     Insert(ROOT, x);
				     break;

		     case 2:   
                     printf("Enter the value to be deleted \n");
				     scanf("%d",&x);
				     delete(ROOT,x);
				     break;
	
		     case 3:	
                     Inorder(ROOT);
			         break;

       	     case 4:	
                     Preorder(ROOT);
			         break;

 		     case 5:	
                     Postorder(ROOT);
				     break;

             case 6:
                     exit(0);
        }		
    }
}
  
void Insert(struct node *p, int val)
{
     struct node *newnode, *parent, *t;
     newnode = (struct node*) malloc (sizeof (struct node));
	newnode->info = val;
	newnode->left = NULL;
     newnode->right = NULL;

     if( ROOT == NULL)
     {
         ROOT = newnode;
     }
     else if( newnode->info <= ROOT->info && ROOT->left == NULL)
     {
         ROOT->left = newnode;
     }
     else
     {
         parent = ROOT;
         t = ROOT;
         while(t != NULL)
         {
             if(newnode->info < t->info)
             {
                 parent = t;
                 t =  t->left;
             }
             else
             {
                 parent = t;
                 t =  t->right;
             }
          }
          
          if(newnode->info < parent->info)
          {
              parent->left = newnode;
          }
          else
          {
              parent->right = newnode;
          }
     }
}

void delete(struct node *p, int val)
{
	int flag = 0;
	struct node *parent, *t, *r;
	t = p;
	parent = NULL;
	
	while(t != NULL)
	{
		if(t->info > val)
		{
			parent = t;
			t = t->left;
		}
		else if(val > t->info)
		{
			parent = t;
			t = t->right;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		if(t->left == NULL && t->right == NULL)
		{
			if(parent->left == t)
			{
				parent->left = NULL;
				free (t);
			}
			else
			{
				parent->right = NULL;
				free (t);
			}
		}
		else if(t->left != NULL && t->right == NULL)
		{
			if(parent->right == t)
			{
				parent->right = t->left;
				free(t);
			}
			else
			{
	               parent->left = t->left;
				free(t);
			}
		}
		else if(t->left == NULL && t->right != NULL)
		{
			if(parent->left == t)
			{
				parent->left = t->right;
				free(t);
			}
			else
			{
	               parent->right = t->right;
				free(t);
			}
		}
		else if(t->left != NULL && t->right != NULL)
		{
			r = t->left;
			while(r->right != NULL)
			{
				r = r->right;
			}
               t->info = r->info;
		     delete (t->left, r->info);
		}
	}
	
     if(flag == 0)
	{
		printf("Node not found\n");
	}
}


void Inorder(struct node *t)
{
	if(t != NULL)
	{
          Inorder (t->left);
          printf("%d \n", t->info);
		Inorder(t->right);
	}
}

void Preorder(struct node *t)
{
	if(t != NULL)
	{
		printf("%d \n", t->info);
		Preorder(t->left);
		Preorder(t->right);
	}
}

void Postorder(struct node *t)
{
	if(t != NULL)
	{
		
		Postorder(t->left);
		Postorder(t->right);
		printf("%d \n", t->info);
	}
}

/* OUTPUT :
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
1
Enter the value to be inserted :
25
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
1
Enter the value to be inserted :
15
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
1
Enter the value to be inserted :
30
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
3
15
25
30
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
4
25
15
30
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
5
15
30
25
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
2
Enter the value to be deleted
30
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
3
15
25
1: Insert an element
2: Delete an element
3: Inorder traversal
4: Preorder Traversal
5: Postorder Traversal
6: Exit
Enter your choice :
6
*/
