#include "linkedlist.h"
#include "stack.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Test(ll, ll_length_tamanho_1) {
  struct LinkedList a;
  struct LL_Element b;
  b.data = 1;
  b.next = NULL;
  a.head = &b;
  cr_assert(LL_Length(&a) == 1);
}

Test(ll, ll_length_tamanho_0) {
  struct LinkedList a;
  a.head = NULL;
  cr_assert(LL_Length(&a) == 0);
}

Test(ll, ll_length_tamanho_maior_1) {
  struct LL_Element c;
  c.data = 5;
  c.next = NULL;

  struct LL_Element b;
  b.data = 1;
  b.next = &c;

  struct LinkedList a;
  a.head = &b;
  cr_assert(LL_Length(&a) == 2);
}

Test(ll, ll_get) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 8;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 2;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  int get_value = 0;
  int result = LL_Get(&list, 2, &get_value);
  cr_assert(result == 1);
  cr_assert(get_value == 8);
}

Test(ll, ll_get_fail) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 8;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 2;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  int get_value = 0;
  int result = LL_Get(&list, 400, &get_value);
  cr_assert(result == 0);
  cr_assert(get_value == 0);
}

Test(ll, ll_append_lista_vazia) {
  struct LinkedList list;
  list.head = NULL;

  LL_Append(&list, 2);

  cr_assert(list.head->data == 2);
}

Test(ll, ll_append_lista_preenchida) {
  struct LL_Element e1;
  e1.data = 10;
  e1.next = NULL;
  struct LinkedList list;
  list.head = &e1;

  LL_Append(&list, 10);

  cr_assert(list.head->next->data == 10);
}

Test(ll, ll_insert_lista_vazia) {
  struct LinkedList list;
  list.head = NULL;

  int insert_result = LL_Insert(&list, 10, 0);
  cr_assert(insert_result == 1);
}

Test(ll, ll_insert_lista_preenchida_0) {
  struct LL_Element e2;
  e2.data = 3;
  e2.next = NULL;

  struct LL_Element e1;
  e1.data = 5;
  e1.next = &e2;

  struct LinkedList list;
  list.head = &e1;

  int insert_result = LL_Insert(&list, 10, 0);
  cr_assert(insert_result == 1);
  cr_assert(list.head->data == 10);
}

Test(ll, ll_insert_lista_preenchida_fim) {
  struct LL_Element e2;
  e2.data = 3;
  e2.next = NULL;

  struct LL_Element e1;
  e1.data = 5;
  e1.next = &e2;

  struct LinkedList list;
  list.head = &e1;

  int insert_result = LL_Insert(&list, 10, 2);
  cr_assert(insert_result == 1);
  cr_assert(list.head->next->next->data == 10);
}

Test(ll, ll_insert_lista_preenchida_meio) {
  struct LL_Element e2;
  e2.data = 3;
  e2.next = NULL;

  struct LL_Element e1;
  e1.data = 5;
  e1.next = &e2;

  struct LinkedList list;
  list.head = &e1;

  int insert_result = LL_Insert(&list, 10, 1);
  cr_assert(insert_result == 1);
  cr_assert(list.head->next->data == 10);
}

Test(ll, ll_insert_indice_menor_que_0) {
  struct LL_Element e2;
  e2.data = 3;
  e2.next = NULL;

  struct LL_Element e1;
  e1.data = 5;
  e1.next = &e2;

  struct LinkedList list;
  list.head = &e1;

  int insert_result = LL_Insert(&list, 10, -1);
  cr_assert(insert_result == 0);
}

Test(ll, ll_insert_indice_maior_que_a_lista) {
  struct LL_Element e2;
  e2.data = 3;
  e2.next = NULL;

  struct LL_Element e1;
  e1.data = 5;
  e1.next = &e2;

  struct LinkedList list;
  list.head = &e1;

  int insert_result = LL_Insert(&list, 10, 100);
  cr_assert(insert_result == 0);
}

Test(ll, ll_pop_length_0) {
  struct LinkedList list;
  list.head = NULL;

  int pop_result = LL_Pop(&list, 0);
  cr_assert(pop_result == 0);
}

Test(ll, ll_pop_length_index_less_than_0) {
  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = NULL;

  struct LinkedList list;
  list.head = e1;

  int pop_result = LL_Pop(&list, -1);
  cr_assert(pop_result == 0);
}

Test(ll, ll_pop_length_index_greater_than_length) {
  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = NULL;

  struct LinkedList list;
  list.head = e1;

  int pop_result = LL_Pop(&list, 2);
  cr_assert(pop_result == 0);
}

Test(ll, ll_pop_length_index_0) {
  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = NULL;

  struct LinkedList list;
  list.head = e1;

  int pop_result = LL_Pop(&list, 0);
  cr_assert(pop_result == 1);
  cr_assert(list.head == NULL);
}

Test(ll, ll_pop_middle) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 8;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 2;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  int pop_result = LL_Pop(&list, 1);
  cr_assert(pop_result == 1);
  cr_assert(e1->next == e3);
}

