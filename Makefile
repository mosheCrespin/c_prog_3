CC=gcc
FLAGS=-Wall -g
.PHONY: all clean 
all: txtfind isort 
isort.o:isort.c
	$(CC) $(FLAGS) -c isort.c
txtfind.o:txtfind.c
	$(CC) $(FLAGS) -c txtfind.c
isort: isort.o 
	$(CC) $(FLAGS) isort.o -o isort
txtfind: txtfind.o 
	$(CC) $(FLAGS) txtfind.o -o txtfind	
	
clean:
	rm  *.o txtfind isort
	
	

