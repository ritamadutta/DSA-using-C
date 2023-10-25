#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node BST;

BST *Insert(BST*, int);
void Inorder(BST*);
void Preorder(BST*);
void Postorder(BST*);
int search (BST*,int);

BST* root = NULL;

int main()
{
    int choice,x,find,f;
    while (1)
    {
        printf ("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf ("Enter the data to be inserted: ");
                scanf ("%d", &x);
                root = Insert(root, x);
            break;
        
        case 2: if (root == NULL)
                printf("Tree is empty...!!");
                
                else
                Inorder(root);
            break;    
        
        case 3: if (root == NULL)
                printf("Tree is empty...!!");
                
                else
                Preorder(root);
            break;
        
        case 4: if (root == NULL)
                printf("Tree is empty...!!");
                
                else
                Postorder(root);
            break;
        
        case 5: if (root == NULL)
                printf("Tree is empty...!!");

                else
                {
                  printf("Enter the data to be searched: ");
                  scanf("%d", &find);
                
                  f = search(root, find);
                
                  if (f == 1)
                  {
                      printf("\n %d is found..!! ",find);
                  }
                  else
                  {
                      printf("\n %d is not found \n",find);
                  }
                }
            break;    
       
        case 6: exit(1);
            break;

        default: printf("Wrong Choice.....!! Try again");
            break;
        }
    }
    
}

BST* Insert(BST* root, int x)
{
    BST *ptr = root;
    BST *new1;
    new1 = (BST*)malloc(sizeof (BST));

    new1->data = x;
    new1->lchild = NULL;
    new1->rchild = NULL;

    if (root == NULL)
    {
        root = new1;
        return(root);
    }
    while (1)
    {
        if (ptr->data > x)
        {
            if (ptr->lchild == NULL)
            {
                ptr->lchild = new1;
                break;
            }
            else
            {
                ptr = ptr->lchild;
            }
        }
        else
        {
            if (ptr -> rchild == NULL)
            {
                ptr -> rchild = new1;
                break;
            }
            else
            {
                ptr = ptr -> rchild; 
            }
        }  
    }
    return(root);
}

void Inorder(BST* root)
{
    if (root->lchild != NULL)
    {
        Inorder(root->lchild);
    }

    printf("%d ,", root->data);
    
    if (root->rchild != NULL)
    {
        Inorder(root->rchild);
    }
    
}

void Preorder (BST* root)
{
    printf("%d ,", root->data);

    if (root->lchild != NULL)
    {
        Inorder(root->lchild);
    }
    
    if (root->rchild != NULL)
    {
        Inorder(root->rchild);
    }
    
}

void Postorder (BST* root)
{
    if (root->lchild != NULL)
    {
        Inorder(root->lchild);
    }
    
    if (root->rchild != NULL)
    {
        Inorder(root->rchild);
    }
    
    printf("%d ,", root->data);
}

int search (BST* root ,int find)
{
    BST* ptr = root;
    int flag = 0;

    while( ptr != NULL && flag == 0)
    {
        if (ptr->data == find)
        {
            flag = 1;
            break;
        }
        else if (ptr->data > find)
        {
            ptr = ptr->lchild;
        }
        else
        {
            ptr = ptr->rchild;
        }
    }
    if (flag == 0)
    {
        return (0);
    }
    else
    {
        return (1);
    }
    
}