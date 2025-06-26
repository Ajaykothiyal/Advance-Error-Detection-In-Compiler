CC = gcc
CFLAGS = -Wall -Wextra
FLEX = win_flex
BISON = win_bison

all: compiler

compiler: lex.yy.c parser.tab.c
	$(CC) $(CFLAGS) -o compiler.exe lex.yy.c parser.tab.c

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

clean:
	del /F /Q compiler.exe lex.yy.c parser.tab.c parser.tab.h

test: compiler
	.\compiler.exe test.c

.PHONY: all clean test 