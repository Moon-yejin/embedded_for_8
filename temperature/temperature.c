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
#include "temperature.h"

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

void read_temperature(void)
{
	while(1)
	{
		char *buffer;
		int file;
		file = spi_init("/dev/spidev1.0");
		buffer = (char*)spi_read_lm74(file);
		close(file);

		int value = 0;
		value = (buffer[1] >> 3);
		value += ((int)(buffer[0])) << 5;
		if(buffer[0] & 0x80)
		{
			int i=0;
			for(i=31; i>12; i--)
			value |= (1<<i);
		}

		double temp = (double)value*0.0625;
		printf("Current Temp: %lf \n", temp);
		sleep(1);
	}
}
