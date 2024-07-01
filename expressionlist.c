#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "expressionlist.h"

// Função para criar nós de expressão constante
ExpressionNode* create_expression_node_constant(ConstantNode* constant) {
    ExpressionNode* node = (ExpressionNode*) malloc(sizeof(ExpressionNode));
    node->type = EXPR_CONSTANT;
    node->expr.constant = constant;
    node->next = NULL;
    return node;
}

// Função para criar nós de expressão variável
ExpressionNode* create_expression_node_variable(IdNode* variable) {
    ExpressionNode* node = (ExpressionNode*) malloc(sizeof(ExpressionNode));
    node->type = EXPR_VARIABLE;
    node->expr.variable = variable;
    node->next = NULL;
    return node;
}

// Função para criar nós de operação binária
ExpressionNode* create_expression_node_binary_op(int op, ExpressionNode* left, ExpressionNode* right) {
    ExpressionNode* node = (ExpressionNode*) malloc(sizeof(ExpressionNode));
    node->type = EXPR_BINARY_OP;
    node->expr.bin_op.op = op;
    node->expr.bin_op.left = left;
    node->expr.bin_op.right = right;
    node->next = NULL;
    return node;
}

ExpressionNode* append_expression_node(ExpressionNode* list, ExpressionNode* new_node) {
    new_node->next = list;
    return new_node;
}

void free_expression_list(ExpressionList* list) {
    ExpressionNode* current = list->head;
    ExpressionNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}



void print_expression_node(ExpressionNode* expr_node, int depth) {
    if (expr_node == NULL) {
        printf("Expression node is NULL\n");
        return;
    }
    print_indent(depth);
    //printf("Expression (type: %d)\n", expr_node->type);

    switch (expr_node->type) {
        case EXPR_CONSTANT:
            //printf("Constant expression: ");
            print_constant_node(expr_node->expr.constant);
            break;
        case EXPR_VARIABLE:
            //printf("Variable expression: ");
            printf("%s\n", expr_node->expr.variable->id);
            break;
        case EXPR_BINARY_OP:
            //printf("Binary operation expression: ");
            switch (expr_node->expr.bin_op.op) {
                case OP_ADD:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" + ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_SUB:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" - ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_MUL:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" * ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_DIV:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_POW:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_NEGATE:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_AND:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_OR:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_NOT:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_EQUAL:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_NOT_EQUAL:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_GREATER_THAN:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_GREATER_EQUAL:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_LESS_THAN:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                case OP_LESS_EQUAL:
                    printf("( ");
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    printf(" / ");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    printf(" )");
                    break;
                default:
                    printf("Unknown binary operation\n");
                    break;
            }
            printf("\n");
            break;
        default:
            printf("Unknown expression type\n");
            break;
    }
}
