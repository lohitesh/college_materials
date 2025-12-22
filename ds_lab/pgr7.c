#include <stdio.h>
#include<stdlib.h>
struct node
{
char usn[10];
char name [10];
char branch[10];
int sem;
char phno[10];
struct node *next;
};
struct node *start = NULL;
struct node *temp,*p,*q;
void nodecreate()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("\n Enter USN:");
scanf("%s",temp->usn);
printf("\n Enter your Name:");
scanf("%s",temp->name);
printf("\n Enter branch:");
scanf("%s",temp->branch);
printf("\n Enter semester :");
scanf("%d", &temp->sem);
printf("\n Enter phone number :");
scanf("%s",temp->phno);
temp->next = NULL;
}
void insertfront ()
{
nodecreate();
if(start == NULL)
start = temp;
else
{
temp->next = start;
start=temp;
}
}
void insertend()
{
nodecreate();
if(start == NULL)
start = temp;
else
{
q=start;
while(q->next!=NULL)
q=q->next;
q->next=temp;
}
}
void deletefront()
{
if(start == NULL)
printf("EMPTY LIST \n");
else
{
q=start;
start = start->next;
printf("\n student deleted is %s",q->usn);
free(q);
}
}
void deleteend()
{
if(start == NULL)
printf("EMPTY LIST \n");
else
{
q=start;
while(q->next!=NULL)
{
p=q;
q=q->next;
}
p->next = NULL;
printf("\n student deleted is %s",q->usn);
free(q);
}
}
void display ()
{
if(start == NULL)
printf("\n LIST IS EMPTY\n");
else
{
printf("\n ---------Student details---------\n");
for(q=start; q!=NULL; q=q->next)
printf("%s\t%s\t%s\t%d\t%s\n", q->usn, q->name, q->branch, q->sem, q->phno);
}
}
int main()
{
int choice,n,i;
while(1)
{
printf("\n\n -----SINGLY LINKED LIST MENU-----\n");
printf("1 : CREATE \n");
printf("2: DISPLAY \n");
printf("3: INSERT AT END \n");
printf("4: INSERT AT FRONT \n");
printf("5: DELETE AT END \n");
printf("6: DELETE FROM FRONT \n");
printf("7: EXIT \n");
printf("Enter your choice \n");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Enter number of students :\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
insertfront();
printf("\n LIST CREATED \n");
break;
case 2 : display();
break;
case 3 : insertend();
break;
case 4 : insertfront();
break;
case 5 : deleteend();
break;
case 6 : deletefront();
break;
case 7 : exit(0);
default : printf("Inavlid choice \n");
}
}
}





