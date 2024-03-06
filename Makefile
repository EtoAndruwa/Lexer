EXE_FLAG = valgrind -s --leak-check=yes --show-leak-kinds=all --log-file="./log/valgrind_log.txt"
CC = g++

DIR_SRC_LEXER = ./src_lexer
DIR_SRC_FLEX = ./src_flex
DIR_OBJ = ./obj
DIR_LOG = ./log

PREF_OBJ = ./obj/
PREF_SRC_LEXER = ./src_lexer/

PREF_SRC_FLEX  = ./src_flex/

SRC_LEXER = $(wildcard $(PREF_SRC_LEXER)*.cpp)
OBJ_LEXER = $(patsubst $(PREF_SRC_LEXER)%.cpp, $(PREF_OBJ)%.o, $(SRC_LEXER))

SRC_FLEX = $(PREF_SRC_FLEX)lex.yy.c
OBJ_FLEX = $(PREF_OBJ)lex.yy.o

OBJ_ALL = $(OBJ_LEXER) $(OBJ_FLEX)

LEX_FILE_NAME = flex.lex

TARGET = lexer

all: make_lex $(TARGET) run
 
make_lex: 
	flex --header-file=$(PREF_SRC_FLEX)flex_header.hpp -o $(PREF_SRC_FLEX)lex.yy.c $(PREF_SRC_FLEX)flex.lex

$(TARGET) : $(OBJ_ALL) 
	$(CC) $(OBJ_ALL) -o $(TARGET).out

$(PREF_OBJ)%.o: $(PREF_SRC_LEXER)%.cpp
	$(CC) -c $< -o $@

$(OBJ_FLEX):
	$(CC) -c $(SRC_FLEX) -ll -o $(OBJ_FLEX)

clear: clear_obj clear_log clear_flex_files

clear_obj: 
	cd $(DIR_OBJ) && rm *.o

clear_log: 	
	cd $(DIR_LOG) && rm *.o

clear_flex_files:
	cd $(DIR_SRC_FLEX) && rm *.hpp *.c

run: 
	$(EXE_FLAG) ./$(TARGET).out
