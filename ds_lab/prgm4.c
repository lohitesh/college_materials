#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char stack[20];
int top=-1;



void push(int item)
{
     stack[++top]=item;
}


int pop()
{
    return stack[top--];
}


int priority(char c)
{
    switch(c)
    {
        case '^':
        case '$':return 3;
        
        case '*':
        case '/':
        case '%':return 2;
        
        case '+':
        case '-':return 1;

       case ')': return -1;
    }
}
void infixtopostfix()
{
  char infix[20],postfix[20];
  int i=0,j=0;
  printf("\n Enter infix expression\n");
  gets(infix);
  
  for(i=0;infix[i]!='\0';i++)
  {
      if(isalpha(infix[i]))
           postfix[j++]=infix[i];
           
      else if(infix[i]=='(')
           push(infix[i]);
           
      else if(infix[i]==')')
            {
                 while(stack[top]!='(')
                      postfix[j++]=pop();
                 pop();
            }

      else if(  priority(infix[i])  >   priority(stack[top]))
                   push(infix[i]);

      else
            {
                   postfix[j++]=pop();
                   push(infix[i]);
            }
  }
  while(top!=-1)
              postfix[j++]=pop();

    postfix[j]='\0';
    printf("\n\n Postfix %s",postfix);
}
  
void main()
{
      infixtopostfix();

}

