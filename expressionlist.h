#ifndef EXPRESSIONLIST_H
#define EXPRESSIONLIST_H

typedef struct ExpressionNode {
    // Definição de ExpressionNode vai aqui
    struct ExpressionNode* next;
} ExpressionNode;

typedef struct {
    ExpressionNode* head;
} ExpressionList;

ExpressionList* create_expression_list();
void add_expression(ExpressionList* list, ExpressionNode* expr);
void free_expression_list(ExpressionList* list);

#endif
