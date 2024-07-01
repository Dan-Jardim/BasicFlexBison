#ifndef INTEGERLIST_H
#define INTEGERLIST_H

typedef struct IntegerNode {
    int value;
    struct IntegerNode* next;
} IntegerNode;

typedef struct {
    IntegerNode* head;
} IntegerList;

IntegerNode* create_integer_node(int value);
IntegerNode* append_int_node(IntegerNode* list, IntegerNode* new_node);
void free_integer_list(IntegerNode* list);

#endif
