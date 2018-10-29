all: randomfile.o
	gcc randomfile.o

file.o: randomfile.c 
	gcc -c randomfile.c

clean:
	rm *.o
	rm a.out

run:
	./a.out
