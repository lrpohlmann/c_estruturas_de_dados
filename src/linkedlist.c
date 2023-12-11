#include <stdio.h>
#include <stdlib.h>

struct Element {
    int index;
    int data;
    struct Element *next;
};

struct LinkedList {
    int length;
    struct Element *head;
};

void LLPrintElement(struct Element *e){
    printf("{Index: %d, Data: %d},", e->index, e->data);
}


void LLPrint(struct LinkedList *ll){
    if (ll->head != NULL){
        struct Element *current = ll->head;

        printf("[");
        LLPrintElement(current);
        while (current->next){
            current = current->next;
            LLPrintElement(current);
        }
        printf("] length: %d\n", ll->length);
        return;
    }

    printf("[] length: %d\n", ll->length);
}


void LLAppend(struct LinkedList *ll, int value){
    struct Element *e = malloc(sizeof(*e));
    if (ll->head == NULL) {
        e->index = 0;
        e->data = value;
        e->next = NULL;
        ll->head = e;
        ll->length += 1;
        return;
    }

    struct Element *current = ll->head;
    while (current->next) {
        current = current->next;
    }
    e->index = current->index + 1;
    e->data = value;
    e->next = NULL;
    current->next = e;
}

int main(){
    struct Element e1 = {3, 14, NULL};
    struct Element e2 = {2, 5, &e1};
    struct Element e3 = {1, 1, &e2};
    struct LinkedList ll = {3, &e3};
    LLAppend(&ll, 23);
    LLPrint(&ll);
    return 0;
}
