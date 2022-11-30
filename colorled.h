#ifndef _COLORLED_H_
#define _COLORLED_H_

int pwmActiveAll(void);
int pwmInactiveAll(void);
int pwmSetDuty(int dutycycle, int pwmIndex);
int pwmSetPeriod(int Period, int pwmIndex);
int pwmSetPercent(int percent, int ledColor);
int pwmRedON(void);
int pwmGreenON(void);
int pwmBlueON(void);

int ColorLedInit(int blue_percent, int green_percent, int red_percent);
void ColorLedExit(void);

#endif
