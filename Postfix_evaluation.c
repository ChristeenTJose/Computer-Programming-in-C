#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 20
int stack[20];
int top=-1;
void push(int);
int pop();
int isempty();
void main()
{
    char str[15];
    int i,a,b;
    printf("Enter the postfix expression to be evaluated: ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(isdigit(str[i]))
        push(str[i]-48);
        else
        {
            b=pop();
            a=pop();
            if(str[i]=='+')
            push(a+b);
            else if(str[i]=='-')
            push(a-b);
            else if(str[i]=='*')
            push(a*b);
            else if(str[i]=='/')
            push(a/b);
            else
            printf("Invalid-error!");
        }
    }
    a=pop();
    b=pop();
    if(b==-1)
    printf("\n\tResult is: %d",a);
    else
    printf("Invalid-error!");
}
void push(int item)
{
    if((top+1)==size)
    {
        printf("Overflow, no more items can be inserted.\n");
    }
    else
    {
        top+=1;
        stack[top]=item;
    }
}
int pop()
{
    if(isempty()==1)
    {
        return -1;
    }
    else
    return stack[top--];
}
int isempty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
