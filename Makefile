all : libMyPeri.a
libMyPeri.a: buzzer.o led.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o buzzer.o

buzzer.o: buzzer.c buzzer.h
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

led.o: led.c led.h
	arm-linux-gnueabi-gcc -c led.c -o led.o

