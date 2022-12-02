#include <stdint.h>
#include <String.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

char gbug[10];
int spi_init(char filename[40])
{
	int file;
	_u8 mode. lsb, bits;
	_u32 speed = 20000;

	if((file = open(filename, O_WRONLY))<0){
		printf("Failed to open the bus.");
		printf("ErrorType:%d\r\n", errno);
		exit(1);
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

	int main(int argc, char **argv){
		char *buffer;
		int file;
		file = spi_init("/dev/spidev1.0");
		buffer = (char*)spi_read_lm74(file);
		close(file);

		int value = 0;
		value = ((int)(buffer[1])>>3);
		value += ((int)(buffer[0])<<5);
		if(buffer[0]&0x80)
		{
			int i=0;
			for(i=31; i>12; i--)
				value |=(1<<i);
		}

		double temp = (double)value*0.0625;
		printf("CUrrent Temp: %lf \n", temp);
		return 0;
	}
