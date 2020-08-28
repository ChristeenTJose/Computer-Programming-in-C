#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char str[20];
	int i,ca,ce,ci,co,cu;
	ca=ce=ci=co=cu=0;
	printf("Enter the string: ");
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	{
			str[i]=tolower(str[i]);
			switch(str[i])
			{
				case 'a':	ca+=1;
							break;
				case 'e':	ce+=1;
							break;
				case 'i':	ci+=1;
							break;
				case 'o': 	co+=1;
							break;
				case 'u':	cu+=1;
							break;
			}
	}
	printf("\n\n\t\t\tTotal number of vowels: %d",ca+ce+ci+co+cu);
	printf("\n\t\t\tNumber of 'a': %d",ca);
	printf("\n\t\t\tNumber of 'e': %d",ce);
	printf("\n\t\t\tNumber of 'i': %d",ci);
	printf("\n\t\t\tNumber of 'o': %d",co);
	printf("\n\t\t\tNumber of 'u': %d",cu);
	return 0;
}
