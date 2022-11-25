#ifndef _BUTTON_H_
#define _BUTTON_H_

#define MESSAGE_ID 8888
typedef struct
{
        long int messageNum;
        int keyInput;
        int pressed;
} BUTTON_MSG_T;

int probeButtonPath(char *newPath);
int buttonInit(void);
int buttonExit(void);

#endif
