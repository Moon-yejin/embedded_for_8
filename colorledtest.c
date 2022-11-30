#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "colorled.h"

int main(void)
{
	ColorLedInit(100, 0, 0);
	sleep(1);

	ColorLedInit(0, 100, 0);
	sleep(1);

	ColorLedInit(0, 0, 100);
	sleep(1);
}
