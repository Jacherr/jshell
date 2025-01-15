CFLAGS = -g
CC = gcc
objects = src/main.o src/help.o src/parse.o

jshell : $(objects)
	cc -g -o jshell $(objects)

src/main.o : src/help.h src/parse.h
src/help.o : src/help.h
src/parse.o : src/parse.h

.PHONY : clean
clean :
	-rm -rf shell $(objects)