main: main.o pshell.o
 	gcc –o main main.o pshell.o 
pshell.o: pshell.h
	gcc -c pshell.h
pcmds.o: pcmds.h
	gcc -c pcmds.h
main.o: main.c pshell.h
 	gcc -c main.c