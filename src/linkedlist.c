#include <stdio.h>
#include <stdlib.h>


struct Element {
    int data;
    struct Element *next;
};


struct LinkedList {
    struct Element *head;
};


int LL_Length(struct LinkedList *ll){
    struct Element *current = ll->head;
    int length = 0;
    if (current) {
        length++;
    }
    while (current->next) {
        length++;
        current = current->next;
    }
    return length;
}


void LL_PrintElement(struct Element *e){
    printf("{Data: %d},", e->data);
}


void LL_Print(struct LinkedList *ll){
    printf("[");
    if (ll->head != NULL){
        struct Element *current = ll->head;

        LL_PrintElement(current);
        while (current->next){
            current = current->next;
            LL_PrintElement(current);
        }
    }
    printf("] length: %d\n", LL_Length(ll));
}


void LL_Append(struct LinkedList *ll, int value){
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

int main(){
    struct Element e2 = {33, NULL};
    struct Element e = {11, &e2};
    struct LinkedList ll = {&e};
    LL_Append(&ll, 34);
    LL_Print(&ll);
    return 0;
}
