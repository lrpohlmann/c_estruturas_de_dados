#include <stdio.h>
#include <stdlib.h>

struct Element {
    int index;
    int data;
    struct Element *next;
};

struct LinkedList {
    struct Element *head;
};

void LLPrintElement(struct Element *e){
    printf("{Index: %d, Data: %d}\n", e->index, e->data);
}


void LLRead(struct LinkedList *ll){
    if (ll->head != NULL){
        struct Element *current = ll->head;
        LLPrintElement(current);
        while (current->next){
            current = current->next;
            LLPrintElement(current);
        }
    }
}


void LLAppend(struct LinkedList *ll, int value){
    struct Element *e = malloc(sizeof(*e));
    if (ll->head == NULL) {
        e->index = 0;
        e->data = value;
        e->next = NULL;
        ll->head = e;
    } else {
        struct Element *current = ll->head;
        while (current->next) {
            current = current->next;
        }
        e->index = current->index + 1;
        e->data = value;
        e->next = NULL;
        current->next = e;
    }

}

int main(){
    struct Element e1 = {3, 14, NULL};
    struct Element e2 = {2, 5, &e1};
    struct Element e3 = {1, 1, &e2};
    struct LinkedList ll = {&e3};
    LLAppend(&ll, 23);
    LLRead(&ll);
    return 0;
}
