#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    unsigned dist[20];
    unsigned from[20];
}rt[20];



int main()
{
    int n,i,j,k,count=0;
    int dmat[20][20];

    printf("enter the number of nodes");
    scanf("%d",&n);


    printf("enter the cost matrix");
    for(i=0;i<n;i++)
    
      
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=i;
                 
        }

        do
        {
            count =0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(k=0;k<n;k++)
                    {
                        if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                        {
                            rt[i].dist[j]=dmat[i][k]+rt[k].dist[j];
                            rt[i].from[j]=rt[k].from[j];
                            count++;
                        }
                    }
                }
            }
        } while (i!=0);

        for(i=0;i<n;i++)


        {
            printf("\nNode\t via \t dist");
            for(j=0;j<n;j++)
            {
                printf("\n%d \t %d \t %d",j+1,rt[i].dist[j],rt[i].from[j]);
            }
            printf("\n\n");
        }
        
    




}