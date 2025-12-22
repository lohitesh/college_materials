#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define maxsize 5

int stack[maxsize];
int top=-1;

int stackfull()
{
   if (top==maxsize-1)
      return 1;
   else
      return 0;
}


int stackempty()
{
     if(top==-1)
        return 1;
      else
        return 0;
}

void push(int item)
{
       stack[++top]=item;
}

int pop()
{   
    return stack[top--];
     
}


void display()
{
    int i;
    if(top==-1)
      printf("\nStack Underflow");
    else
       {
           for(i=top;i>=0;i--)
             printf("\n%d",stack[i]);
       }
}


void palindrome()
{
    int num,i,rem,rev,temp;;
    printf("\n Enter a number");
    scanf("%d",&num);
    temp=num;
    while(num!=0)
    {
         rem=num%10;
         push(rem);
         num=num/10;
    }
    rev=0, i=0;
    while (top!=-1)
    {
          rev=rev+pop()*pow(10,i);
          i=i+1;
    }
    if(temp==rev)
        printf("\n No is palindrome");
    else
       printf("\n No is not a plaidrome");
}

void main()
{
      int choice, item;
      while(1)
      {
          printf("\n STACK OPERATIONS\n");
          printf("\n 1. PUSH");
          printf("\n 2.POP");
          printf("\n 3.DISPLAY");
          printf("\n 4.PALINDROME");
          printf("\n 5.EXIT");
          printf("\n \nEnter ypur choice");
          scanf("%d", &choice);
          
          switch(choice)
          {
              case 1:  if (stackfull()==1)
                              printf("\nStack Overflow"); 
                            else
                            {
                          printf("\n Enter element  to pushed");
                          scanf("%d",&item);
                          push(item);
                            }
                           break;
             case 2: if(stackempty()==1)
                             printf("\nStack  Underflow");  
                          else
                            printf("\n Element popped %d",pop());
                          break;
             case 3:  display();
                          break;
             case 4:  palindrome();
                          break;
                     case 5:  exit(0);

                   default: printf("Invalid choice");
         }   //switch end
     }//while end     
}//main end


