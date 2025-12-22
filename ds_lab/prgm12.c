#include <stdio.h>
#include <stdlib.h>

#define tablesize 10

struct employee 
{
    int id;
    char name[15]; 
    int  flag;

};

struct employee emp[tablesize];
int n,i;



void create()
{
     int num, key, i;
    int ans = 1;
       
   for (i=0; i < tablesize; i++)
            emp[i].flag=0;
 
        
    printf("\nEnter the no of employess");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the 4 digit number id of  emplyee");
        scanf("%d", &num);
        key=num % tablesize;
      
        if(emp[key].flag==0)
        {
                emp[key].flag=1;
                emp[key].id=num;
               printf("enter the employee name");
               scanf("%s", &emp[key].name);
        }
        else
         {        while(emp[key].flag!=0)
                                key=(key+1)%tablesize;
                        
                     emp[key].flag=1;
                     emp[key].id=num;
                     printf("enter the employee name");
                    scanf("%s", &emp[key].name);
                    
            }
    }
}

void display()
{
      printf("\nHashIndex\t\tEmpID\t\tEmpName");
  for(i=0; i<tablesize; i++)
          printf("\n%d\t\t\t%d\t\t%s", i, emp[i].id, emp[i].name);
    
  }
void main()
{
         create();
         display();
 }

