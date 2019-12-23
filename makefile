main: main.o pshell.o pcmds.o vcs.o endecryptermain.o
	gcc -o main main.o pshell.o pcmds.o vcs.o endecryptermain.o

main.o: main.c pshell.h
	cc -c main.c

pshell.o: pshell.c pshell.h pcmds.h 
	cc -c pshell.c

pcmds.o: pcmds.c pcmds.h vcs.h endecryptermain.h
	cc -c pcmds.c

vcs.o: vcs.c vcs.h
	cc -c vcs.c

endecryptermain.o: endecryptermain.c endecryptermain.h
	cc -c endecryptermain.c

clean: 
	rm -f endecryptermain.o vcs.o pcmds.o pshell.o main.o