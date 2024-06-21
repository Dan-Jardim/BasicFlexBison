#ifndef ARVORE_H
#define ARVORE_H

typedef enum {

    CLOSE_STMT,
    DATA_STMT,
    DIM_STMT,
    END_STMT,
    FOR_STMT,
    GOTO_STMT,
    GOSUB_STMT,
    IF_STMT,
    INPUT_STMT,
    LET_STMT,
    NEXT_STMT,
    OPEN_STMT,
    POKE_STMT,
    PRINT_STMT,
    READ_STMT,
    RETURN_STMT,
    RESTORE_STMT,
    RUN_STMT,
    STOP_STMT,
    SYS_STMT,
    WAIT_STMT,
    REMARK_STMT

} StatementType;

typedef struct StatementNode {
    StatementType type; 
    union {
        struct {
            int hash_value;
            int integer_value;
        } close;
        struct {
           
            ConstantList* constant_list;
        } data;
        struct {
            char* id;
            IntegerList* integer_list;
        } dim;
        struct {
            char* id;
            ExpressionNode* from_expr;
            ExpressionNode* to_expr;
            ExpressionNode* step_expr; // Pode ser NULL se não houver STEP
        } for_loop;
        struct {
            ExpressionNode* expr;
        } goto_stmt, gosub_stmt;
        struct {
            ExpressionNode* condition;
            struct StatementNode* then_statement;
        } if_stmt;
        struct {
            IdList* id_list;
        } input_stmt, read_stmt;
        struct {
            char* id;
            ExpressionNode* expr;
        } let_stmt;
        struct {
            ValueNode* value;
            AccessType access;
            int hash_value;
        } open_stmt;
        struct {
            ValueList* value_list;
        } poke_stmt, wait_stmt;
        struct {
            PrintList* print_list;
        } print_stmt;
        struct {
            char* remark_text;
        }
        ValueNode* sys_value;
    } statement;
    struct StatementNode* next; // Próximo nó de instrução na lista
} StatementNode;


typedef struct LineNode {
    int line_number;        
    StatementNode* statement;  
    struct LineNode* next;  
} LineNode;


typedef struct ProgramNode {
    LineNode* first_line;  
} ProgramNode;


StatementNode* create_close_statement(int hash_value, int integer_value);
StatementNode* create_data_statement(ConstantList* constant_list);
StatementNode* create_dim_statement(char* id, IntegerList* integer_list);
StatementNode* create_end_statement();
StatementNode* create_for_statement(char* id, ExpressionNode* from_expr, ExpressionNode* to_expr, ExpressionNode* step_expr);
StatementNode* create_goto_statement(ExpressionNode* expr);
StatementNode* create_gosub_statement(ExpressionNode* expr);
StatementNode* create_if_statement(ExpressionNode* condition, StatementNode* then_statement);
StatementNode* create_input_statement(IdList* id_list);
StatementNode* create_input_hash_statement(int hash_value, IdList* id_list);
StatementNode* create_let_statement(char* id, ExpressionNode* expr);
StatementNode* create_next_statement(IdList* id_list);
StatementNode* create_open_statement(ValueNode* value, AccessType access, int hash_value);
StatementNode* create_poke_statement(ValueList* value_list);
StatementNode* create_print_statement(PrintList* print_list);
StatementNode* create_print_hash_statement(int hash_value, PrintList* print_list);
StatementNode* create_read_statement(IdList* id_list);
StatementNode* create_return_statement();
StatementNode* create_restore_statement();
StatementNode* create_run_statement();
StatementNode* create_stop_statement();
StatementNode* create_sys_statement(ValueNode* value);
StatementNode* create_wait_statement(ValueList* value_list);
StatementNode* create_remark_statement();

LineNode* create_line_node(int line_number, StatementNode* statement, LineNode* next_line);
ProgramNode* create_program_node(LineNode* first_line);


#endif