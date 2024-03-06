EXE_FLAG = valgrind -s --leak-check=yes --show-leak-kinds=all --log-file="./log/valgrind_log.txt"
CC = g++

DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_LOG = ./log

PREF_OBJ  = ./obj/
PREF_SRC  = ./src/

SRC_NOT_FLEX = $(wildcard $(PREF_SRC)*.cpp)
OBJ_NOT_FLEX = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC_NOT_FLEX))

SRC_FLEX = $(PREF_SRC)lex.yy.c
OBJ_FLEX = $(PREF_OBJ)lex.yy.o

OBJ_ALL = $(OBJ_NOT_FLEX) $(OBJ_FLEX)

LEX_FILE_NAME = flex.lex

TARGET = lexer

all: make_lex $(TARGET) run
 
make_lex: 
	flex --header-file=./src/flex_header.hpp -o ./src/lex.yy.c ./src/flex.lex

$(TARGET) : $(OBJ_ALL) 
	$(CC) $(OBJ_ALL) -o $(TARGET).out

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp
	$(CC) -c $< -o $@

$(OBJ_FLEX):
	$(CC) -c $(SRC_FLEX) -ll -o $(OBJ_FLEX)

clear: clear_obj clear_log

clear_obj: 
	cd $(DIR_OBJ) && rm *.o

clear_log: 	
	cd $(DIR_LOG) && rm *.o

run: 
	$(EXE_FLAG) ./$(TARGET).out
