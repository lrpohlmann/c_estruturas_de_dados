#include "linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
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
