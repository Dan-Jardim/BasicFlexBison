%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap

%%
\n              { printf("Token: NEWLINE\n"); return NEWLINE; }
"REM"[^\n]*     { yylval.strval = strdup(yytext + 3); printf("Token: REMARK_STRING, Value: %s\n", yylval.strval); return REMARK_STRING; }
"PRINT"         { printf("Token: PRINT\n"); return PRINT; }
"LET"           { printf("Token: LET\n"); return LET; }
"IF"            { printf("Token: IF\n"); return IF; }
"THEN"          { printf("Token: THEN\n"); return THEN; }
"GOTO"          { printf("Token: GOTO\n"); return GOTO; }
"STOP"          { printf("Token: STOP\n"); return STOP; }
"RUN"           { printf("Token: RUN\n"); return RUN; }
"END"           { printf("Token: END\n"); return END; }
"DIM"           { printf("Token: DIM\n"); return DIM; }
"DATA"          { printf("Token: DATA\n"); return DATA; }
"CLOSE"         { printf("Token: CLOSE\n"); return CLOSE; }
"FOR"           { printf("Token: FOR\n"); return FOR; }
"TO"            { printf("Token: TO\n"); return TO; }
"STEP"          { printf("Token: STEP\n"); return STEP; }
"INPUT"         { printf("Token: INPUT\n"); return INPUT; }
"OUTPUT"        { printf("Token: OUTPUT\n"); return OUTPUT; }
"GOSUB"         { printf("Token: GOSUB\n"); return GOSUB; }
"NEXT"          { printf("Token: NEXT\n"); return NEXT; }
"OPEN"          { printf("Token: OPEN\n"); return OPEN; }
"AS"            { printf("Token: AS\n"); return AS; }
"POKE"          { printf("Token: POKE\n"); return POKE; }
"RETURN"        { printf("Token: RETURN\n"); return RETURN; }
"READ"          { printf("Token: READ\n"); return READ; }
"RESTORE"       { printf("Token: RESTORE\n"); return RESTORE; }
"SYS"           { printf("Token: SYS\n"); return SYS; }
"WAIT"          { printf("Token: WAIT\n"); return WAIT; }
"OR"            { printf("Token: OR\n"); return OR; }
"AND"           { printf("Token: AND\n"); return AND; }
"NOT"           { printf("Token: NOT\n"); return NOT;}
"#"             { printf("Token: HASH\n"); return HASH; }


[A-Za-z][A-Za-z0-9_]*[$%]? { yylval.strval = strdup(yytext); printf("Token: ID, Value: %s\n", yylval.strval); return ID; }
\"[^\"]*\"                   { yylval.strval = strdup(yytext); printf("Token: STRING, Value: %s\n", yylval.strval); return STRING; }
[0-9]+          { yylval.intval = atoi(yytext); printf("Token: INTEGER, Value: %d\n", yylval.intval); return INTEGER; }
[0-9]+\.[0-9]+               { yylval.realval = atof(yytext); printf("Token: REAL, Value: %f\n", yylval.realval); return REAL; }

"="             { printf("Token: EQUAL\n"); return EQUAL; }
"\+"            { printf("Token: PLUS\n"); return PLUS; }
"-"             { printf("Token: MINUS\n"); return MINUS; }
"\*"            { printf("Token: MULT\n"); return MULT; }
"/"             { printf("Token: DIV\n"); return DIV; }
"\^"            { printf("Token: POW\n"); return POW; }
"\("            { printf("Token: LPAREN\n"); return LPAREN; }
"\)"            { printf("Token: RPAREN\n"); return RPAREN; }
":"             { printf("Token: DOIS_PONTOS\n"); return DOIS_PONTOS; }
";"             { printf("Token: PONTO_VIRGULA\n"); return PONTO_VIRGULA; }
","             { printf("Token: VIRGULA\n"); return VIRGULA; }
"\."            { printf("Token: PONTO\n"); return PONTO; }
"<>"            { printf("Token: NOT_EQUAL\n"); return NOT_EQUAL; }
"<="            { printf("Token: MENOR_IGUAL\n"); return MENOR_IGUAL; }
">="            { printf("Token: MAIOR_IGUAL\n"); return MAIOR_IGUAL; }
"<"             { printf("Token: MENOR_QUE\n"); return MENOR_QUE; }
">"             { printf("Token: MAIOR_QUE\n"); return MAIOR_QUE; }

[ \t\n]+        { /* Ignore whitespace */ }

.               { printf("Unknown character: %s\n", yytext); }

%%


