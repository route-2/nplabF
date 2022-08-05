//sender module should count the no of bytes in the frame and receive module should display each frame received 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void reciver();
char frames[1024];

int main()
{
    char buffer[256],temp[20];
    int n;

    printf("enter the number of nodes you want to send %d",&n);
    scanf("%d",&n);


    for(int i =0;i<n;i++)
    {
        bzero(buffer,256);
        printf("\nenter the frame %d\n",(i+1));
        scanf("%s",buffer);

        int len =strlen(buffer);

        sprintf(temp,"%d",len);

        strcat(frames,temp);
        strcat(frames,buffer);
    }
    reciver();
}

void reciver()
{
    printf("the frames recieved is %s\n",frames);

    int frameslen = strlen(frames);
    int i = 0;
    printf("the length of the frames is %d\n",frameslen);
    printf("the frames are\n");

    while(i<frameslen)
    {
        char leninchar = frames[i++];

        int len = (int)leninchar - (int)'0';
        while(len>0)
        {
            printf("%c",frames[i++]);
            len--;
        }
        printf("\n");
    }
    
}