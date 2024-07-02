#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "expressionlist.h"

ExpressionNode* create_expression_node_constant(ConstantNode* constant) {
    ExpressionNode* node = (ExpressionNode*) malloc(sizeof(ExpressionNode));
    node->type = EXPR_CONSTANT;
    node->expr.constant = constant;
    node->next = NULL;
    return node;
}

ExpressionNode* create_expression_node_variable(IdNode* variable) {
    ExpressionNode* node = (ExpressionNode*) malloc(sizeof(ExpressionNode));
    node->type = EXPR_VARIABLE;
    node->expr.variable = variable;
    node->next = NULL;
    return node;
}

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
    //print_indent(depth);
    //printf("Expression (type: %d)\n", expr_node->type);

    switch (expr_node->type) {
        case EXPR_CONSTANT:
            //printf("Constant expression: ");
            //printf("\n");
            print_indent(depth);
            printf("Constant: ");
            print_constant_node(expr_node->expr.constant);
            break;
        case EXPR_VARIABLE:
            //printf("Variable expression: ");
            printf("\n");
            print_indent(depth);
            printf("Variable: %s\n", expr_node->expr.variable->id);
            break;
        case EXPR_BINARY_OP:
            printf("\n");
            print_indent(depth);
            printf("Expression: \n");
            print_indent(depth+1);
            switch (expr_node->expr.bin_op.op) {
                case OP_ADD:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: + \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_SUB:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: - \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_MUL:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: * \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_DIV:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: / \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_POW:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: ^ \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_NEGATE:
                    printf("Operator: - \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_AND:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: AND \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_OR:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: OR \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_NOT:
                    printf("Operator: NOT \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_EQUAL:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: = \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_NOT_EQUAL:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: <> \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_GREATER_THAN:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: > \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_GREATER_EQUAL:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: >= \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_LESS_THAN:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: <= \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
                    break;
                case OP_LESS_EQUAL:
                    print_expression_node(expr_node->expr.bin_op.left, depth + 1);
                    print_indent(depth+1);
                    printf("Operator: <= \n");
                    print_expression_node(expr_node->expr.bin_op.right, depth + 1);
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
