main: main.o pshell.o
	gcc –o main main.o pshell.o 
pshell.o: pshell.h
	gcc -c pshell.h
pcmds.o: pcmds.h vcs.h
	gcc -c pcmds.h
vcs.o: vcs.h
	gcc -c vcs.h
main.o: main.c pshell.h
	gcc -c main.c