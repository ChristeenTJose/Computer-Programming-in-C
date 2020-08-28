#include<stdio.h>
#include<string.h>
#define size 20
char stack[20];
int top=-1;
void push(char);
char pop();
int isempty();
void main()
{
    int i,flag=0;
    char str[15];
    printf("Enter the string for balanced symbol checking: ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if((str[i]=='(')||(str[i]=='[')||(str[i]=='{'))
        push(str[i]);
        else if((str[i]==')')||(str[i]==']')||(str[i]=='}'))
        {
            if(isempty()==1)
            {
                printf("\n\n\t\tUnbalanced 1\n");
                flag=1;
            }
            else
            {
                if((str[i]==')' && pop()!='(')||(str[i]==']' && pop()!='[')||(str[i]=='}' && pop()!='{'))
                {
                    printf("\n\n\t\tUnbalanced 2\n");
                    flag=1;
                }
            }
        }
        if(flag==1)
        break;
    }
    if(flag==0)
    {
        if(isempty()==0)
        printf("\n\n\t\tUnbalanced 3\n");
        else
        printf("\n\n\t\tBalanced\n");
    }
}
void push(char item)
{
    if((top+1)==size)
    {
        printf("Overflow, no more items can be inserted\n");
    }
    else
    {
        top+=1;
        stack[top]=item;
    }
}
char pop()
{
    if(isempty()==1)
    printf("Underflow, no more elements to be deleted\n");
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
