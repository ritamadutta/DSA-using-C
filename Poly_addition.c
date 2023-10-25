//Write a program in c to input two polynomials using singly linklist and perform addition on them

#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int cof,exp;
    struct node *next;
};
typedef struct node pol;
void main()
{
    pol *head1=NULL;	
    pol *head2=NULL;  	 
    pol *head3=NULL;	
    pol *p=head1,*nw1;
    pol *q=head2,*nw2;
    pol *r=head3,*nw3;
    
    int i=1,j=1,k=1,n,m,f,t,c,e;
    printf("enter the number of term of 1st polynomial : ");
    scanf("%d",&n);
    printf("enter the number of term of 2nd polynomial : ");
    scanf("%d",&m);
    printf("enter the coefficient and exponent  for pol1:\n");
    while(i<=n) 
    {
       
        nw1=(pol*)malloc(sizeof(pol));
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        if(head1==NULL)
        {
            head1=nw1;
            head1->next=NULL;
        }
        else
        {
        	p=head1;
        	while(p->next!=NULL)
        	{
				 p=p->next;
            }
            p->next=nw1;
            nw1->next=NULL;
        }
        i++;

    }
   
    printf("eneter the coefficient and exponent  for pol2:\n");
    while(j<=m)	
    {
        p=head2;
        nw1=(pol*)malloc(sizeof(pol));
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        if(head2==NULL)
        {
            head2=nw1;
            head2->next=NULL;
        }
        else
        {
        	while(p->next!=NULL)
        	{
				 p=p->next;
            }
            p->next=nw1;
            nw1->next=NULL;
        }
        j++;

    }
    
    printf("\n1st polynomial is : ");
    for(p=head1;p!=NULL;p=p->next)	
    {
		if(p->exp==0)
	    	printf(" (%d)",p->cof);
	    else if(p->next==NULL)
	    	printf(" (%dX^%d)",p->cof,p->exp);
		else
			printf(" (%dX^%d )+",p->cof,p->exp);
    }
    printf("\n2nd polynomial is : ");
    for(q=head2;q!=NULL;q=q->next)	
    {
        if(q->exp==0)
	    	printf(" (%d)",q->cof);
	    else if(q->next==NULL)
	    	printf(" (%dX^%d)",q->cof,q->exp);
		else
			printf(" (%dX^%d )+",q->cof,q->exp);
	}				
    printf("\n");
    p=head1;
    q=head2;
    
    while(p!=NULL&&q!=NULL)	
    {
      
        if(p->exp==q->exp) 
        {
            c=p->cof+q->cof;
            e=p->exp;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)
        {
            c=p->cof;
            e=p->exp;
            p=p->next;
        }
        else if(p->exp<q->exp)
        {
            c=q->cof;
            e=q->exp;
            q=q->next;
        }
        nw3=(pol*)malloc(sizeof(pol));
        nw3->cof=c;
        nw3->exp=e;
        if(head3==NULL)
        {
            head3=nw3;
            head3->next=NULL;
        }
        else
        {
        	r=head3;
        	while(r->next!=NULL)
        	{
				 r=r->next;
            }
            
            r->next=nw3;
            nw3->next=NULL;
        }
     
    }
    while(p!=NULL) 
    {
        r=head3;
        nw3=(pol*)malloc(sizeof(pol));
        nw3->cof=p->cof;
        nw3->exp=p->exp;
		while(r->next!=NULL)
        {
				 r=r->next;
        }   
        r->next=nw3;
        nw3->next=NULL;
        
        p=p->next;
    }
    while(q!=NULL) 
    {
        r=head3;
        nw3=(pol*)malloc(sizeof(pol));
        nw3->cof=q->cof;
        nw3->exp=q->exp;
        while(r->next!=NULL)
        {
				 r=r->next;
        } 
        r->next=nw3;
        nw3->next=NULL;
    	q=q->next;
           
    }
    printf("\nthe addition of two polynomial is : ");
    for(r=head3;r!=NULL;r=r->next)	
    {
		if(r->cof!=0)
		{
		
			if(r->exp==0)
		    	printf(" (%d)",r->cof);
		    else if(r->next==NULL)
		    	printf(" (%dX^%d)",r->cof,r->exp);
			else
				printf(" (%dX^%d )+",r->cof,r->exp);
		}
    }
    printf("\n");
}

