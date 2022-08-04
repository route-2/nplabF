#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sender();
void reviver(int message,int l2);

int main(void)
{
    sender();
}
void sender()
{
    int i,j,zero=0,count1=0,bitstuff=0;
    int msg[50];
    int result[50];
    int n;
    printf("enter the number of bits in the message");
    scanf("%d",&n);

    printf("enter the bits");

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&msg[i]);
        
    }
    result[0]=0;
    result[1]=1;
    result[2]=1;
    result[3]=1;
    result[4]=1;
    result[5]=1;
    result[6]=1;
    result[7]=0;
    j=8;
    for(i=0;i<n;i++)
    {
        if(msg[i]==0)
        {
            result[j]=msg[i];
            j++;
            count1=0;
            zero=1;
        }
        else{
            if((count1==5) && (zero==1))
            {
                result[j]=0;
                bitstuff=1;
                j++;
                result[j]=msg[i];
                j++;
                count1=0;
                
            }
            else{
                result[j]=msg[i];
                j++;
                count1++;
            }
        }
    }
    result[j++]=0;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=0;

    int l1 = 16+n+bitstuff;
    printf("the length of the message is %d", l1);
    printf("the frame is ");
    for(i=0;i<j;i++)
    {
   printf("%d",result[i]);
    }
    reciver(result,l1);

    }
    void reciver(int *result, int l2)
    {
        int i,j,count1,l3;
        int mesg[100];
        l3=l2-8;
        j=0;
        for(i=8;i<l3;i++)
        {
            if(result[i]==0)
            {
                if(count1==5)
                {
                    i++;
                    mesg[j]=result[i];
                    j++;
                    count1=0;
                }
                else{
                    mesg[j] = result[i];
                    j++;
                    count1=0;

                }
            }
            else
            {
                mesg[j] = result[i];
               j++;
               count1++;
            }
        }
        printf("the recieved message is");
        for(i=0;i<j;i++)
        {
            printf("%d",mesg[i]);
        }
    }










