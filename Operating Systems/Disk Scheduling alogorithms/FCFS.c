#include<stdio.h>
#include<math.h>
#define size 50
struct request
{
	int sector;
}R[size];
void main()
{
	int i,j,n,head_position,total=0;
	printf("Enter the current head position: ");
	scanf("%d",&head_position);
	printf("Enter the number of requests in Request Queue: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the sector number for request %d: ",i+1);
		scanf("%d",&R[i].sector);
	}
	for(i=0;i<n;i++)
	{
		total+=abs(head_position-R[i].sector);
		printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[i].sector);
		head_position=R[i].sector;
	}
	printf("\n\n\n\t\tTotal number of head movements = %d\n",total);
}
