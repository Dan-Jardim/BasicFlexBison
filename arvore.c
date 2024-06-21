#include <stdlib.h>
#include <string.h>
#include "arvore.h"

StatementNode* create_close_statement(int hash_value, int integer_value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = CLOSE_STMT;
    node->statement.close.hash_value = hash_value;
    node->statement.close.integer_value = integer_value;
    node->next = NULL;
    return node;
}

StatementNode* create_data_statement(ConstantList* constant_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = DATA_STMT;
    node->statement.data.constant_list = constant_list;
    node->next = NULL;
    return node;
}

StatementNode* create_dim_statement(char* id, IntegerList* integer_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = DIM_STMT;
    node->statement.dim.id = strdup(id);
    node->statement.dim.integer_list = integer_list;
    node->next = NULL;
    return node;
}

StatementNode* create_remark_statement(char* remark_text) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = REMARK_STMT;
    node->remark_text = strdup(remark_text);
    node->next = NULL;
    return node;
}