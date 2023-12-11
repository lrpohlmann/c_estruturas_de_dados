linkedlist: linkedlist.o
	cc obj/linkedlist.o -o build/linkedlist

linkedlist.o: 
	cc -c src/linkedlist.c -o obj/linkedlist.o
