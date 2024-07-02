#include "python.h"
#include "arvore.h"
#include "constantlist.h"
#include "expressionlist.h"
#include <stdio.h>
#include <stdlib.h>

char *translate_operator(int op) {
    switch (op) {
        case OP_ADD: return "+";
        case OP_SUB: return "-";
        case OP_MUL: return "*";
        case OP_DIV: return "/";
        case OP_POW: return "**";
        case OP_AND: return "and";
        case OP_OR: return "or";
        case OP_NOT: return "not";
        case OP_EQUAL: return "==";
        case OP_NOT_EQUAL: return "!=";
        case OP_GREATER_THAN: return ">";
        case OP_LESS_THAN: return "<";
        case OP_GREATER_EQUAL: return ">=";
        case OP_LESS_EQUAL: return "<=";
        case OP_NEGATE: return "-";
        default: return "# Unknown operator";
    }
}

void generate_python_code(ProgramNode* node) {
    if (!node) return;
    LineNode *line = node->first_line;
    while (line) {
        generate_line_code(line);
        line = line->next;
    }
}

void generate_line_code(LineNode *line) {
    //printf("# Line %d\n", line->line_number);
    generate_statement_code(line->statement);
    printf("\n");

}

void generate_statement_code(StatementNode *stmt) {
    if (!stmt) return;

    switch (stmt->type) {
        case 13:  // PRINT
            printf("print(");
            generate_print_list_code(stmt->statement.print_stmt.print_list);
            printf(")\n");
            break;

        case 9:  // LET
            printf("%s = ", stmt->statement.let_stmt.id);
            generate_expression_code(stmt->statement.let_stmt.expr);
            printf("\n");
            break;

        case 7:  // IF
            printf("if ");
            generate_expression_code(stmt->statement.if_stmt.condition);
            printf(":\n");
            generate_statement_code(stmt->statement.if_stmt.then_statement);
            break;

        case 5:  // GOTO
            printf("goto_%d()\n", (int)stmt->statement.goto_stmt.expr->expr.constant->value.int_val);
            break;

        case 3:  // END
            //printf("exit()\n");
            break;

        case 8:  // INPUT
            generate_id_list_code(stmt->statement.input_stmt.id_list);
            printf(" = input()\n");
            break;

        case 21:  // REMARK
            generate_remark_text_code(stmt->statement.remark.remark_text);
            break;

        case 6:  // GOSUB
            printf("# GOSUB %d\n", (int)stmt->statement.gosub_stmt.expr->expr.constant->value.int_val);
            break;

        case 15:  // RETURN
            printf("return\n");
            break;

        case 4:  // FOR
            printf("for %s in range(", stmt->statement.for_loop.id);
            generate_expression_code(stmt->statement.for_loop.from_expr);
            printf(", ");
            generate_expression_code(stmt->statement.for_loop.to_expr);
            if (stmt->statement.for_loop.step) {
                printf(", ");
                printf("%d",*stmt->statement.for_loop.step);
            }
            printf("):\n");
            break;

        case 10:  // NEXT
            //printf("# NEXT %s\n", stmt->statement.next_stmt.id_list->id);
            break;

        case 18:  // STOP
            printf("stop\n");
            break;

        case 17:  // RUN
            printf("run()\n");
            break;

        case 2:  // DIM
            printf("# DIM %s (not implemented)\n", stmt->statement.dim.id);
            break;

        case 1:  // DATA
            printf("# DATA ");
            generate_constant_list_code(stmt->statement.data.constant_list);
            printf("\n");
            break;

        case 0:  // CLOSE
            printf("file.close");
            //printf("# CLOSE %d, %d\n", stmt->statement.close.hash_value, stmt->statement.close.integer_value);
            break;

        case 14:  // READ
            printf("# READ ");
            generate_id_list_code(stmt->statement.read_stmt.id_list);
            printf("\n");
            break;

        case 16:  // RESTORE
            printf("# RESTORE\n");
            break;

        case 19:  // SYS
            printf("sys(");
            generate_expression_code(stmt->statement.sys.sys_value);
            printf(")\n");
            break;

        case 20:  // WAIT
            printf("wait(");
            generate_value_list_code(stmt->statement.wait_stmt.value_list);
            printf(")\n");
            break;

        case 11:  // OPEN
            printf("file = open(");
            generate_expression_code(stmt->statement.open_stmt.value);
            printf(")\n");
            //printf("# OPEN HASH %d\n", stmt->statement.open_stmt.hash_value);
            break;

        case 12:  // POKE
            printf("poke_func(");
            generate_value_list_code(stmt->statement.poke_stmt.value_list);
            printf(")\n");
            break;

        default:
            printf("# Unknown statement type %d\n", stmt->type);
            break;
    }

    if (stmt->next) {
        generate_statement_code(stmt->next);
    }
}

