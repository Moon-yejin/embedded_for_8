#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// #include "led.h"

#define LED_DRIVER_NAME "/dev/periled"


void doHelp(void)
{
	printf (" ledtest <hex byte> : data bit0 operation 1 => on 0 => off \n");
	printf (" ledtest 0x05 ; 4th and 1st led on \n");
	printf (" ledtest 0xff ; all led ON \n");
	printf (" ledtest 0x00 l all led off \n");
}

int main (int argc, char **argv)
{
	unsigned int data = 0;
	int fd;
	if (argc < 2)
	{
		perror(" Args number is less than 2 \n");
		doHelp();
		return 1;
	}

	data = strtol(argv[1],NULL,16);
	printf ("write data : 0x%X \n", data);
	ledLibInit();
//	ledOnOff(int ledNum, int onOff); -> 여러 문장 사용해서 실행
	ledOnOff(8,1);
	ledStatus();
	sleep(1);
	ledOnOff(6,1);
        ledStatus();
	sleep(1);

	ledLibExit();
	return 0;
}
