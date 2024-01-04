#include "linkedlist.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(ll_length, ll_length_tamanho_1) {
  struct LinkedList a;
  struct Element b;
  b.data = 1;
  b.next = NULL;
  a.head = &b;
  cr_assert(LL_Length(&a) == 1);
}

Test(ll_length, ll_length_tamanho_0) {
  struct LinkedList a;
  a.head = NULL;
  cr_assert(LL_Length(&a) == 0);
}

Test(ll_length, ll_length_tamanho_maior_1) {
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
