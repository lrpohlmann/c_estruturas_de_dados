#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int LL_Length(struct LinkedList *ll) {
  struct Element *current = ll->head;
  int length = 0;
  if (current) {
    length++;
    while (current->next) {
      length++;
      current = current->next;
    }
  }

  return length;
}

void LL_PrintElement(struct Element *e) { printf("{Data: %d},", e->data); }

void LL_Print(struct LinkedList *ll) {
  printf("[");
  if (ll->head != NULL) {
    struct Element *current = ll->head;

    LL_PrintElement(current);
    while (current->next) {
      current = current->next;
      LL_PrintElement(current);
    }
  }
  printf("] length: %d\n", LL_Length(ll));
}

void LL_Append(struct LinkedList *ll, int value) {
  struct Element *e = malloc(sizeof(*e));
  if (ll->head == NULL) {
    e->data = value;
    e->next = NULL;
    ll->head = e;
    return;
  }

  struct Element *current = ll->head;
  while (current->next) {
    current = current->next;
  }
  e->data = value;
  e->next = NULL;
  current->next = e;
}

int LL_Insert(struct LinkedList *ll, int value, int index) {
  int length = LL_Length(ll);
  if ((length < index) || (0 > index)) {
    return 0;
  }

  if (length == index) {
    LL_Append(ll, value);
    return 1;
  }

  int current_index = 0;
  struct Element *current_element = ll->head;
  struct Element *e = malloc(sizeof(*e));
  while (current_element->next) {
    if (0 == index) {
      e->data = value;
      e->next = current_element;
      ll->head = e;
      return 1;
    }

    if (current_index == index - 1) {
      e->data = value;
      e->next = current_element->next;
      current_element->next = e;
      return 1;
    }
    current_element = current_element->next;
    current_index++;
  }
  return 0;
}
