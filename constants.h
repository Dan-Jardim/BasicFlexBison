#ifndef CONSTANTS_H
#define CONSTANTS_H

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

typedef struct ConstantList {
    ConstantNode* head;
    struct ConstantList* next;
} ConstantList;

// Função para criar um nó de constante
ConstantNode* create_constant_node(ConstantType type, void* value);

// Função para criar um nó de lista de constantes
ConstantList* create_constant_list(ConstantNode* constant);


#endif