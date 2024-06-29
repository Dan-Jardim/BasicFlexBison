#ifndef VALUELIST_H
#define VALUELIST_H

typedef struct ValueNode {
    // Definição de ValueNode vai aqui
    struct ValueNode* next;
} ValueNode;

typedef struct {
    ValueNode* head;
} ValueList;

ValueList* create_value_list();
void add_value(ValueList* list, ValueNode* value);
void free_value_list(ValueList* list);

#endif
