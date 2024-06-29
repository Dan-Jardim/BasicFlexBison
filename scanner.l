%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap

%%
\n              { return NEWLINE; }
"REM"           { return REMARK; }
"PRINT"         { return PRINT; }
"LET"           { return LET; }
"IF"            { return IF; }
"THEN"          { return THEN; }
"GOTO"          { return GOTO; }
"STOP"          { return STOP; }
"RUN"           { return RUN; }
"END"           { return END; }
"DIM"           { return DIM; }
"DATA"          { return DATA; }
"CLOSE"         { return CLOSE; }
"FOR"           { return FOR; }
"TO"            { return TO; }
"STEP"          { return STEP; }
"INPUT"         { return INPUT; }
"OUTPUT"        { return OUTPUT; }
"GOSUB"         { return GOSUB; }
"NEXT"          { return NEXT; }
"OPEN"          { return OPEN; }
"AS"            { return AS; }
"POKE"          { return POKE; }
"RETURN"        { return RETURN; }
"READ"          { return READ; }
"RESTORE"       { return RESTORE; }
"SYS"           { return SYS; }
"WAIT"          { return WAIT; }
"OR"            { return OR; }
"AND"           { return AND; }
"NOT"           { return NOT;}
"#"             { return HASH; }

[A-Za-z][A-Za-z0-9_]*[$%]? { yylval.strval = strdup(yytext); return ID; }
\"[^\"]*\"                   { yylval.strval = strdup(yytext); return STRING; }
[0-9]+          { yylval.intval = atoi(yytext); return INTEGER; }
[0-9]+\.[0-9]+               { yylval.realval = atof(yytext); return REAL; }


"="             { return EQUAL; }
"\+"            { return PLUS; }
"-"             { return MINUS; }
"\*"            { return MULT; }
"/"             { return DIV; }
"\^"            { return POW; }
"\("            { return LPAREN; }
"\)"            { return RPAREN; }
":"             { return DOIS_PONTOS; }
";"             { return PONTO_VIRGULA; }
","             { return VIRGULA; }
"\."            { return PONTO; }
"<>"            { return NOT_EQUAL; }
"<="            { return MENOR_IGUAL; }
">="            { return MAIOR_IGUAL; }
"<"             { return MENOR_QUE; }
">"             { return MAIOR_QUE; }

[ \t\n]+        { }

.               { printf("Unknown character: %s\n", yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}
