struct Element {
  int data;
  struct Element *next;
};

struct LinkedList {
  struct Element *head;
};

int LL_Length(struct LinkedList *ll);

void LL_PrintElement(struct Element *e);

void LL_Print(struct LinkedList *ll);

void LL_Append(struct LinkedList *ll, int value);

int LL_Insert(struct LinkedList *ll, int value, int index);


