make:
	gcc -c main.c -lncurses -Wall
	gcc -o App main.o -lncurses -Wall
	./App

cmp:
	gcc -c main.c -lncurses -Wall
	gcc -o App main.o -lncurses -Wall

clean:
	rm *.o
