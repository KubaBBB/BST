
all: program

program: main.o BST.o funny.o
	gcc -o program main.o BST.o funny.o

main.o: main.c
	gcc -c main.c

BST.o: BST.c BST.h
	gcc -c BST.c

funny.o: funny.c funny.h BST.h
	gcc -c funny.c

clean:
	rm program main.o BST.o funny.o
