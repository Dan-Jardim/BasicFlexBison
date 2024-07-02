// symbol_table.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

unsigned int hash(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

SymbolTable *create_symbol_table() {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    table->size = 0;
    table->capacity = 10;
    table->symbols = malloc(table->capacity * sizeof(Symbol));
    return table;
}

void add_variable(const char *name, SymbolType type, SymbolTable *table) {
    int existing_index = -1;

    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            existing_index = i;
            break;
        }
    }

    if (existing_index != -1) {
        if (table->symbols[existing_index].type == ENUM_NULL) {
            table->symbols[existing_index].type = type;
        } else {
            fprintf(stderr, "Erro: variável %s já declarada com tipo %d.\n", name, table->symbols[existing_index].type);
        }
    } else {
        if (table->size >= table->capacity) {
            table->capacity *= 2;
            table->symbols = realloc(table->symbols, table->capacity * sizeof(Symbol));
        }
        table->symbols[table->size].name = strdup(name);
        table->symbols[table->size].type = type;
        table->size++;
    }
}



Symbol *find_symbol(const char *name, SymbolTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return &table->symbols[i];
        }
    }
    return NULL;
}

ConstantType get_expression_type(ExpressionNode *expr,SymbolTable* symbol_table) {
    switch (expr->type) {
        case EXPR_CONSTANT:
            return expr->expr.constant->type;
        case EXPR_VARIABLE:
            if (find_symbol(expr->expr.variable->id,symbol_table)->type == VAR_INTEGER){
                return INTEGER_CONST;
            } else if (find_symbol(expr->expr.variable->id,symbol_table)->type == VAR_STRING){
                return STRING_CONST;
            } else if (find_symbol(expr->expr.variable->id,symbol_table)->type == VAR_REAL){
                return REAL_CONST;
            }
        

        default:
            exit(1);
    }
}


void free_symbol_table(SymbolTable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->symbols[i].name);
    }
    free(table->symbols);
    free(table);
}
