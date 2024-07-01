#ifndef PYTHON_H
#define PYTHON_H

#include "arvore.h"
#include "constantlist.h"



void generate_python_code(ProgramNode *node);
void generate_line_code(LineNode *line);
void generate_statement_code(StatementNode *stmt);
void generate_expression_code(ExpressionNode *expr);
void generate_constant_list_code(ConstantNode* const_list);
void generate_id_list_code(IdNode *id_list);
void generate_value_list_code(ExpressionNode *value_list);
void generate_print_list_code(ExpressionNode *print_list);
void generate_remark_text_code(char *text);
void generate_access_type_code(int access_type);


#endif