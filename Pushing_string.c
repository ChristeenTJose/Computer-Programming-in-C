/*This program will push a character at the end of the string
 * and display the new string*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],choice='y',temp;
	int i,size;
	printf("Enter the string: ");
	scanf("%s",str);
	size=strlen(str);
	do
	{
		if(size!=20)
		{
			printf("\n\n\t\t\tEnter the character to push: ");
			scanf("%s",&temp);//Not working with %c
			str[size]=temp;
			size+=1;
			printf("\n\t\t\tString after pushing: ");
			for(i=0;i<size;i++)
			{
				printf("%c",str[i]);
			}
			printf("\n\n\t\t\tEnter 'y' to continue pushing: ");
			scanf("%s",&choice);//Not working with %c
		}
		else
		{
			printf("\n\n\t\t\tString is now full!");
			choice='n';
		}
	}
	while(choice=='y');
	return 0;
}
