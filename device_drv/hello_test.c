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

#define HELLO_DRIVER_NAME "/dev/hello1"

int main (int argc, char **argv)
{
	char data[4];
	int fd;
	printf ("enter test! \n");

	fd = open ("/dev/hello1", O_RDWR);
	if (fd < 0)
	{
		printf ("OPEN FAIL \n");
		perror ("driver (/dev/hello1) open error! \n");
		return 1;
	}
	printf ("OPEN SUCCESS! \n");
	
	write(fd, &data, 4);
        read(fd, data, 4);
//      printf("read value: %c %c %c %c \n", data[0], data[1], data[2], data[3]);

	// application
	for (int k=0; k < 8; k++)
	{
		int request = 1 << k;
		unsigned int inputCmd = _IO(0x88, request);
		printf ("Enter CMD: %d -> 0x%08x \n", request, inputCmd);
		unsigned long returnValue = ioctl(fd, inputCmd, 0);
	}
	
	char array [20]={'5','6','7','8'};
        unsigned int inputCmd = _IOW(0x88, 89, array);
        unsigned long returnValue = ioctl (fd, inputCmd, array);
	
        inputCmd = _IOW(0x88, 88, int);
        int cnt = 4;
        returnValue = ioctl (fd, inputCmd, &cnt);
	printf("readValue: ");
	for(int i=0; i < 4; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
	close(fd);
	return 0;
}
