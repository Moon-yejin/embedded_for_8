#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "amg.h"
#include "fnd.h"
#include "buzzer.h"
#include "textlcd.h"
//#include "bitmap.h"

int fa = 0;
int accel[3];
FILE *fp = NULL;

int accInit(void)
{
	fa = open (ACCELPATH "enable",O_WRONLY);
	dprintf (fa,"1");
	close(fa);
	return 0;
}

int getAcc(void)
{
	fp = fopen (ACCELPATH "data", "rt");
	fscanf(fp,"%d, %d, %d",&accel[0],&accel[1],&accel[2]);
	printf ("I read Accel %d, %d, %d\r\n",accel[0],accel[1],accel[2]);
	fclose(fp);
	return 0;
}

int fitness(void)
{
//	bitmainfunc("start.bmp");

	// TEXT-LCD
	TextInit(1, " NO  ");
	TextInit(2, "REST ");

	// BUZZER로 운동 기준 시간을 출력
	// FND, ACCEL
	buzzerInit();

	for(int i=0; i<5; i++)
	{
		buzzerPlaySong(3);
		usleep(50000);
		buzzerStopSong();
		fndDispInit(i+1,0);
		sleep(3);

		accInit();
		getAcc();

//		if (accel[0] < 0)
//		{
//			fndDispInit(i+1,0);
//		}
	}

	fndDispExit();
	buzzerExit();
	TextExit();
}

