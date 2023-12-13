all: maze
maze: Stack.o hw9.o
	gcc Stack.o hw9.o -o maze
Stack.o: Stack.c Stack.h
	gcc -c Stack.c
hw9.o: hw9.o Stack.h
	gcc -c hw9.c
clean:
	rm -f maze Stack.o hw9.o
