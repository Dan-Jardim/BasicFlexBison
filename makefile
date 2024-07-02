# Makefile para compilar o parser e o scanner


CC = gcc


CFLAGS = -Wall -g -Wno-unused-function


SRCS = parser.y scanner.l constantlist.c integerlist.c idlist.c expressionlist.c arvore.c utils.c access.c python.c symbol_table.c


OBJS = parser.tab.o lex.yy.o constantlist.o integerlist.o idlist.o expressionlist.o arvore.o utils.o access.o python.o symbol_table.o


EXEC = basic



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

idlist.o: idlist.c idlist.h
	$(CC) $(CFLAGS) -c idlist.c

expressionlist.o: expressionlist.c expressionlist.h
	$(CC) $(CFLAGS) -c expressionlist.c

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c arvore.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

access.o: access.c access.h
	$(CC) $(CFLAGS) -c access.c

python.o: python.c python.h
	$(CC) $(CFLAGS) -c python.c

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(CFLAGS) -c symbol_table.c

clean:
	rm -f $(OBJS) $(EXEC) *.o
