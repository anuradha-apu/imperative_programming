# Makefile

# target program

# default rule
a.out : main.o listlib.o
	   gcc main.o listlib.o 

# compile source files into object files
main.o: main.c listlib.h
	gcc -c main.c

listlib.o: listlib.c listlib.h
	   gcc -c listlib.c

# clean up build files
clean:
	rm -f *.o a.out
