#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "constantlist.h"
#include "integerlist.h"
#include "printlist.h"
#include "expressionlist.h"
#include "idlist.h"
#include "valuelist.h"

StatementNode* create_close_statement(int hash_value, int integer_value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = CLOSE_STMT;
    node->statement.close.hash_value = hash_value;
    node->statement.close.integer_value = integer_value;
    node->next = NULL;
    return node;
}

StatementNode* create_data_statement(ConstantNode* constant_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = DATA_STMT;
    node->statement.data.constant_list = constant_list;
    node->next = NULL;
    return node;
}

StatementNode* create_dim_statement(char* id, IntegerNode* integer_list) {
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

StatementNode* create_for_statement(char* id, ExpressionNode* from_expr, ExpressionNode* to_expr, int* step) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = FOR_STMT;
    node->statement.for_loop.id = strdup(id);
    node->statement.for_loop.from_expr = from_expr;
    node->statement.for_loop.to_expr = to_expr;
    node->statement.for_loop.step = step;
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

StatementNode* create_input_statement(IdNode* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = INPUT_STMT;
    node->statement.input_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_input_hash_statement(int hash_value, IdNode* id_list) {
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

StatementNode* create_next_statement(IdNode* id_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = NEXT_STMT;
    node->statement.input_stmt.id_list = id_list;
    node->next = NULL;
    return node;
}

StatementNode* create_open_statement(ExpressionNode* value, AccessTypeNode* access, int hash_value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = OPEN_STMT;
    node->statement.open_stmt.value = value;
    node->statement.open_stmt.access = access;
    node->statement.open_stmt.hash_value = hash_value;
    node->next = NULL;
    return node;
}

StatementNode* create_poke_statement(ExpressionNode* value_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = POKE_STMT;
    node->statement.poke_stmt.value_list = value_list;
    node->next = NULL;
    return node;
}

StatementNode* create_print_statement(ExpressionNode* print_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = PRINT_STMT;
    node->statement.print_stmt.print_list = print_list;
    node->next = NULL;
    return node;
}

StatementNode* create_print_hash_statement(int hash_value, ExpressionNode* print_list) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = PRINT_STMT;
    node->statement.print_stmt.print_list = print_list;
    node->next = NULL;
    return node;
}

StatementNode* create_read_statement(IdNode* id_list) {
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

StatementNode* create_sys_statement(ExpressionNode* value) {
    StatementNode* node = (StatementNode*) malloc(sizeof(StatementNode));
    node->type = SYS_STMT;
    node->statement.sys.sys_value = value;
    node->next = NULL;
    return node;
}

StatementNode* create_wait_statement(ExpressionNode* value_list) {
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

StatementNode* append_statement_node(StatementNode* list, StatementNode* new_node){
    new_node->next = list;
    return new_node;
}


void print_program_node(ProgramNode* program) {
    LineNode* current_line = program->first_line;
    printf("Program\n");
    print_branch(3);
    while (current_line) {
        print_line_node(current_line, 1);
        current_line = current_line->next;
    }
}

void print_line_node(LineNode* line, int depth) {
    print_indent(depth);
    printf("Line %d:\n", line->line_number);
    StatementNode* current_statement = line->statement;
    while (current_statement) {
        print_statement_node(current_statement, depth + 1);
        current_statement = current_statement->next;
    }
    printf("\n");
}

void print_statement_node(StatementNode* statement, int depth) {
    // Implemente a impressão para cada tipo de declaração
    print_indent(depth);
    switch (statement->type) {
        case 13:
            printf("PRINT\n");
            ExpressionNode* print_list = statement->statement.print_stmt.print_list;
            while (print_list) {
                print_indent(depth + 1);
                print_expression_node(print_list, depth + 2);
                print_list = print_list->next;
            }
            break;

        case 9:
            printf("LET\n");
            print_indent(depth + 1);
            printf("%s\n", statement->statement.let_stmt.id);
            print_indent(depth + 1);
            //printf("Expression: ");
            print_expression_node(statement->statement.let_stmt.expr, depth + 2);
            break;

        case 7:
            printf("IF\n");
            print_indent(depth + 1);
            printf("Condition: ");
            print_expression_node(statement->statement.if_stmt.condition, depth + 2);  // Função auxiliar para imprimir expressões
            print_indent(depth + 1);
            printf("THEN\n");
            print_statement_node(statement->statement.if_stmt.then_statement, depth + 2);  // Imprimir a declaração associada ao THEN
            break;

        case 5:
            printf("GOTO\n");
            print_indent(depth + 1);
            //printf("");
            print_expression_node(statement->statement.goto_stmt.expr, depth + 2);  // Função auxiliar para imprimir expressões
            break;

        case 3:
            printf("END\n");
            break;

        case 8:
            printf("INPUT\n");
            print_id_node(statement->statement.input_stmt.id_list, depth + 1);  // Função auxiliar para imprimir IDs
            break;

        case 21:
            printf("REMARK\n");
            print_indent(depth + 1);
            printf(" %s\n", statement->statement.remark.remark_text);
            break;

        case 6:
            printf("GOSUB\n");
            print_indent(depth + 1);
            //printf("");
            print_expression_node(statement->statement.gosub_stmt.expr, depth + 2);  // Função auxiliar para imprimir expressões
            break;

        case 15:
            printf("RETURN\n");
            break;

        case 4:
            printf("FOR\n");
            print_indent(depth + 1);
            printf("ID: %s\n", statement->statement.for_loop.id);
            print_indent(depth + 1);
            printf("From: ");
            print_expression_node(statement->statement.for_loop.from_expr, depth + 2);  // Função auxiliar para imprimir expressões
            print_indent(depth + 1);
            printf("To: ");
            print_expression_node(statement->statement.for_loop.to_expr, depth + 2);  // Função auxiliar para imprimir expressões
            if (statement->statement.for_loop.step) {
                print_indent(depth + 1);
                printf("Step: %d\n", *(statement->statement.for_loop.step));
            } else {
                print_indent(depth + 1);
                printf("Step: (Not specified)\n");
            }
            break;

        case 10:
            printf("NEXT\n");
            print_indent(depth + 1);
            printf("%s\n", statement->statement.next_stmt.id_list->id);
            break;

        case 18:
            printf("STOP\n");
            break;

        case 17:
            printf("RUN\n");
            break;

        case 2:
            printf("DIM\n");
            print_indent(depth + 1);
            printf("%s\n", statement->statement.dim.id);
            IntegerNode* int_list = statement->statement.dim.integer_list;
            while (int_list) {
                print_indent(depth + 1);
                printf("%d\n", int_list->value);
                int_list = int_list->next;
            }
            break;

        case 1:
            printf("DATA\n");
            ConstantNode* data_list = statement->statement.data.constant_list;
            while (data_list) {
                print_indent(depth + 1);
                //printf("Data: ");
                print_constant_node(data_list);
                printf("\n");
                data_list = data_list->next;
            }
            break;

        case 0:
            printf("CLOSE\n");
            print_indent(depth + 1);
            printf("%d\n", statement->statement.close.hash_value);
            print_indent(depth + 1);
            printf(" %d\n", statement->statement.close.integer_value);
            break;

        case 14:
            printf("READ\n");
            print_id_node(statement->statement.read_stmt.id_list, depth + 1);  // Função auxiliar para imprimir IDs
            break;

        case 16:
            printf("RESTORE\n");
            break;

        case 19:
            printf("SYS\n");
            print_indent(depth + 1);
           // printf("Expression: ");
            print_expression_node(statement->statement.sys.sys_value, depth + 2);
            break;

        case 20:
            printf("WAITn");
            print_indent(depth + 1);
            //printf("Expression: ");
            print_expression_node(statement->statement.wait_stmt.value_list, depth + 2);
            break;
        
        case 11:
            printf("OPEN statement\n");
            print_indent(depth + 1);
            printf("Access type: ");
            // Adapte com base em AccessTypeNode
            //printf("Value: ");
            print_expression_node(statement->statement.open_stmt.value, depth + 2);
            print_indent(depth + 1);
            printf(" %d\n", statement->statement.open_stmt.hash_value);
            break;

        case 12:
            printf("POKE\n");
            print_indent(depth + 1);
            //printf("Value: ");
            print_expression_node(statement->statement.poke_stmt.value_list, depth + 2);
            break;

        default:
            printf("Unknown statement type: %d\n", statement->type);
            break;
    }
}


