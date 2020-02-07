#include<stdio.h>
#include<math.h>
#define size 50
struct request
{
	int sector;
	int finished;
}R[size];
void main()
{
	int i,j,n,head_position,min,pos,total=0;
	printf("Enter the current head position: ");
	scanf("%d",&head_position);
	printf("Enter the number of requests in Request Queue: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the sector number for request %d: ",i+1);
		scanf("%d",&R[i].sector);
		R[i].finished=0;
	}
	for(i=0;i<n;i++)
	{
		min=-1;
		for(j=0;j<n;j++)
		{
			if(R[j].finished==0)
			{
				if(min==-1)
				{
					min=abs(R[j].sector-head_position);
					pos=j;
				}
				else if(abs(R[j].sector-head_position)<min)
				{
					min=abs(R[j].sector-head_position);
					pos=j;
				}
			}
		}
		if(min!=-1)
		{
			total+=min;
			printf("\n\n\t\tHead moved from sector %d to sector %d",head_position,R[pos].sector);
			head_position=R[pos].sector;
			R[pos].finished=1;
		}
	}
	printf("\n\n\n\t\tTotal number of head movements = %d\n",total);
}
