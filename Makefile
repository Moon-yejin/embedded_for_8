all : libMyPeri.a

libMyPeri.a: fnd.o buzzer.o button.o led.o textlcd.o colorled.o temperature.o accelMagGyro.o fitness.o bitmap.o
	arm-linux-gnueabi-ar rc libMyPeri.a fnd.o led.o button.o buzzer.o textlcd.o colorled.o temperature.o accelMagGyro.o fitness.o bitmap.o

bitmap.o: bitmap.c bitmap.h
	arm-linux-gnueabi-gcc -c bitmap.c -o bitmap.o

fitness.o: fitness.c
	arm-linux-gnueabi-gcc -c fitness.c -o fitness.o

accelMagGyro.o: accelMagGyro.c amg.h
	arm-linux-gnueabi-gcc -c accelMagGyro.c -o accelMagGyro.o

temperature.o: temperature.c temperature.h
	arm-linux-gnueabi-gcc -c temperature.c -o temperature.o

colorled.o : colorled.c colorled.h
	arm-linux-gnueabi-gcc -c colorled.c -o colorled.o

textlcd.o : textlcd.c textlcd.h
	arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o

fnd.o: fnd.c fnd.h
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o

buzzer.o: buzzer.c buzzer.h
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

button.o: button.c button.h
	arm-linux-gnueabi-gcc -c button.c -o button.o

led.o: led.c led.h
	arm-linux-gnueabi-gcc -c led.c -o led.o

