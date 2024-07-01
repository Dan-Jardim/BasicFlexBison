# Makefile para compilar o parser e o scanner

# Compilador a ser utilizado
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g -Wno-unused-function

# Lista dos arquivos fonte
SRCS = parser.y scanner.l constantlist.c integerlist.c printlist.c idlist.c expressionlist.c valuelist.c arvore.c utils.c access.c

# Objetos gerados pelo Bison e pelo Flex
OBJS = parser.tab.o lex.yy.o constantlist.o integerlist.o printlist.o idlist.o expressionlist.o valuelist.o arvore.o utils.o access.o

# Nome do executável a ser gerado
EXEC = basic

# Regras do Makefile

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) -lm

parser.tab.c parser.tab.h: parser.y
	bison -d -t -v parser.y > parsing_table.txt

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

constantlist.o: constantlist.c constantlist.h
	$(CC) $(CFLAGS) -c constantlist.c

integerlist.o: integerlist.c integerlist.h
	$(CC) $(CFLAGS) -c integerlist.c

printlist.o: printlist.c printlist.h
	$(CC) $(CFLAGS) -c printlist.c

idlist.o: idlist.c idlist.h
	$(CC) $(CFLAGS) -c idlist.c

expressionlist.o: expressionlist.c expressionlist.h
	$(CC) $(CFLAGS) -c expressionlist.c

valuelist.o: valuelist.c valuelist.h
	$(CC) $(CFLAGS) -c valuelist.c

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c arvore.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

access.o: access.c access.h
	$(CC) $(CFLAGS) -c access.c

clean:
	rm -f $(OBJS) $(EXEC) *.o
