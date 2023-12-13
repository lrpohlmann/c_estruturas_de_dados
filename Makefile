linkedlist: linkedlist.o
	cc -Wall -pedantic -g obj/linkedlist.o -o build/linkedlist

linkedlist.o: 
	cc -Wall -pedantic -g -c src/linkedlist.c -o obj/linkedlist.o
