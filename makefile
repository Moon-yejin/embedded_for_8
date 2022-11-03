final.elf : 1.o 2.o main.o myProject.h
	gcc 1.o 2.o main.o myProject.h -o final.elf

main.o : main.c myProject.h
	gcc -c -o main.o main.c

1.o : 1.c myProject.h
	gcc -c -o 1.o 1.c

2.o : 2.c myProject.h
	gcc -c -o 2.o 2.c
