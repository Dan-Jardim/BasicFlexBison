%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int intval;          
    double realval;
    char* strval;
  }

%token <intval> INTEGER
%token <realval> REAL
%token <strval> STRING ID

%token PLUS MINUS MULT DIV POW LPAREN RPAREN DOIS_PONTOS PONTO_VIRGULA VIRGULA PONTO HASH NEWLINE 
%token NOT_EQUAL EQUAL MENOR_IGUAL MAIOR_IGUAL MENOR_QUE MAIOR_QUE
%token REMARK PRINT LET IF THEN GOTO STOP RUN END DIM DATA CLOSE FOR TO STEP INPUT OUTPUT GOSUB NEXT OPEN AS POKE RETURN READ RESTORE SYS WAIT OR AND NOT

%type <intval> expression and_exp  value compare_exp not_exp mult_exp negate_exp add_exp power_exp


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
	     constant VIRGULA constant_list
	     | constant
	     ;

integer_list:
	    INTEGER VIRGULA integer_list
	    | INTEGER
	    ;

expression: INTEGER { $$ = $1; }
	  | and_exp OR expression { $$ = $1 || $3; }
	  | and_exp
	  ;

value:
     LPAREN expression RPAREN { $$ = $2; }
     | ID
     | ID LPAREN expression_list RPAREN
     | constant
     ;

access:
      INPUT
      | OUTPUT
      ;

id_list:
       ID VIRGULA id_list
       | ID
       ;

expression_list:
	       expression VIRGULA expression_list
	       | expression
	       ;

print_list:
	  expression PONTO_VIRGULA print_list
	  | expression
	  |
	  ;

value_list:
	  value VIRGULA value_list
	  | value
	  ;

and_exp: INTEGER { $$ = $1; }
	   | not_exp AND and_exp {$$ = $1 && $3; }
       | not_exp
       ;

not_exp:
       NOT compare_exp {$$ = !$2; }
       | compare_exp
       ;

compare_exp: INTEGER { $$ = $1; }
	   | add_exp EQUAL compare_exp { $1 == $3; }
       | add_exp NOT_EQUAL compare_exp { $1 != $3; }
       | add_exp MAIOR_QUE compare_exp { $1 > $3; }
       | add_exp MAIOR_IGUAL compare_exp { $1 >= $3; }
       | add_exp MENOR_QUE compare_exp { $1 < $3; }
       | add_exp MENOR_IGUAL compare_exp { $1 <= $3; }
       | add_exp
       ;




add_exp: INTEGER { $$ = $1; }
	   | mult_exp PLUS add_exp { $$ = $1 + $3; }
       | mult_exp MINUS add_exp { $$ = $1 - $3; }
       | mult_exp
       ;

mult_exp: INTEGER { $$ = $1; }
	|negate_exp MULT mult_exp { $$ = $1 * $3; }
	| negate_exp DIV mult_exp { $$ = $1 / $3; }
	| negate_exp
	;
negate_exp: 
	  MINUS power_exp { $$ = - $2; }
	  | power_exp
	  ;

power_exp: INTEGER { $$ = $1; }
	| power_exp POW value 
	| value
	;

constant:
	INTEGER
	| STRING
	| REAL
	;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    //FILE inFile = fopen();

    return yyparse();
}

