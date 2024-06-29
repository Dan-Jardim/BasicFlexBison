#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "constants.h"

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

StatementNode* create_end_statement() {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = END_STMT;
    node->next = NULL;
    return node;
}

StatementNode* create_for_statement(char* id, ExpressionNode* from_expr, ExpressionNode* to_expr, ExpressionNode* step_expr) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = FOR_STMT;
    node->statement.for_loop.id = strdup(id);
    node->statement.for_loop.from_expr = from_expr;
    node->statement.for_loop.to_expr = to_expr;
    node->statement.for_loop.step_expr = step_expr;
    node->next = NULL;
    return node;
}

StatementNode* create_goto_statement(ExpressionNode* expr) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = GOTO_STMT;
    node->statement.goto_stmt.expr = expr;
    node->next = NULL;
    return node;
}

StatementNode* create_gosub_statement(ExpressionNode* expr) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = GOSUB_STMT;
    node->statement.gosub_stmt.expr = expr;
    node->next = NULL;
    return node;
}

StatementNode* create_if_statement(ExpressionNode* condition, StatementNode* then_statement) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = IF_STMT;
    node->statement.if_stmt.condition = condition;
    node->statement.if_stmt.then_statement = then_statement;
    node->next = NULL;
    return node;
}

StatementNode* create_input_statement(IdList* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = INPUT_STMT;
    node->statement.input_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_input_hash_statement(int hash_value, IdList* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = INPUT_STMT;
    node->statement.input_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_let_statement(char* id, ExpressionNode* expr) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = LET_STMT;
    node->statement.let_stmt.id = strdup(id);
    node->statement.let_stmt.expr = expr;
    node->next = NULL;
    return node;
}

StatementNode* create_next_statement(IdList* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = NEXT_STMT;
    node->statement.input_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_open_statement(ValueNode* value, AccessType access, int hash_value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = OPEN_STMT;
    node->statement.open_stmt.value = value;
    node->statement.open_stmt.access = access;
    node->statement.open_stmt.hash_value = hash_value;
    node->next = NULL;
    return node;
}

StatementNode* create_poke_statement(ValueList* value_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = POKE_STMT;
    node->statement.poke_stmt.value_list = value_list;
    node->next = NULL;
    return node;
}

StatementNode* create_print_statement(PrintList* print_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = PRINT_STMT;
    node->statement.print_stmt.print_list = print_list;
    node->next = NULL;
    return node;
}

StatementNode* create_print_hash_statement(int hash_value, PrintList* print_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = PRINT_STMT;
    node->statement.print_stmt.print_list = print_list;
    node->next = NULL;
    return node;
}

StatementNode* create_read_statement(IdList* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = READ_STMT;
    node->statement.read_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_return_statement() {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = RETURN_STMT;
    node->next = NULL;
    return node;
}

StatementNode* create_restore_statement() {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = RESTORE_STMT;
    node->next = NULL;
    return node;
}

StatementNode* create_run_statement() {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = RUN_STMT;
    node->next = NULL;
    return node;
}

StatementNode* create_stop_statement() {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = STOP_STMT;
    node->next = NULL;
    return node;
}

StatementNode* create_sys_statement(ValueNode* value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = SYS_STMT;
    node->statement.sys.sys_value = value;
    node->next = NULL;
    return node;
}

StatementNode* create_wait_statement(ValueList* value_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = WAIT_STMT;
    node->statement.wait_stmt.value_list = value_list;
    node->next = NULL;
    return node;
}

StatementNode* create_remark_statement(char* remark_text) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = REMARK_STMT;
    node->statement.remark.remark_text = strdup(remark_text);
    node->next = NULL;
    return node;
}

LineNode* create_line_node(int line_number, StatementNode* statement, LineNode* next_line) {
    LineNode* line = (LineNode*) malloc(sizeof(LineNode));
    line->line_number = line_number;
    line->statement = statement;
    line->next = next_line;
    return line;
}

ProgramNode* create_program_node(LineNode* first_line) {
    ProgramNode* program = (ProgramNode*) malloc(sizeof(ProgramNode));
    program->first_line = first_line;
    return program;
}
