#include "linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>

Test(ll, ll_length_tamanho_1) {
  struct LinkedList a;
  struct Element b;
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
  struct Element c;
  c.data = 5;
  c.next = NULL;
  
  struct Element b;
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
    struct Element e1;
    e1.data = 10;
    e1.next = NULL;
    struct LinkedList list;
    list.head = &e1;
    
    LL_Append(&list, 10);

    cr_assert(list.head->next->data == 10);
}
