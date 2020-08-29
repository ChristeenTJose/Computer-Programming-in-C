#include<stdio.h>
struct Activity
{
    int ID;
    int start;
    int end;
};
int main()
{
    int n;
    printf("Enter the total number of activities: ");
    scanf("%d",&n);
    struct Activity A[n],temp;
    int i,j,time,count;
    printf("\nEnter the start time and end time for all the activities: ");
    for(i=0;i<n;i++)
    {
        printf("\n\nActivity %d\nStart time: ",i+1);
        scanf("%d",&A[i].start);
        printf("End time: ");
        scanf("%d",&A[i].end);
        A[i].ID=i+1;
    }
    for(i=0;i<n-1;i++)//Sorting based on end time
    {
        for(j=0;j<n-1-i;i++)
        {
            if(A[j].end>A[j+1].end)
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    time=A[0].end;//First Activity is selected
    printf("\n\n\n\t\t\tStarting Activity 1 at time: %d\n\n\t\t\tActivity 1 completed at time: %d",A[0].start,time);
    count=1;
    for(i=1;i<n;i++)
    {
        if(A[i].start>=time)
        {
            time=A[i].end;
            printf("\n\n\t\t\tStarting Activity %d at time: %d\n\n\t\t\tActivity %d completed at time: %d",A[i].ID,A[i].start,A[i].ID,time);
            count+=1;
        }
    }
    printf("\n\n\n\t\tTotal number of Activities completed = %d/%d\n\n",count,n);
    return 0;
}
