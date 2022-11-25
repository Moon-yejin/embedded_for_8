#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"

#define INPUT_DEVICE_LIST "/dev/input/event"
#define PROBE_FILE "/proc/bus/input/devices"
#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n"
#define HAVE_TO_FIND_2 "H:Handlers=kbd event"

pthread_t buttonTh_1;
int fd = 0;
int msgID;

int probeButtonPath(char *newPath)
{
        int returnValue = 0;
        int number = 0;
        FILE *fd = fopen(PROBE_FILE, "rt");
        while(!feof(fd))
        {
                char tmpStr[200];
                fgets(tmpStr, 200, fd);
                if(strcmp(tmpStr, HAVE_TO_FIND_1)==0)
                {
                        printf("YES! I found! : %s\r\n", tmpStr);
                        returnValue = 1;
                }
                if(
                                (returnValue == 1)&&
                                (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2))==0)
                  )
                {
                        printf("-->%s", tmpStr);
                        printf("\t%c\r\n", tmpStr[strlen(tmpStr)-3]);
                        number - tmpStr[strlen(tmpStr)-3]-'0';
                        break;
                }
        }
        fclose(fd);
        if(returnValue==1)
                sprintf(newPath, "%s%d", INPUT_DEVICE_LIST, number);
        return returnValue;
}


/* int buttonInit(void)
{
	char inputDevPath[200] = {0,};
        if(probeButtonPath(inputDevPath)==0)
	{
		printf("ERROR! File Not Found!\r\n");
                printf("DId you insmod?\r\n");
		return 0;
	}
        fd=open(inputDevPath, O_RDONLY);
        msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
        pthread_create(&buttonTh_1, NULL, buttonThFunc, NULL);
	pthread_join (buttonTh_1, NULL); // 대기
        return 1;
}
*/

void buttonThFunc(void)
{
        while(1){
        struct input_event A;
        int readSize = read(fd, &A, sizeof(A));
	if(readSize != sizeof(A))
                {
                        continue;
                }
                if( A.type==EV_KEY)
                {
                        printf("EV_KEY(");
                        switch(A.code)
                        {
                                case KEY_VOLUMEUP: printf("Volume up key):");
                                                   break;
                                case KEY_HOME: printf("Home key):");
                                                   break;
                                case KEY_SEARCH: printf("Search key):");
                                                   break;
                                case KEY_BACK: printf("Back key):");
                                                   break;
                                case KEY_MENU: printf("Menu key):");
                                                   break;
                                case KEY_VOLUMEDOWN: printf("Volume down key):");
                                                   break;
                        }
                        if ( A.value )
                                printf("pressed\n");
                        else
                                printf("released\n");
                }
                else
                        ;
        BUTTON_MSG_T B;
        B.messageNum=1;
        B.keyInput=A.code;
        B.pressed=A.value;
        msgsnd(msgID, &B, sizeof(B)-4, 0);
	}
}

int buttonInit(void)
{
        char inputDevPath[200] = {0,};
        if(probeButtonPath(inputDevPath)==0)
        {
                printf("ERROR! File Not Found!\r\n");
                printf("DId you insmod?\r\n");
                return 0;
        }
        fd=open(inputDevPath, O_RDONLY);
        msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
        pthread_create(&buttonTh_1, NULL, buttonThFunc, NULL);
        pthread_join (buttonTh_1, NULL); // 대기
        return 1;
}

int buttonExit(void)
{
	close(fd);
}
