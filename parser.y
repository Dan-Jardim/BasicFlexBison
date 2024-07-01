%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#include "python.h"


extern FILE *yyin;

extern int yylex(void);
void yyerror(const char *s);
extern int yylineno;
extern char *yytext;
ProgramNode *root;

#define YYDEBUG 1

%}




%union {
    int intval;          
    double realval;
    char* strval;
    struct ConstantNode* const_list;
    struct IntegerNode* int_list;
    struct PrintNode* print_list;
	struct IdNode* id_list;
	struct ValueNode* value_list;
    struct ExpressionNode* expr_list;
    struct StatementNode* statement;
    struct AccessTypeNode* access_type;
    struct LineNode* line;
    struct ProgramNode* program;
  }

%token <intval> INTEGER
%token <realval> REAL
%token <strval> STRING ID REMARK_STRING

%token PLUS MINUS MULT DIV POW LPAREN RPAREN DOIS_PONTOS PONTO_VIRGULA VIRGULA PONTO HASH NEWLINE 
%token NOT_EQUAL EQUAL MENOR_IGUAL MAIOR_IGUAL MENOR_QUE MAIOR_QUE
%token REMARK PRINT LET IF THEN GOTO STOP RUN END DIM DATA CLOSE FOR TO STEP INPUT OUTPUT GOSUB NEXT OPEN AS POKE RETURN READ RESTORE SYS WAIT OR AND NOT

%type <strval> remark_text
%type <const_list> constant_list constant
%type <int_list> integer_list
%type <id_list> id_list
%type <expr_list> expression_list expression and_exp  value compare_exp not_exp mult_exp negate_exp add_exp power_exp value_list print_list
%type <statement> statement statements
%type <access_type> access
%type <line> lines
%type <program> program

%debug

%%


program:
    lines {root = create_program_node($1);}
    ;

lines:
     INTEGER statements NEWLINE lines{$$ = create_line_node($1, $2, $4); }
     | INTEGER statements NEWLINE {$$ = create_line_node($1, $2, NULL); }
     ;
statements:
	  statement DOIS_PONTOS statements {$$ = append_statement_node($3, $1); }
	  | statement {$$ = $1; }
	  ;
statement : CLOSE HASH INTEGER { $$ = create_close_statement($3, 0); }
          | DATA constant_list { $$ = create_data_statement($2); }
          | DIM ID LPAREN integer_list RPAREN { $$ = create_dim_statement($2, $4); }
          | END { $$ = create_end_statement(); }
          | FOR ID EQUAL expression TO expression { 
            $$ = create_for_statement($2, $4, $6, NULL); }
          | FOR ID EQUAL expression TO expression STEP INTEGER { $$ = create_for_statement($2, $4, $6, &($8)); }
          | GOTO expression { $$ = create_goto_statement($2); }
          | GOSUB expression { $$ = create_gosub_statement($2); }
          | IF expression THEN statement { $$ = create_if_statement($2, $4); }
          | INPUT id_list { $$ = create_input_statement($2); }
          | INPUT HASH INTEGER VIRGULA id_list { $$ = create_input_hash_statement($3, $5); }
          | LET ID EQUAL expression { $$ = create_let_statement($2, $4); }
          | NEXT id_list { $$ = create_next_statement($2); }
          | OPEN value FOR access AS HASH INTEGER { $$ = create_open_statement($2, $4, $7); }
          | POKE value_list { $$ = create_poke_statement($2); }
          | PRINT print_list { $$ = create_print_statement($2); }
          | PRINT HASH INTEGER VIRGULA print_list { $$ = create_print_hash_statement($3, $5); }
          | READ id_list { $$ = create_read_statement($2); }
          | RETURN { $$ = create_return_statement(); }
          | RESTORE { $$ = create_restore_statement(); }
          | RUN { $$ = create_run_statement(); }
          | STOP { $$ = create_stop_statement(); }
          | SYS value { $$ = create_sys_statement($2); }
          | WAIT value_list { $$ = create_wait_statement($2); }
          | REMARK remark_text { $$ = create_remark_statement($2); }
          ;

constant_list:
	     constant VIRGULA constant_list {$$ = append_const_node($3, $1); }
	     | constant { $$ = $1; }
	     ;

integer_list:
	    INTEGER VIRGULA integer_list { $$ = append_int_node($3, create_integer_node($1)); }
	    | INTEGER { $$ = create_integer_node($1); }
	    ;

