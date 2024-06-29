#ifndef CONSTANTLIST_H
#define CONSTANTLIST_H

typedef struct ConstantNode {
    // Definição de ConstantNode vai aqui
    struct ConstantNode* next;
} ConstantNode;

typedef struct {
    ConstantNode* head;
} ConstantList;

ConstantList* create_constant_list();
void add_constant(ConstantList* list, ConstantNode* constant);
void free_constant_list(ConstantList* list);

#endif
