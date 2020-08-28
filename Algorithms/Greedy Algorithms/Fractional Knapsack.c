#include<stdio.h>
struct item
{
    int ID;
    int profit;
    int weight;
    float ratio;
};
void main()
{
    int n,i,j;
    float W,P=0;
    struct item temp,I[20];
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%f",&W);
    for(i=0;i<n;i++)
    {
        printf("\n\nEnter the corresponding values of profit and weight for item %d:\nprofit: ",i+1);
        I[i].ID=(i+1);
        scanf("%d",&I[i].profit);
        printf("Weight: ");
        scanf("%d",&I[i].weight);
        I[i].ratio=(float)I[i].profit/I[i].weight;
    }
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(I[j].ratio<I[j+1].ratio)
            {
                temp=I[j];
                I[j]=I[j+1];
                I[j+1]=temp;
            }
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        printf("\n\nItem %d\tRatio - %f",I[i].ID,I[i].ratio);
    }
    */
    for(i=0;i<n;i++)
    {
        if(W>I[i].weight)
        {
            W-=I[i].weight;
            P+=I[i].profit;
            printf("\n\tItem %d inserted",I[i].ID);
        }
        else if(W>0)
        {
            P+=(float)W/I[i].weight*I[i].profit;
            W=0;
            printf("\n\tItem %d inserted",I[i].ID);
        }
    }
printf("\n\n\n\t\tTotal profit: %f\n\t\tSpace remaining: %f\n\n",P,W);
}
