#include "constantlist.h"

// Function to create a new integer node
ConstantNode* create_int_node(int value) {
    ConstantNode* node = (ConstantNode*)malloc(sizeof(ConstantNode));
    node->intval = value;
    node->type = 0;
    node->next = NULL;
    return node;
}

// Function to create a new real node
ConstantNode* create_real_node(double value) {
    ConstantNode* node = (ConstantNode*)malloc(sizeof(ConstantNode));
    node->realval = value;
    node->type = 1;
    node->next = NULL;
    return node;
}

// Function to create a new string node
ConstantNode* create_string_node(char* value) {
    ConstantNode* node = (ConstantNode*)malloc(sizeof(ConstantNode));
    node->strval = strdup(value);
    node->type = 2;
    node->next = NULL;
    return node;
}

// Function to append a node to the list
ConstantNode* append_const_node(ConstantNode* list, ConstantNode* new_node) {
    if (list == NULL) {
        return new_node;
    }
    ConstantNode* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return list;
}