#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

char gbuf{10};
int spi_init(char filename[40]);
int file;
char *spi_read_lm74(int file);


#endif