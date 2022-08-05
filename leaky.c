#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) (a>b)?b:a

int main()
{
    int out,drop=0,cap,x,count=0,np,inp[10]={0},i=0,nsec,ch;
 printf("enter bucket size");
 scanf("%d",&cap);

 printf("enter the output rate");
 scanf("%d",&out);

 do
 {
    printf("enter the input rate");
    scanf("%d",&inp[i]);
    if(inp[i]>cap)
    {
        printf("input rate is greater than bucket size",i+1);
        exit(0);
    }
    i++;
    printf("enter 1 to continue or 0 to quit");
    scanf("%d",&ch);
}while(ch);
nsec=i;
printf("\n second \t received \t sent \t dropped \t remained \n");
for(i=0;count || i <nsec;i++)
{
    printf("%d",i+1);
    printf("\t\t%d\t",inp[i]);
    printf("\t%d\t", MIN((inp[i]+count),out));
    if((x=inp[i]+count-out)>0)
    {
        if(x>cap)
        {
            count=cap;
            drop=x-cap;
        }
        else{
            count = x;
            drop=0;
        }
    }
    else{
        drop=0;
        count=0;
    }
    printf("\t%d\t%d\n",drop,count);
}
return 0;

 }
