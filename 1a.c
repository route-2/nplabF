//sender module should count the no of bytes in the frame and receive module should display each frame received 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void reciver();
char frames[1024];
int main()
{
    char buffer[256],temp[10];
    int n;
    printf("enter the no of frames to be sent");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    
    {
        bzero(buffer,256);
        printf("enter the frames at %d",(i+1));
        scanf("%s",buffer);

        int len = strlen(buffer);
        printf("the length of the frames are %d",len);
        sprintf(temp,"%d",len);
        strcat(frames,temp);
        strcat(frames,buffer);
    }
    reciver();
}
void reciver()
{
    printf("\n the frame recived is %s",frames);
    int frameslen = strlen(frames);
    printf("\n the length of the frame is %d",frameslen);

    int i = 0;
    while(i<frameslen)
    {
        char leninchar=frames[i++];
        int len = (int)leninchar- (int)'0';
        while(len>0)
        {
            printf("%c",frames[i++]);
            len--;
        }
        printf("\n");
            }
}