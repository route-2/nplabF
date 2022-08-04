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
    printf("enter the no of frames to be sent"); // takes users input for no of frames to be sent
    scanf("%d",&n);

    for(int i=0;i<n;i++) // prints the frames and stores in buffer
    
    {
        bzero(buffer,256); //turns buffer to 0s
        printf("enter the frames at %d",(i+1));
        scanf("%s",buffer);
        //buffer of type string

        int len = strlen(buffer);//length of the buffer
        printf("the length of the frames are %d",len);
        sprintf(temp,"%d",len); // store len in temp of type int
        strcat(frames,temp); // concatenate temp to frames
        strcat(frames,buffer); // concatenate buffer to frames
    }
    reciver();
}
void reciver()
{
    printf("\n the frame recived is %s",frames);
    //print frames

    int frameslen = strlen(frames);
    printf("\n the length of the frame is %d",frameslen);
    //prints frames len after strlen

    int i = 0;
    while(i<frameslen)
    {
        char leninchar=frames[i++];
        int len = (int)leninchar- (int)'0'; //converts char to int
        while(len>0)
        {
            printf("%c",frames[i++]);
            len--;
        }
        printf("\n");
        //prints char by char
            }
}