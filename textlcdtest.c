#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "textlcd.h"

int main(void)
{
	TextInit(1, 'Hello!');
	sleep(5);
	TextExit();
}
