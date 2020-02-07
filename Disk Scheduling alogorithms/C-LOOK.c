#include<stdio.h>
#include<math.h>
#define size 50
struct request
{
	int sector;
}R[size];
void main()
{
	int i,j,n,head_position,density1=0,density2=0,temp,total=0;
	printf("Enter the current head position: ");
	scanf("%d",&head_position);
	printf("Enter the number of requests in Request Queue: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the sector number for request %d: ",i+1);
		scanf("%d",&R[i].sector);
	}
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-1-i);j++)
		{
			if(R[j].sector>R[j+1].sector)
			{
				temp=R[j].sector;
				R[j].sector=R[j+1].sector;
				R[j+1].sector=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(R[i].sector<head_position)
		density1++;
		else
		density2++;
	}
	if(density1>density2)
	{
		for(i=(density1-1);i>=0;i--)	
		{
			total+=abs(head_position-R[i].sector);
			printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[i].sector);
			head_position=R[i].sector;
		}
		for(i=(n-1);i<=density1;i--)
		{
			total+=abs(head_position-R[i].sector);
			printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[i].sector);
			head_position=R[i].sector;
		}
		printf("\n\n\n\t\tTotal number of head movements = %d",total);
	}
	else
	{
		for(i=density1;i<n;i++)
		{
			total+=abs(head_position-R[i].sector);
			printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[i].sector);
			head_position=R[i].sector;
		}
		for(i=0;i<density1;i++)
		{
			total+=abs(head_position-R[i].sector);
			printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[i].sector);
			head_position=R[i].sector;
		}
		printf("\n\n\n\t\tTotal number of head movements = %d",total);
	}
}
