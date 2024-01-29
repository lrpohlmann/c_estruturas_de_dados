#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

Stack *ST_Init(int size, int *init_values) {
  if (size <= 0) {
    return NULL;
  }
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->size = size;
  stack->length = 0;
  stack->elements = (int *)malloc(size * sizeof(int));
  if (init_values == NULL) {
    return stack;
  }

  for (int i = 0; i < stack->size; i++) {
    stack->elements[i] = init_values[i];
    stack->length++;
  }
  return stack;
}

bool ST_Push(Stack *st, int e) {
  if (st->length >= st->size) {
    return false;
  }

  st->elements[st->length] = e;
  st->length++;
  return true;
}

bool ST_Pop(Stack *st, int *element) {
  if (st->length <= 0) {
    return false;
  }

  *element = st->elements[st->length - 1];
  st->length--;
  return true;
}

bool ST_Peek(Stack *st, int *peeked_element) {
  if (st->length <= 0) {
    peeked_element = NULL;
    return false;
  }

  *peeked_element = st->elements[st->length - 1];
  return true;
}