void generate_expression_code(ExpressionNode* expr) {
    if (!expr) return;

    switch (expr->type) {
        case EXPR_CONSTANT:
            if (expr->expr.constant->type == INTEGER_CONST && expr->expr.constant->value.int_val != 0) {
                printf("%d", expr->expr.constant->value.int_val);
            }
            else if (expr->expr.constant->type == STRING_CONST && expr->expr.constant->value.str_val != NULL) {
                printf("%s", expr->expr.constant->value.str_val);
            }
            else if (expr->expr.constant->type == REAL_CONST && expr->expr.constant->value.real_val != 0.0) {
                printf("%f", expr->expr.constant->value.real_val);
            }
            break;

        case EXPR_VARIABLE:
            if (expr->expr.variable->id) {
                printf("%s", (char *)expr->expr.variable->id);
            }
            break;

        case EXPR_BINARY_OP:
            if (expr->expr.bin_op.left == NULL){
                printf(" %s ", translate_operator(expr->expr.bin_op.op));
                generate_expression_code(expr->expr.bin_op.left);
            }
            else {
                generate_expression_code(expr->expr.bin_op.left);
                printf(" %s ", translate_operator(expr->expr.bin_op.op));
                generate_expression_code(expr->expr.bin_op.right);
            }
            break;

        

        default:
            printf("# Unknown expression type %d\n", expr->type);
            break;
    }
}

void generate_constant_list_code(ConstantNode* const_list) {
    if (!const_list) return;

    switch (const_list->type) {
        case INTEGER_CONST:
            printf("%d", const_list->value.int_val);
            break;

        case STRING_CONST:
            printf("\"%s\"", (char *)const_list->value.str_val);
            break;

        case REAL_CONST:
            printf("%f", const_list->value.real_val);
            break;

        default:
            printf("# Unknown constant type %d\n", const_list->type);
            break;
    }

    if (const_list->next) {
        printf(", ");
        generate_constant_list_code(const_list->next);
    }
}

void generate_id_list_code(IdNode *id_list) {
    if (!id_list) return;

    printf("%s", id_list->id);

    if (id_list->next) {
        printf(", ");
        generate_id_list_code(id_list->next);
    }
}

void generate_value_list_code(ExpressionNode *value_list) {
    if (!value_list) return;

    generate_expression_code(value_list);

    if (value_list->next) {
        printf(", ");
        generate_value_list_code(value_list->next);
    }
}

void generate_print_list_code(ExpressionNode *print_list) {
    if (!print_list) return;

    generate_expression_code(print_list);

    if (print_list->next) {
        printf(", ");
        generate_print_list_code(print_list->next);
    }
}

void generate_remark_text_code(char *text) {
    printf("# %s\n", text);
}

void generate_access_type_code(int access_type) {
    switch (access_type) {
        case ACCESS_INPUT:
            printf("INPUT");
            break;

        case ACCESS_OUTPUT:
            printf("OUTPUT");
            break;

        default:
            printf("# Unknown access type %d\n", access_type);
            break;
    }
}


