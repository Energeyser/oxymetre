projet: main.o
	gcc main.o -o main
clean:
	rm -f *.o main
all: clean main