#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "amg.h"

int fd = 0;
FILE *fp = NULL;

int accInit(void)
{
	fd = open (ACCELPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	return 0;
}


int magInit(void)
{
	fd = open (MAGNEPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	return 0;
}


int gyroInit(void)
{
	fd = open (GYROPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	return 0;
}


int getAcc(void)
{

	fp = fopen (ACCELPATH "data", "rt");
	int accel[3];
	fscanf(fp,"%d, %d, %d",&accel[0],&accel[1],&accel[2]);
	printf ("I read Accel %d, %d, %d\r\n",accel[0],accel[1],accel[2]);
	fclose(fp);
	return 0;

}


int getMag(void)
{
	fp = fopen (MAGNEPATH "data", "rt");
	int magne[3];
	fscanf(fp,"%d, %d, %d",&magne[0],&magne[1],&magne[2]);
	printf ("I read Magneto %d, %d, %d\r\n",magne[0],magne[1],magne[2]);
	fclose(fp);
	return 0;
}


int getGyro(void)
{
	fp = fopen (GYROPATH "data", "rt");
	int gyro[3];
	fscanf(fp,"%d, %d, %d",&gyro[0],&gyro[1],&gyro[2]);
	printf ("I read Gyroscope %d, %d, %d\r\n",gyro[0],gyro[1],gyro[2]);
	fclose(fp);
	return 0;
}
