#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "amg.h"
#include "fnd.h"
#include "buzzer.h"
#include "textlcd.h"

int fd = 0;
int accel[3];
FILE *fp = NULL;

int accInit(void)
{
	fd = open (ACCELPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	return 0;
}

int getAcc(void)
{
	fp = fopen (ACCELPATH "data", "rt");
	fscanf(fp,"%d, %d, %d",&accel[0],&accel[1],&accel[2]);
	printf ("I read Accel %d, %d, %d\r\n",accel[0],accel[1],accel[2]);
	fclose(fp);
	return accel[0];
}

int main(void)
{
	// TEXT-LCD
	TextInit(1, "GAME ");
	TextInit(2, "OVER ");

	// BUZZER로 운동 기준 시간을 출력
	// FND, ACCEL
	buzzerInit();

	for(int i=0; i<5; i++)
	{
		buzzerPlaySong(3);
		sleep(1);
		buzzerStopSong();
		sleep(3);

		if (getAcc() < 0)
		{
			fndDispInit(i+1,0);
			break;
		}
	}

	fndDispExit();
	buzzerExit();
	TextExit();
}

