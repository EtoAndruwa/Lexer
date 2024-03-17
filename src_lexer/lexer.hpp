#ifndef LEXER_HPP
#define LEXER_HPP

/*################################################################################################################*/

#include <time.h>
#include <cstdio>
#include <cstddef>

/*################################################################################################################*/

extern size_t cur_tok_num;
extern size_t line_num;
extern size_t total_tok_num;
extern FILE* log_ptr;
extern FILE* output_ptr;

#define OUTPUT_FILE "./txt/symbols_table.txt"  // The name of the output file
#define LOG_FILE "./log/log.txt"               // The name of the log file 
#define SOURCE_FILE "./txt/source.txt"         // The name of the source file

/*################################################################################################################*/

enum TOK_TYPE
{
    ARITH_OP,
    ASSIGN_OP,
    OP_BRACE,
    CL_BRACE,
    INT_NUMBER,
    FLOAT_NUMBER,
    DIGIT,
    NEW_LINE,
    KEY_WORD,
    OTHER,
    ID_OBJ,
    ID_TYPE,
    EOFILE,

    // below must be checked
    STRING,
    CHAR,
    OBJ_NAME,
    VARIABLE,
    COMMENT,
};

extern TOK_TYPE State;

/*################################################################################################################*/

#endif