Test(ll, ll_pop_end) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 8;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 2;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  int pop_result = LL_Pop(&list, 2);
  cr_assert(pop_result == 1);
  cr_assert(e2->next == NULL);
}

Test(ll, ll_sort) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 8;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 2;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 10;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  LL_Sort(&list);
  struct LL_Element *current = list.head;
  while (current->next) {
    cr_assert(current->next->data >= current->data);
    current = current->next;
  }
}

Test(ll, ll_sort_empty_list) {
  struct LinkedList list;
  list.head = NULL;

  LL_Sort(&list);
  cr_assert(list.head == NULL);
}

Test(ll, ll_sort_do_nothing) {
  struct LL_Element *e3 = (struct LL_Element *)malloc(sizeof(*e3));
  e3->data = 10;
  e3->next = NULL;

  struct LL_Element *e2 = (struct LL_Element *)malloc(sizeof(*e2));
  e2->data = 6;
  e2->next = e3;

  struct LL_Element *e1 = (struct LL_Element *)malloc(sizeof(*e1));
  e1->data = 6;
  e1->next = e2;

  struct LinkedList list;
  list.head = e1;

  LL_Sort(&list);
  struct LL_Element *current = list.head;
  while (current->next) {
    cr_assert(current->next->data >= current->data);
    current = current->next;
  }
}

Test(st, st_init_size_0) {
  Stack *stack = ST_Init(0, NULL);
  cr_assert_eq(stack, NULL);
}

Test(st, st_init_size_non_0) {
  Stack *stack = ST_Init(8, NULL);
  cr_assert_eq(stack->size, 8);
  cr_assert_eq(stack->length, 0);
  cr_assert_not_null(stack->elements);
}

Test(st, st_init_with_values) {
  int init_values[] = {5, 7, 9, 11};
  Stack *stack = ST_Init(4, init_values);

  for (int i = 0; i < stack->size; i++) {
    cr_assert_eq(stack->elements[i], init_values[i]);
  };
  cr_assert_eq(stack->length, 4);
}

Test(st, st_push_ok) {
  const int PUSH_VALUE = 100;
  const int EXPECTED_LENGTH = 1;
  Stack *stack = ST_Init(5, NULL);  

  cr_assert(ST_Push(stack, PUSH_VALUE));
  cr_assert_eq(stack->elements[0], PUSH_VALUE);
  cr_assert_eq(stack->length, EXPECTED_LENGTH);
}

Test(st, st_push_stack_full) {
  const int INIT_STACK_SIZE = 6;
  const int PUSH_VALUE = 12;

  int init_values[] = {6, 7, 8, 9, 10, 11};
  Stack *stack = ST_Init(INIT_STACK_SIZE, init_values);

  cr_assert(!ST_Push(stack, PUSH_VALUE));
  cr_assert(stack->elements[5] != PUSH_VALUE);
}

Test(st, st_push_until_its_full) {
    const int INIT_STACK_SIZE = 3;
    
    Stack *stack = ST_Init(INIT_STACK_SIZE, NULL);
    
    int push_value = 1;
    bool push_sucess = ST_Push(stack, push_value);
    while (push_sucess) {
        push_value++;
        push_sucess = ST_Push(stack, push_value);
    }

    cr_assert(stack->elements[0] == 1);
    cr_assert(stack->elements[1] == 2);
    cr_assert(stack->elements[2] == 3);
    cr_assert(stack->length == 3);
}

Test(st, st_pop_empty_stack){
    Stack *stack = ST_Init(3, NULL);
    int element = 0;

    bool pop_sucess = ST_Pop(stack, &element);
    cr_assert(!pop_sucess);
    cr_assert_eq(element, 0);
    cr_assert_eq(stack->length, 0);
}

Test(st, st_pop_ok){
    int init_values[] = {5,6,7,8};
    Stack *stack = ST_Init(4, init_values);
    int element = 0;

    bool pop_sucess = ST_Pop(stack, &element);

    cr_assert(pop_sucess);
    cr_assert_eq(element, 8);
    cr_assert_eq(stack->length, 3);
}

Test(st, st_pop_until_empty) {
    int init_values[] = {9, 3, 5, 1};
    Stack *stack = ST_Init(4, init_values);
    int element = 0;

    bool pop_sucess = ST_Pop(stack, &element);
    while (pop_sucess) {
        pop_sucess = ST_Pop(stack, &element);
    }

    cr_assert_eq(stack->length, 0);
}

Test(st, st_peek_empty_stack) {
    Stack *stack = ST_Init(8, NULL);
    int element = -1;

    bool peek_sucess = ST_Peek(stack, &element);
    cr_assert(!peek_sucess);
    cr_assert_eq(element, -1);
}

Test(st, st_peek_ok) {
    int init_values[] = {5, 7, 9};
    Stack *stack = ST_Init(3, init_values);
    int element = -1;

    bool peek_sucess = ST_Peek(stack, &element);
    cr_assert(peek_sucess);
    cr_assert_eq(element, 9);

    int element2 = -1;
    ST_Peek(stack, &element2);
    cr_assert_eq(element2, 9);


}
