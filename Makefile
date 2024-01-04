BIN := test.out
SRCS := $(wildcard *.c)

all:
	echo "Compilando test.c"
	gcc $(SRCS) -o $(BIN) -lcriterion
	./test.out
