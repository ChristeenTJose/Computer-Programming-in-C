#include<stdio.h>
#define size 20
int stack[20];
int top=-1;
void push(int);
int pop();
void main()
{
	int n,r,i;
	printf("Enter the integer to be converted: ");
	scanf("%d",&n);
	while(n>0)
	{
	       r=(n%2);
	       push(r);
	       n/=2;
	}
	printf("\nThe required number in binary system is: ");
	for(i=top;i>=0;i--)
	printf("%d",pop());
	printf("\n\n");
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
	if(top==-1)
	{
		printf("Underflow, no more elements to be deleted.\n");
	}
	else
	return stack[top--];
}
