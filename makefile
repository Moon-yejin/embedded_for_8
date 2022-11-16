obj-m := hello_drv.o
KDIR := /home/yejin/targetSrc/linux_kernel/
PWD := $(shell pwd)

export ARCH = arm
export CROSS_COMPILE = arm-linux-gnueabi-
all:
	$(MAKE) -C $(KDIR) SUBDIRS = $(PWD) modules


