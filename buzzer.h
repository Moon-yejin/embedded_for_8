#ifndef _BUZZER_H_
#define _BUZZER_H_

void buzzerEnable(int bEnable);
void setFrequency(int frequency);

int buzzerInit(void); // 디렉토리 찾기
int buzzerPlaySong(int scale); // 주파수 입력
int buzzerStopSong(void); // 디렉토리 enable에 0 입력
int buzzerExit(void); // buzzerStopSong 한 번 불러오기

#endif
