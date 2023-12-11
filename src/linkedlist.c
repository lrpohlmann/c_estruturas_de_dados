#include <stdio.h>

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

int main(){
    struct Element e1 = {3, 14, NULL};
    struct Element e2 = {2, 5, &e1};
    struct Element e3 = {1, 1, &e2};
    struct LinkedList ll = {&e3};

    LLRead(&ll);

    return 0;
}
