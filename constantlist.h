#ifndef CONSTANTLIST_H
#define CONSTANTLIST_H

#include <stdlib.h>

typedef struct ConstantNode {
    int intval;
    double realval;
    char* strval;
    int type; // 0 for int, 1 for real, 2 for string
    struct ConstantNode* next;
} ConstantNode;

// Function to create a new integer node
ConstantNode* create_int_node(int value);


// Function to create a new real node
ConstantNode* create_real_node(double value);

// Function to create a new string node
ConstantNode* create_string_node(char* value);

// Function to append a node to the list
ConstantNode* append_const_node(ConstantNode* list, ConstantNode* new_node);

#endif