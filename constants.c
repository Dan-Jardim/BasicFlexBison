#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "arvore.h"

ConstantNode* create_constant_node(ConstantType type, void* value) {
    ConstantNode* node = (ConstantNode*) malloc(sizeof(ConstantNode));
    node->type = type;
    node->next = NULL;
    switch (type) {
        case INTEGER_CONST:
            node->value.int_val = *(int*)value;
            break;
        case STRING_CONST:
            node->value.str_val = strdup((char*)value);
            break;
        case REAL_CONST:
            node->value.real_val = *(double*)value;
            break;
    }
    return node;
}

ConstantList* create_constant_list(ConstantNode* constant) {
    ConstantList* list = (ConstantList*) malloc(sizeof(ConstantList));
    list->head = constant;
    list->next = NULL;
    return list;
}
