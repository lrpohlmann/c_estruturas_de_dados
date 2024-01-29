#include <stdbool.h>

typedef struct stack_struct {
  int size;
  int length;
  int *elements;
} Stack;

Stack *ST_Init(int size, int *init_values);

bool ST_Push(Stack *st, int e);

bool ST_Pop(Stack *st, int *element);

bool ST_Peek(Stack *st, int *peeked_element);
