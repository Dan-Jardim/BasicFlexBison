// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct SymbolTable SymbolTable;
typedef enum SymbolType SymbolType;
typedef struct Symbol Symbol;


#include "arvore.h"

#define TABLE_SIZE 100

enum SymbolType{
    VAR_INTEGER,
    VAR_REAL,
    VAR_STRING,
    VAR_ARRAY,
    ENUM_NULL = -1 
};

typedef struct Symbol {
    char *name;
    SymbolType type; 
} Symbol;

typedef struct SymbolTable {
    Symbol *symbols;
    int size;
    int capacity;
} SymbolTable;

SymbolTable* create_symbol_table();
void insert_symbol(SymbolTable *table, char *name, SymbolType type);
Symbol *find_symbol(const char *name, SymbolTable *table);
ConstantType get_expression_type(ExpressionNode *expr,SymbolTable* symbol_table);
void free_symbol_table(SymbolTable *table);
void add_variable(const char *name, SymbolType type, SymbolTable *table) ;
#endif
