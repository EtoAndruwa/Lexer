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
extern size_t brackets_num;
extern size_t error_tok_num;
extern FILE* log_ptr;
extern FILE* output_ptr;

#define OUTPUT_FILE "./txt/symbols_table.txt"  // The name of the output file
#define LOG_FILE "./log/log.txt"               // The name of the log file 
#define SOURCE_FILE "./txt/source.txt"         // The name of the source file

/*################################################################################################################*/

enum TOK_TYPE
{
    ARITH_OP, // used
    ASSIGN_OP, // used
    OP_BRACE, // used
    CL_BRACE, // used
    INT_NUMBER,// used
    FLOAT_NUMBER, // used
    DIGIT, // used
    OTHER, // used
    ID_OBJ, // used
    ID_TYPE, // used
    EOFILE, // used
    KEYWORD, // used
    STRING, // used
    LOG_OP, // used

    // below must be checked
    COMMENT, // used
};

enum ERR_CODES
{
    NO_OPENING_BR,
    NO_CLOSING_BR,


};

/*################################################################################################################*/

#endif
