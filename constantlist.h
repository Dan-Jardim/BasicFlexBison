#ifndef CONSTANTLIST_H
#define CONSTANTLIST_H

typedef enum {
    INTEGER_CONST,
    STRING_CONST,
    REAL_CONST
} ConstantType;


typedef struct ConstantNode {
    ConstantType type;
    union {
        int int_val;
        char* str_val;
        double real_val;
    } value;
    struct ConstantNode* next;
} ConstantNode;

typedef struct {
    ConstantNode* head;
} ConstantList;

ConstantNode* create_constant_node(ConstantType type, void* value);
ConstantNode* append_const_node(ConstantNode* list, ConstantNode* new_node);
void free_constant_list(ConstantNode* list);
void print_constant_node(ConstantNode* const_node);

#endif
