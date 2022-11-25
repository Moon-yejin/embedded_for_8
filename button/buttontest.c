#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>  //for open/close
#include <fcntl.h>  //for O_RDWR
#include <sys/ioctl.h>  //for ioctl
#include "button.h"
#include <pthread.h>

int main(void)
{
// probeButtonPath(); // char 대입

	buttonInit();

	buttonExit();
}
