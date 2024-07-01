#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantlist.h"

ConstantNode* append_const_node(ConstantNode* list, ConstantNode* new_node) {
    new_node->next = list;
    return new_node;
}

ConstantNode* create_constant_node(ConstantType type, void* value) {
    ConstantNode* node = (ConstantNode*) malloc(sizeof(ConstantNode));
    node->type = type;
    node->next = NULL;

    node->value.int_val = 0;
    node->value.str_val = NULL; 
    node->value.real_val = 0.0; 
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


void free_constant_list(ConstantNode* list) {
    ConstantNode* current = list;
    ConstantNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}

void print_constant_node(ConstantNode* const_node) {
    if (const_node == NULL) {
        printf("Constant node is NULL\n");
        return;
    }

    switch (const_node->type) {
        case INTEGER_CONST:
            printf("%d", const_node->value.int_val);
            break;
        case STRING_CONST:
            printf("%s", const_node->value.str_val);
            break;
        case REAL_CONST:
            printf("%lf", const_node->value.real_val);
            break;
        default:
            printf("Unknown constant type\n");
            break;
    }
}
