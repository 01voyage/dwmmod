.POSIX:

PREFIX = /usr/local
CC = gcc

install:
	gcc dwmmod.c -o dwmmod
	cp dwmmod /bin/dwmmod
	chmod 755 /bin/dwmmod

