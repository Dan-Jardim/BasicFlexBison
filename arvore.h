#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantlist.h"
#include "integerlist.h"
#include "expressionlist.h"
#include "idlist.h"
#include "utils.h"
#include "access.h"
#include "symbol_table.h"

typedef enum {
    CLOSE_STMT,//0
    DATA_STMT,//1
    DIM_STMT,//2
    END_STMT,//3
    FOR_STMT,//4
    GOTO_STMT,//5
    GOSUB_STMT,//6
    IF_STMT,//7
    INPUT_STMT,//8
    LET_STMT,//9
    NEXT_STMT,//10
    OPEN_STMT,//11
    POKE_STMT,//12
    PRINT_STMT,//13
    READ_STMT,//14
    RETURN_STMT,//15
    RESTORE_STMT,//16
    RUN_STMT,//17
    STOP_STMT,//18
    SYS_STMT,//19
    WAIT_STMT,//20
    REMARK_STMT//21
} StatementType;


typedef struct StatementNode {
    StatementType type; 
    union {
        struct {
            int hash_value;
            int integer_value;
        } close;
        struct {
            ConstantNode* constant_list;
        } data;
        struct {
            char* id;
            IntegerNode* integer_list;
        } dim;
        struct {
            char* id;
            ExpressionNode* from_expr;
            ExpressionNode* to_expr;
            int* step; 
        } for_loop;
        struct {
            ExpressionNode* expr;
        } goto_stmt, gosub_stmt;
        struct {
            ExpressionNode* condition;
            struct StatementNode* then_statement;
        } if_stmt;
        struct {
            IdNode* id_list;
        } input_stmt, read_stmt, next_stmt;
        struct {
            char* id;
            ExpressionNode* expr;
        } let_stmt;
        struct {
            ExpressionNode* value;
            AccessTypeNode* access;
            int hash_value;
        } open_stmt;
        struct {
            ExpressionNode* value_list;
        } poke_stmt, wait_stmt;
        struct {
            ExpressionNode* print_list;
        } print_stmt;
        struct {
            char* remark_text;
        } remark;
        struct {
            ExpressionNode* sys_value;
        } sys;
    } statement;
    struct StatementNode* next; 
} StatementNode;

typedef struct LineNode {
    int line_number;        
    StatementNode* statement;  
    struct LineNode* next;  
} LineNode;

typedef struct ProgramNode {
    LineNode* first_line;  
} ProgramNode;

LineNode* create_line_node(int line_number, StatementNode* statement, LineNode* next_line);
ProgramNode* create_program_node(LineNode* first_line);
StatementNode* create_close_statement(int hash_value, int integer_value);
StatementNode* create_data_statement(ConstantNode* constant_list);
StatementNode* create_dim_statement(char* id, IntegerNode* integer_list);
StatementNode* create_end_statement();
StatementNode* create_for_statement(char* id, ExpressionNode* from_expr, ExpressionNode* to_expr, int* step);
StatementNode* create_goto_statement(ExpressionNode* expr);
StatementNode* create_gosub_statement(ExpressionNode* expr);
StatementNode* create_if_statement(ExpressionNode* condition, StatementNode* then_statement);
StatementNode* create_input_statement(IdNode* id_list);
StatementNode* create_input_hash_statement(int hash_value, IdNode* id_list);
StatementNode* create_let_statement(char* id, ExpressionNode* expr);
StatementNode* create_next_statement(IdNode* id_list);
StatementNode* create_open_statement(ExpressionNode* value, AccessTypeNode* access, int hash_value);
StatementNode* create_poke_statement(ExpressionNode* value_list);
StatementNode* create_print_statement(ExpressionNode* print_list);
StatementNode* create_print_hash_statement(int hash_value, ExpressionNode* print_list);
StatementNode* create_read_statement(IdNode* id_list);
StatementNode* create_return_statement();
StatementNode* create_restore_statement();
StatementNode* create_run_statement();
StatementNode* create_stop_statement();
StatementNode* create_sys_statement(ExpressionNode* value);
StatementNode* create_wait_statement(ExpressionNode* value_list);
StatementNode* create_remark_statement(char* remark_text);
StatementNode* append_statement_node(StatementNode* list, StatementNode* new_node);

LineNode* create_line_node(int line_number, StatementNode* statement, LineNode* next_line);
ProgramNode* create_program_node(LineNode* first_line);

void print_program_node(ProgramNode* program);
void print_line_node(LineNode* line, int depth);
void print_statement_node(StatementNode* statement, int depth);
int check_variable_type(char *var_name, SymbolType expected_type, SymbolTable* symbol_table);



#endif