expression:
	and_exp OR expression { $$ = create_expression_node_binary_op(OP_OR, $1, $3); }
	  | and_exp { $$ = $1; }
	  ;

value:
     LPAREN expression RPAREN { $$ = $2; }
     | ID { $$ = create_expression_node_variable(create_id_node($1)); } // placeholder
     | ID LPAREN expression_list RPAREN { $$ = 0; } // placeholder
     | constant { $$ = create_expression_node_constant($1); }
     ;

access:
    INPUT { $$ = create_access_node(ACCESS_INPUT); }
    | OUTPUT { $$ = create_access_node(ACCESS_OUTPUT); }
    ;

id_list:
     ID VIRGULA id_list { $$ = append_id_node($3, create_id_node($1)); }
     | ID { $$ = create_id_node($1); }
     ;

expression_list:
     expression VIRGULA expression_list { $$ = append_expression_node($3, $1); }
     | expression { $$ = $1; }
     ;

value_list:
     value VIRGULA value_list { $$ = append_expression_node($3, $1); }
     | value { $$ = $1; }
     ;

print_list:
     expression PONTO_VIRGULA print_list {
        $$ = append_expression_node($3, $1); }
     | expression { $$ = $1; }
     |  { $$ = NULL; }
     ;

and_exp: 
	not_exp AND and_exp {$$ = create_expression_node_binary_op(OP_AND, $1, $3); }
       | not_exp { $$ = $1; }
       ;

not_exp:
       NOT compare_exp {$$ = create_expression_node_binary_op(OP_NOT, NULL, $2);}
       | compare_exp { $$ = $1; }
       ;

compare_exp:
	add_exp EQUAL compare_exp { $$ = create_expression_node_binary_op(OP_EQUAL, $1, $3); }
       | add_exp NOT_EQUAL compare_exp { $$ = create_expression_node_binary_op(OP_NOT_EQUAL, $1, $3); }
       | add_exp MAIOR_QUE compare_exp { $$ = create_expression_node_binary_op(OP_GREATER_THAN, $1, $3); }
       | add_exp MAIOR_IGUAL compare_exp { $$ = create_expression_node_binary_op(OP_GREATER_EQUAL, $1, $3); }
       | add_exp MENOR_QUE compare_exp { $$ = create_expression_node_binary_op(OP_LESS_THAN, $1, $3); }
       | add_exp MENOR_IGUAL compare_exp { $$ = create_expression_node_binary_op(OP_LESS_EQUAL, $1, $3); }
       | add_exp { $$ = $1; }
       ;




add_exp: 
	mult_exp PLUS add_exp { $$ = create_expression_node_binary_op(OP_ADD, $1, $3); }
       | mult_exp MINUS add_exp { $$ = create_expression_node_binary_op(OP_SUB, $1, $3); }
       | mult_exp { $$ = $1; }
       ;

mult_exp:
	negate_exp MULT mult_exp { $$ = create_expression_node_binary_op(OP_MUL, $1, $3); }
	| negate_exp DIV mult_exp { $$ = create_expression_node_binary_op(OP_DIV, $1, $3); }
	| negate_exp { $$ = $1; }
	;
negate_exp: 
	  MINUS power_exp { $$ = create_expression_node_binary_op(OP_NEGATE, NULL, $2); }
	  | power_exp { $$ = $1; }
	  ;

power_exp: 
	power_exp POW value { $$ = create_expression_node_binary_op(OP_POW, $1, $3); }
	| value { $$ = $1; }
	;

constant:
	INTEGER { $$ = create_constant_node(INTEGER_CONST, &($1)); }
	| STRING { $$ = create_constant_node(STRING_CONST, $1); }
	| REAL { $$ = create_constant_node(REAL_CONST, &($1)); }
	;

remark_text:
    REMARK_STRING { $$ = strdup($1); }
    | remark_text REMARK_STRING { $$ = concat_strings($1, $2); }
    ;

%%


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, token '%s'\n", s, yylineno, yytext);
}



int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Não é possível abrir o arquivo");
            return 1;
        }
    } else {
        fprintf(stderr, "Uso: %s <arquivo.bas>\n", argv[0]);
        return 1;
    }

    
    //yydebug = 1;

    if (yyparse() == 0) {
        printf("Análise sintática concluída com sucesso.\n");
        generate_python_code(root);
        print_program_node(root);
    } else {
        printf("Erro na análise sintática.\n");
    }

    fclose(yyin);

    return 0;
}