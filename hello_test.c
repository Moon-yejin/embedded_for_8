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
	char data[4] = {'5','6','7','8'};
	int fd;
	printf ("enter test! \r \n");

	fd = open ("/dev/hello1", O_RDWR);
	if (fd < 0)
	{
		printf ("OPEN FAIL \r \n");
		perror ("driver (/dev/hello1) open error! \r \n");
		return 1;
	}
	printf ("OPEN SUCCESS! \r \n");

	// application
	for (int k=0; k < 8; k++)
	{
		int request = 1 << k;
		unsigned int inputCmd = _IO(0x88, request);
		printf ("Enter CMD: %d -> 0x%08x \t", request, inputCmd);
		unsigned long returnValue = ioctl(fd, inputCmd, 0);
	}

	char array [20];
	unsigned int inputCmd = _IOWR(0x88, 89, array);
	unsigned long returnValue = ioctl (fd, inputCmd, array);

	inputCmd = _IOWR(0x88, 88, int);
	int count = 5;
	returnValue = ioctl (fd, inputCmd, &count);

//	write (fd, &data, 4);
//	read (fd, data, 4);
//	printf ("read value: %d %d %d %d \r \n", data[0], data[1], data[2], data[3]);
	close (fd);
	return 0;
}
