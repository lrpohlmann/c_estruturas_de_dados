#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int LL_Length(struct LinkedList *ll) {
  struct LL_Element *current = ll->head;
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

int LL_Get(struct LinkedList *ll, int index, int *ptr_result) {
  int length = LL_Length(ll);
  if ((ll->head == NULL) || (index < 0) || (index >= length)) {
    return 0;
  }

  struct LL_Element *current = ll->head;
  int current_index = 0;
  while (current) {
    if (index == current_index) {
      *ptr_result = current->data;
      return 1;
    }

    current = current->next;
    current_index++;
  }

  return 0;
}

void LL_Append(struct LinkedList *ll, int value) {
  struct LL_Element *e = malloc(sizeof(*e));
  if (ll->head == NULL) {
    e->data = value;
    e->next = NULL;
    ll->head = e;
    return;
  }

  struct LL_Element *current = ll->head;
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
  struct LL_Element *current_element = ll->head;
  struct LL_Element *e = malloc(sizeof(*e));
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

int LL_Pop(struct LinkedList *ll, int index) {
  int length = LL_Length(ll);
  if ((ll->head == NULL) || (index < 0) || (index >= length)) {
    return 0;
  }

  if (index == 0) {
    struct LL_Element *to_be_deleted = ll->head;
    ll->head = ll->head->next;
    free(to_be_deleted);
    return 1;
  }
  struct LL_Element *current = ll->head;
  int current_index = 0;
  while (current) {
    if (index - 1 == current_index) {
      struct LL_Element *to_be_deleted = current->next;
      current->next = current->next->next;
      free(to_be_deleted);
      return 1;
    }
    current = current->next;
    current_index++;
  }

  return 0;
}

void LL_Sort(struct LinkedList *ll) {
  if (ll->head != NULL) {
    struct LL_Element *current = ll->head;
    while (current->next) {
      if (current->data > current->next->data) {
        int i = current->next->data;
        current->next->data = current->data;
        current->data = i;
      }
      current = current->next;
    }
  }
}
