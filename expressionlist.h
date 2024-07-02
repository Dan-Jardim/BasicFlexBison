#ifndef EXPRESSIONLIST_H
#define EXPRESSIONLIST_H
#include "constantlist.h"
#include "idlist.h"

typedef struct ExpressionNode {
    enum { 
        EXPR_CONSTANT,
        EXPR_VARIABLE,
        EXPR_BINARY_OP
    } type;

    union {
        ConstantNode* constant;  
        IdNode* variable;        
        struct {
            enum { OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_POW, OP_NEGATE, OP_AND, OP_OR, OP_NOT, OP_EQUAL, OP_NOT_EQUAL, OP_GREATER_THAN, OP_GREATER_EQUAL, OP_LESS_THAN, OP_LESS_EQUAL } op;
            struct ExpressionNode* left;
            struct ExpressionNode* right;
        } bin_op;                
    } expr;

    struct ExpressionNode* next;
} ExpressionNode;

typedef struct {
    ExpressionNode* head;
} ExpressionList;

ExpressionNode* append_expression_node(ExpressionNode* list, ExpressionNode* new_node);
ExpressionNode* create_expression_node_constant(ConstantNode* constant);
ExpressionNode* create_expression_node_variable(IdNode* variable);
ExpressionNode* create_expression_node_binary_op(int op, ExpressionNode* left, ExpressionNode* right);
void free_expression_list(ExpressionList* list);
void print_expression_node(ExpressionNode* expr_node, int depth);

#endif
