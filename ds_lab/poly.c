#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node
{
int coef;
int x,y,z;
struct node*next;
};
struct node *temp,*q;
struct node *poly,*poly1,*poly2,*polysum;
int px,py,pz,cf;
struct node*insert(struct node *head,int cf,int px,int py, int pz)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->coef=cf;
temp->x=px;
temp->y=py;
temp->z=pz;
temp->next=NULL;
if(head == NULL)
head = temp;
else
{
q=head;
while(q->next!=NULL)
q=q->next;
q->next=temp;
}
return head;
}
struct node*readpoly(struct node * head)
{
int px,py,pz,cf;
int n,i;
printf("\n Enter the no of terms in polynomial");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n Enter coef ");
scanf("%d",&cf);
printf("\n Enter x,y,z powers:");
scanf("%d%d%d",&px,&py,&pz);
head=insert(head,cf,px,py,pz);
}
return head;
}
void print(struct node*head)
{
for(q=head;q!=NULL;q=q->next)
printf("%dx^%dy^%dz^%d+",q->coef,q->x,q->y,q->z);
}
void evaluate(struct node*head)
{
int result =0;
printf("\n Enter the values of x,y,z");
scanf("%d%d%d",&px,&py,&pz);
for(q=head;q!=NULL;q=q->next)
result=result+(q->coef*pow(px,q->x)*pow(py,q->y)*pow(pz,q->z));
printf("\n polynomial result is:%d",result);
}
struct node*add(struct node*poly1,struct node*poly2)
{
struct node*polysum =NULL;
while((poly1!=NULL)&&(poly2!=NULL))
{
if((poly1->x==poly2->x)&&(poly1->y==poly2->y)&&(poly1->z==poly1->z))
{
polysum = insert(polysum,poly1->coef+poly2->coef,poly1->x,poly1->y,poly1->z);
poly1=poly1->next;
poly2=poly2->next;
}
else if(poly1->x > poly2->x)
{
polysum=insert(polysum,poly1->coef,poly1->x,poly1->y,poly1->z);
poly1=poly1->next;
}
else
{
polysum=insert(polysum,poly2->coef,poly2->x,poly2->y,poly2->z);
poly2=poly2->next;
}
}
while(poly1!=NULL)
{
polysum=insert(polysum,poly1->coef,poly1->x,poly1->y,poly1->z);
poly1=poly1->next;
}
while(poly2!=NULL)
{
polysum=insert(polysum,poly2->coef,poly2->x,poly2->y,poly2->z);
poly2=poly2->next;
}
return polysum;
}
void main()
{
int choice;
struct node*head=NULL;
while(1)
{
printf("\n \n 1.Read polynomial");
printf("\n 2.print plynomial");
printf("\n 3.polynomial evaluation");
printf("\n 4.polynomial addition");
printf("\n 5. Exit");
printf("\n Enter your choice ");
scanf("%d",&choice);
switch(choice)
{
case 1 :printf("\n Read a polynomial");
head=readpoly(head);
break;
case 2 : printf("\n polynomial is \n");
print(head);
break;
case 3: evaluate (head);
break;
case 4 : printf("\n Enter polynomial 1");
poly1=readpoly(poly1);
printf("\n Enter polynomial 1");
poly2=readpoly(poly2);
printf("\n polynomial 1\n");
print (poly1);
polysum = add(poly1,poly2);
printf("\n polynomial 2 \n");
print (poly2);
printf("\n polynomial Addition Result \n");
print (polysum);
break;
case 5 :exit(0);
default : printf("Invalid choice ");
}
}
}

