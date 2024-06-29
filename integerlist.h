#ifndef INTEGERLIST_H
#define INTEGERLIST_H

typedef struct IntegerNode {
    int value;
    struct IntegerNode* next;
} IntegerNode;

typedef struct {
    IntegerNode* head;
} IntegerList;

IntegerList* create_integer_list();
void add_integer(IntegerList* list, int value);
void free_integer_list(IntegerList* list);

#endif
