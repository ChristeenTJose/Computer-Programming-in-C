#include<stdio.h>
#define size 20
struct hole
{
	int memory_space;
	int allocated;
}H[size];
struct process
{
	int process_size;
	int allocated;
}P[size];
void main()
{
	int m,n,i,j,totalE=0,totalI=0;
	printf("Enter the number of holes: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\nEnter the amount of memeory space available in hole %d: ",i+1);
		scanf("%d",&H[i].memory_space);
		printf("Is hole %d occupied? (0 or 1): ",i+1);
		scanf("%d",&H[i].allocated);
	}
	printf("\n\nEnter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the amount of memory space required by process %d: ",i+1);
		scanf("%d",&P[i].process_size);
		P[i].allocated=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(H[j].allocated!=0)
			{
				continue;
			}
			else if(H[j].memory_space-P[i].process_size>=0)
			{
				H[j].memory_space-=P[i].process_size;
				P[i].allocated=1;
				H[j].allocated=2;
				printf("\n\n\tProcess %d has been allocated in hole %d",i+1,j+1);
				break;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(H[i].allocated==2)
		totalI+=H[i].memory_space;
		else if(H[i].allocated==0)
		totalE+=H[i].memory_space;
	}
	printf("\n\n\tTotal External Fragmentation= %d\n\tTotal Internal Fragmentation= %d\n",totalE,totalI);
}
