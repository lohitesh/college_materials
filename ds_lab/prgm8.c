#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[20];
    char name[20];
    char dept[20];
    char desig[20];
    int sal;
    char pno[12];
    struct node *next;
    struct node *prev;
};

struct node *start=NULL;
struct node *temp,*q,*p;

void nodecreate()
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter SSN: ");
    scanf("%s",temp->ssn);
    printf("Enter Name: ");
    scanf("%s",temp->name);
    printf("Enter Department: ");
    scanf("%s",temp->dept);
    printf("Enter Designation: ");
    scanf("%s",temp->desig);
    printf("Enter Salary: ");
    scanf("%d",&temp->sal);
    printf("Enter phone number: ");
    scanf("%s",temp->pno);
    
    temp->next=NULL;
    temp->prev=NULL;
}


void insertfront()
{
    
    nodecreate();
    if(start==NULL)
        start=temp;
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
}


void insertend()
{
   
    nodecreate();
    if(start==NULL)
        start=temp;
    else
    {
        q=start;
        while(q->next!=NULL)
                q=q->next;
        temp->prev=q;
        q->next=temp;
    }
}


void deletefront()
{
    if(start==NULL)
       printf("The DLL list is empty. \n");
    else 
    {
       q=start;
       printf("Deleted Employee SSN is %s \n\n",q->ssn);
       start=start->next;
       if(start!=NULL) 
       	start->prev=NULL;
       free(q);
    }
}


void deleteend()
{
    if(start == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else if(start->next == NULL)
    {
        printf("Deleted Employee SSN is %s\n", start->ssn);
        free(start);
        start = NULL;
        return;
    }

    q = start;
    while(q->next != NULL)
    {
        p = q;
        q = q->next;
    }

    p->next = NULL;
    printf("Deleted Employee SSN is %s\n", q->ssn);
    free(q);
}



void display()
{
    int count=0;
    if(start==NULL)
       printf(" DLL List is empty. \n");
    else
    {
        printf("The Employee details are:\n");
       for(q=start;q!=NULL;q=q->next)
       {
             printf("%s\t\t%s\t\t%s\t\t%s\t%d\t%s\n",q->ssn,q->name,q->dept,q->desig, q->sal,q->pno);
            count++;
         }
    }
    printf("\nTotal Number of Employee in the DLL List are: %d\n",count);
}



void main( )
{
    int choice,n,i;
    while(1)
    {
        printf("\n-----DOUBLY LINKED LIST MENU	\n");
        printf("1:CREATE DLL\n");
        printf("2:DISPLAY DLL\n");
        printf("DOUBLE ENDED QUEUE DEMOSTRATION \n");
        printf("3:INSERT AT END OF DLL\n");
        printf("4:DELETE FROM END OF DLL\n");
        printf("5:INSERT AT FRONT OF DLL\n");
        printf("6:DELETE FROM FRONT OF DLL\n");
        printf("7:EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
       switch(choice)
       {
            case 1:printf("Enter number of Employees:\n ");
                   scanf("%d",&n);
                   for(i=1;i<=n;i++)
                   {
                       printf("Employee %d details\n",i);
                       insertend();
                   }
                    break;
            case 2: display();
                         break;
            case 3: insertend();
                         break;
            case 4: deleteend();
                         break;
            case 5: insertfront();
                          break;
            case 6: deletefront();
                         break;
            case 7: exit(0);
            default:printf("Invalid Choice\n");
     }
  }
}

