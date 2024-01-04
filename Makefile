BUILD := ./build
OBJ := ./obj
SRC := ./src

linkedlist: linkedlist.o
	cc -Wall -pedantic -g $(OBJ)/linkedlist.o -o $(BUILD)/linkedlist

linkedlist.o: linkedlist.c 
	cc -Wall -pedantic -g -c $(SRC)/linkedlist.c -o $(OBJ)/linkedlist.o

linkedlist.c:
	touch $(SRC)/$@
