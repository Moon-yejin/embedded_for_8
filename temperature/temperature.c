#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

char gbuf[10];
int spi_init(char filename[40])
{
	int file;

	if((file = open(filename, O_RDWR))<0)
	{
		printf("Failed to open the bus.");
		printf("ErrorType:%d\r\n", errno);
		exit(1);
	}
}

char *spi_read_lm74(int file)
{
	int len;

	memset(gbuf, 0, sizeof( gbuf));
	len = read(file, gbuf, 2);
	if(len != 2)
	{
		perror("read error");
		return NULL;
	}
	return gbuf;
}

