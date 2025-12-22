#include <stdio.h>
#include<stdlib.h> 
#include<ctype.h> 
#include <math.h>

void postfixeval();

int stack[20];
int  top =-1;
char postfix[20];

void push(int item)
{		
    stack[++top]=item;
}

int pop()
{		
    return(stack[top --]);
}


void postfixeval( )
{
   int i=0,op1,op2,result;
   printf("\n\nEnter the postfix Expression:"); 
   scanf("%s",postfix);
   
   for(i=0;postfix[i]!='\0';i++)
   {
        if(isdigit(postfix[i]))
               push(postfix[i]-'0');
       else
       {	
          op2=pop();
          op1=pop();
          switch(postfix[i])
         {
                case'+':push(op1+op2); 
                        break;
                case '-':push(op1-op2); 
                        break;
                case'*':push(op1*op2); 
                        break;
                case'/':push(op1/op2); 
                        break;
                case'%':push(op1%op2);
                        break;
                case'^':push(pow(op1,op2));
                        break;
          }
      }
  }
     printf("\n Given sufffix Expression n: %s\n", postfix); 
     printf("\nResult after Evaluation:%d\n",stack[top]);
}

void  main()
{
      postfixeval();
    
}
