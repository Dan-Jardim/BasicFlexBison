%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constantlist.h"
#include "integerlist.h"
#include "printlist.h"
#include "expressionlist.h"
#include "idlist.h"
#include "valuelist.h"

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int intval;          
    double realval;
    char* strval;
    struct ConstantNode* const_list;
    struct IntegerNode* int_list;
    struct PrintNode* print_list;
	struct IDNode* id_list;
	struct ValueNode* value_list;
    struct ExpressionNode* expr_list;
  }

%token <intval> INTEGER
%token <realval> REAL
%token <strval> STRING ID

%token PLUS MINUS MULT DIV POW LPAREN RPAREN DOIS_PONTOS PONTO_VIRGULA VIRGULA PONTO HASH NEWLINE 
%token NOT_EQUAL EQUAL MENOR_IGUAL MAIOR_IGUAL MENOR_QUE MAIOR_QUE
%token REMARK PRINT LET IF THEN GOTO STOP RUN END DIM DATA CLOSE FOR TO STEP INPUT OUTPUT GOSUB NEXT OPEN AS POKE RETURN READ RESTORE SYS WAIT OR AND NOT

%type <intval> expression and_exp  value compare_exp not_exp mult_exp negate_exp add_exp power_exp
%type <const_list> constant_list constant
%type <int_list> integer_list
%type <print_list> print_list
%type <id_list> id_list
%type <value_list> value_list
%type <expr_list> expression_list

%%
lines:
     INTEGER statements NEWLINE lines
     | INTEGER statements NEWLINE
     ;
statements:
	  statement DOIS_PONTOS statements
	  | statement
	  ;
statement:  
     CLOSE HASH INTEGER
	 | DATA constant_list
	 | DIM ID LPAREN integer_list RPAREN
	 | END
	 | FOR ID EQUAL expression TO expression
	 | FOR ID EQUAL expression TO expression STEP INTEGER
	 | GOTO expression
	 | GOSUB expression
	 | IF expression THEN statement
	 | INPUT id_list
	 | INPUT HASH INTEGER VIRGULA id_list
	 | LET ID EQUAL expression
	 | NEXT id_list
	 | OPEN value FOR access AS HASH INTEGER
	 | POKE value_list
	 | PRINT print_list
	 | PRINT HASH INTEGER VIRGULA print_list
	 | READ id_list
	 | RETURN
	 | RESTORE
	 | RUN
	 | STOP
	 | SYS value
	 | WAIT value_list
	 | REMARK
	 ;

constant_list:
	     constant VIRGULA constant_list {$$ = append_const_node($3, $1); }
	     | constant { $$ = $1; }
	     ;

integer_list:
	    INTEGER VIRGULA integer_list { $$ = append_intlist_node($3, create_intlist_onde($1)); }
	    | INTEGER { $$ = $1; }
	    ;

expression:
	and_exp OR expression { $$ = $1 || $3; }
	  | and_exp { $$ = $1; }
	  ;

value:
     LPAREN expression RPAREN { $$ = $2; }
     | ID { $$ = 0; } // placeholder
     | ID LPAREN expression_list RPAREN { $$ = 0; } // placeholder
     | constant { $$ = $1; }
     ;

access:
      INPUT
      | OUTPUT
      ;

id_list:
     ID VIRGULA id_list { $$ = append_id_node($3, $1); }
     | ID { $$ = $1; }
     ;

expression_list:
     expression VIRGULA expression_list { $$ = append_expression_node($3, $1); }
     | expression { $$ = $1; }
     ;

value_list:
     value VIRGULA value_list { $$ = append_value_node($3, $1); }
     | value { $$ = $1; }
     ;

print_list:
     expression PONTO_VIRGULA print_list { $$ = append_print_node($3, create_print_node($1)); }
     | expression { $$ = $1; }
     |  { $$ = NULL; }
     ;

and_exp: 
	not_exp AND and_exp {$$ = $1 && $3; }
       | not_exp { $$ = $1; }
       ;

not_exp:
       NOT compare_exp {$$ = !$2}
       | compare_exp { $$ = $1; }
       ;

compare_exp:
	add_exp EQUAL compare_exp { $$ = $1 == $3; }
       | add_exp NOT_EQUAL compare_exp { $$ = $1 != $3; }
       | add_exp MAIOR_QUE compare_exp { $$ = $1 > $3; }
       | add_exp MAIOR_IGUAL compare_exp { $$ = $1 >= $3; }
       | add_exp MENOR_QUE compare_exp { $$ = $1 < $3; }
       | add_exp MENOR_IGUAL compare_exp { $$ = $1 <= $3; }
       | add_exp { $$ = $1; }
       ;




add_exp: 
	mult_exp PLUS add_exp { $$ = $1 + $3; }
       | mult_exp MINUS add_exp { $$ = $1 - $3; }
       | mult_exp { $$ = $1; }
       ;

mult_exp:
	negate_exp MULT mult_exp { $$ = $1 * $3; }
	| negate_exp DIV mult_exp { $$ = $1 / $3; }
	| negate_exp { $$ = $1; }
	;
negate_exp: 
	  MINUS power_exp { $$ = - ($2); }
	  | power_exp { $$ = $1; }
	  ;

power_exp: 
	power_exp POW value { $$ = pow($1,$3); }
	| value { $$ = $1; }
	;

constant:
	INTEGER { $$ = create_constant_integer_node($1); }
	| STRING { $$ = create_constant_string_node($1); }
	| REAL { $$ = create_constant_real_node($1); }
	;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    return yyparse();
}
