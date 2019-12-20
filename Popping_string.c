/*This program will pop the first element from the string
 * and display it*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],choice,temp;
	int i,size;
	printf("Enter the string: ");
	scanf("%s",str);
	size=strlen(str);
	do
	{
		if(size!=0)
		{
			temp=str[0];
			for(i=0;i<size;i++)
			{
				str[i]=str[i+1];
			}
			size-=1;
			printf("\n\n\t\t\tCharacter popped: %c",temp);
			printf("\n\t\t\tString after popping: ");
			for(i=0;i<size;i++)
			{
				printf("%c",str[i]);
			}
			printf("\n\n\t\t\tEnter 'y' to continue popping: ");
			scanf("%s",&choice);//Not working with %c
		}
		else
		{
			printf("\n\n\t\t\tString is now empty!");
			choice='n';
		}
	}
	while(choice=='y');
	return 0;
}
