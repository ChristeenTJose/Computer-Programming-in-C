#include<stdio.h>
#define total 20
struct frame
{
	int frame_number;
	int last_modified;
};
struct page
{
	int page_number;
};
void main()
{
	int m,n,i,j,k,fifo_frame,min;
	struct frame f[total];
	struct page p[total];
	printf("Enter the total number of available frames: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		f[i].frame_number=-1;
		f[i].last_modified=-1;
	}
	printf("Enterthe total number of pages: ");
	scanf("%d",&n);
	printf("Enter the page reference string (as a sequence of numbers):\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].page_number);
	}
	printf("\n\t\tPAGEREPLACEMENT USING FIFO POLICY:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(f[j].frame_number==p[i].page_number)
			{
				printf("\n\t\tPage %d has already been alotted to frame %d",p[i].page_number,j+1);
				break;
			}
		}
		if(j==m)
		for(j=0;j<m;j++)
		{
			if(f[j].frame_number==-1)
			{
				f[j].frame_number=p[i].page_number;
				f[j].last_modified=i;
				printf("\n\t\tPage %d has been alotted to frame %d",p[i].page_number,j+1);
				break;
			}
		}
		if(j==m)
		{
			fifo_frame=0;
			min=f[fifo_frame].last_modified;
			for(j=1;j<m;j++)
			{
				if(f[j].last_modified<min)
				{
					fifo_frame=j;
					min=f[j].last_modified;
				}
			}
			f[fifo_frame].frame_number=p[i].page_number;
			f[fifo_frame].last_modified=i;
			printf("\n\t\tPage %d has been alotted to frame %d",p[i].page_number,fifo_frame+1);
		}
	}
}
