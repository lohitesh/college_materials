#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct   Calendar
{
     char *name;
     int date;	
     char *activity;
};

struct Calendar *C;
int i;

void create( )
{
    C=(struct Calendar *)malloc(7* sizeof(struct Calendar));
}

void read( )
{
   
    char buffer[20];
    for(i=0;i<7;i++)
   {
      printf("\n enter weekday");
     scanf("%s",buffer);
     (C+i)->name=(char*)malloc(strlen(buffer)+1);
     strcpy((C+i)->name,buffer);

     printf("\n Enter the date ");
     scanf("%d", &(C+i)->date);

     printf("\n Enter the activity");
     scanf("%s",buffer);
     (C+i)->activity=(char*)malloc(strlen(buffer)+1);
     strcpy((C+i)->activity,buffer);
   }
}


void display( )
{
   printf("\n Weekly Calendar of Activities\n");
   printf("--------------------------------------------");
   printf("\n Date\t\t\t Weekday\t\t\t Activity\n");
   printf("--------------------------------------------\n");
   for(i=0;i<7;i++)
  {
      printf("\n %d\t\t\t %s\t\t\t %s\n", (C+i)->date,(C+i)->name,(C+i)->activity); 
   }
 }



void main()
{
    create();
    read();
    display();
    free(C);
    
} 

