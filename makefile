# Makefile para compilar o parser e o scanner

# Compilador a ser utilizado
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Lista dos arquivos fonte
SRCS = parser.y scanner.l constantlist.c integerlist.c printlist.c idlist.c expressionlist.c valuelist.c

# Objetos gerados pelo Bison e pelo Flex
OBJS = parser.tab.c lex.yy.c

# Nome do executável a ser gerado
EXEC = basic

# Regras do Makefile

all: $(EXEC)

$(EXEC): $(OBJS) constantlist.o integerlist.o printlist.o idlist.o expressionlist.o valuelist.o
	$(CC) $(CFLAGS) $(OBJS) constantlist.o integerlist.o printlist.o idlist.o expressionlist.o valuelist.o -o $(EXEC) -lm

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

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

clean:
	rm -f $(OBJS) $(EXEC) *.o