#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "colorled.h"

int main(void)
{
	ColorLedInit(0, 0);
	sleep(1);
	ColorLedExit();

	ColorLedInit(0, 1);
	sleep(1);
        ColorLedExit();

	ColorLedInit(0, 2);
	sleep(1);
        ColorLedExit();

//	ColorLedInit(0, 0);
//	ColorLedInit(0, 1);
//	ColorLedInit(0, 2);
//	sleep(1);
//        ColorLedExit();
}
