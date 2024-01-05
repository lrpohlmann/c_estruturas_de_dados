struct LL_Element {
  int data;
  struct LL_Element *next;
};

struct LinkedList {
  struct LL_Element *head;
};

int LL_Get(struct LinkedList *ll, int index, int *ptr_result);

int LL_Length(struct LinkedList *ll);

void LL_Append(struct LinkedList *ll, int value);

int LL_Insert(struct LinkedList *ll, int value, int index);

int LL_Pop(struct LinkedList *ll, int index);  
