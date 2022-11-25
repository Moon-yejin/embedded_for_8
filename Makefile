all: libMyPeri.a
	libMyPeri.a: led.o button.o buzzer.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o buzzer.o
	
button.o: button.h button.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o
led.o: led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o
