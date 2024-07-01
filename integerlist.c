#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integerlist.h"

IntegerNode* append_int_node(IntegerNode* list, IntegerNode* new_node) {
    new_node->next = list;
    return new_node;
}

IntegerNode* create_integer_node(int value) {
    IntegerNode* node = (IntegerNode*) malloc(sizeof(IntegerNode));
    node->value = value;
    node->next = NULL;
    
    return node;
}


void free_integer_list(IntegerNode* list) {
    IntegerNode* current = list;
    IntegerNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}

