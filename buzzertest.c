#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "buzzer.h"

void doHelp(void)
{
	printf("Usage: \n");
	printf ("buzzertest <buzzer No.> \n");
	printf ("buzzer No. : \n");
	printf ("do(1), re(2), mi(3), fa(4), sol(5), ra(6), si(7), do(8) \n");
	printf ("OFF(0) \n");
}

int main (void)
{
	// 경로 찾기
	buzzerInit();
	
	//PLAY SONG
	buzzerPlaySong(1);
	sleep(1);
	buzzerPlaySong(2);
	sleep(1);
	buzzerPlaySong(3);
	sleep(1);
	buzzerPlaySong(4);
	sleep(1);
	buzzerPlaySong(5);
	sleep(1);
	buzzerPlaySong(6);
	sleep(1);
	buzzerPlaySong(7);
	sleep(1);
	buzzerPlaySong(8);
	sleep(1);

	// STOP SONG
	buzzerStopSong();
	
	// DISABLE
	buzzerExit();
}

