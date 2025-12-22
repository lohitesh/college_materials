#include<stdio.h>
#include<stdlib.h>
#define  maxsize 5

char cq[maxsize];
int front,rear;

void insert(char item)
{
    if (front==(rear+1)% maxsize)
         printf("\n\n  CIRCULAR QUEUE FULL\n");
 

    else
    {
        if(front==-1) 
               front=rear=0;
       else
               rear=(rear+1)%maxsize;

       cq[rear]=item;
      printf("\nRear=%d	Front= %d\n",rear,front);
     }
}


void delete()
{
     if((front==-1))
          printf("\n CIRCULAR QUEUE  EMPTY\n");
     else
    {
           printf("\nDELETED  ELEMENT  FROM  QUEUE  IS:%c\n", cq[front]);
           cq[front]= '-';
           if(front==rear)
                  front=rear=-1;
           else
                 front=(front+1)%maxsize;
           printf("\nRear = %d	Front = %d \n",rear,front);
           }
}



void display()
{
    int i;
    if((front==-1))
        printf("QUEUE  EMPTY\n");
     else
    {
        printf("The  Queue  Elements   are\n");
        for(i=0;i<maxsize;i++)
            printf("%c \t",cq[i]);
        printf("\nRear = %d	Front = %d \n",rear,front);
    }
}
 void  main( )
{
 	   int choice;
           char item ;
 	   front=-1; rear=-1;
  	  while(1)
  	  {
        printf("\n\n-------QUEUE MENU	\n");
        printf("\n1.INSERT INTO QUEUE");
        printf("\n2.DELETEF FROM QUEUE");
        printf("\n3.DISPLAY QUEUE");
        printf("\n4.EXIT");

        printf("\n\n  ENTER YOUR CHOICE:"); 
        scanf("%d",&choice);
        switch(choice)
        {
           	 case  1:printf("\nENTER THEQUEUE ELEMENT:"); 
                            scanf(" %c",&item);
                            insert(item); 
                            break;

            	case 2:	delete();
                            break; 

           	 case 3:display();
                            break;

           	 case 4:exit(0);

              default:printf("\nInvalidChoice.\n");
      }
     }
 }

