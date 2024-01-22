CC := gcc
CCFLAGS := -g -Wall -Werror -Wextra
BIN := test.out
SRCS := $(wildcard *.c)

all:
	echo "Compilando test.c"
	$(CC) $(CCFLAGS) $(SRCS) -o $(BIN) -lcriterion
	./test.out
