//Write a c program to create a singly linklist and perform 
//1. Display the list
//2.inserting an item at user specified position
#include <stdio.h>
#include <stdlib.h>
 struct node
 {
    int data;
    struct node *next;
 };
 typedef struct node NODE;
 NODE *head = NULL;

 void insert_at_any_pos();
 void display();

int main()
{
   int choice;
   while (1)
   {
    printf ("\n 1.Insert at Any Position \n 2.Display \n 3.Exit");
    printf ("\n Enter your Choice:\n");
    scanf ("%d",&choice);
    switch(choice)
    {
        case 1: insert_at_any_pos();
        break;

        case 2:display();
        break;

        case 3:exit(1);
        break;
    }
   }

    
}

 void insert_at_any_pos()
 {
    int pos, i;
    NODE *new1, *p;
    new1 = (NODE*)malloc(sizeof (NODE));
    
    printf ("Enter the Data: \n");
    scanf ("%d", &new1->data);

    new1->next = NULL;

    if (head == NULL)
    {
        head = new1;
    }
    else 
    {
        printf ("Enter the Position: ");
        scanf ("%d",&pos);

        if (pos == 1)
        {
            new1->next = head;
            head = new1;
        }
        else
        {
            i=1; //i calculating the value like pos 1,2,3..
            p = head;// calculating the node
            while (i!= pos-1 && p->next!= NULL)
            {
                i++;
                p=p->next;
            }
            if(i = pos && p->next != NULL)
            {
                new1->next = p->next;
                p->next = new1;
            }
            else if (i = pos && p->next == NULL)
            {
                p->next = new1;
            }
            else
            {
                printf("Position not Exits!!");
            }
        
        }
    }
    

 }

 void display()
 {
    NODE *p;
    if (head == NULL)
    {
        printf ("\n List is EMPTY.....");
    }
    else
    {
        printf("Linklist is : ");
        printf("Head-> ");
        for (p = head; p != NULL; p = p->next)
        {
            printf ("|%d|->",p->data);
            printf ("Next->|%d|",p->next);
        }
    }
    
 }