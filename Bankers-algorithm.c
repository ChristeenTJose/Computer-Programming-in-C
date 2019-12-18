#include<stdio.h>
struct process
{
int alotted[15];
int max[15];
int need[15];
};
void main()
{
    //n processes, k types of resources
    struct process P[15],temp;
    int n,k,i,j,total[15],available[15],SSS[15],counter=0,sum1,sum2,flag;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the number of types of resources: ");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        printf("Enter the total number of instances available for reource type %d: ",i+1);
        scanf("%d",&total[i]);
        available[i]=total[i];
    }
    for(i=0;i<n;i++)
    {
        printf("\n\n");
        for(j=0;j<k;j++)
        {
            printf("\nEnter the maximum muber of instances of reosurce type %d that should be allotted to process %d: ",j+1,i+1);
            scanf("%d",&P[i].max[j]);
            printf("Enter the number of instances of resource type %d that has been alotted to process %d: ",j+1,i+1);
            scanf("%d",&P[i].alotted[j]);
            P[i].need[j]=P[i].max[j]-P[i].alotted[j];
            available[j]-=P[i].alotted[j];
        }
    }
    while(counter<n)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            sum1=0;//need<available
            sum2=0;//finished
            for(j=0;j<k;j++)
            {
                if(P[i].need[j]<=available[j])
                sum1+=1;
                sum2+=P[i].need[j];
            }
            if((sum1==k)&&(sum2!=0))
            {
                for(j=0;j<k;j++)
                {
                    P[i].need[j]=0;
                    available[j]+=P[i].alotted[j];
                    P[i].alotted[j]=P[i].max[j];
                }
                SSS[counter]=i;
                counter+=1;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n\nUnsafe State");
            printf("\nSafe state does not exit\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("\n\n\tSafe State");
        printf("\n\tSafe State Sequence: <");
        for(i=0;i<counter;i++)
        {
            printf(" %d ",SSS[i]);
        }
        printf(">\n");
    }
}
