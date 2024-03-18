#ifndef LEXER_HPP
#define LEXER_HPP

/*################################################################################################################*/

#include <time.h>
#include <cstdio>
#include <cstddef>
#include <string.h>

/*################################################################################################################*/

extern size_t cur_tok_num;
extern size_t line_num;
extern size_t total_tok_num;
extern size_t brackets_num;
extern size_t total_err_tok_num;
extern bool without_errs;
extern FILE* log_ptr;
extern FILE* output_ptr;


#define OUTPUT_FILE "./txt/symbols_table.txt"  // The name of the output file
#define LOG_FILE "./log/log.txt"               // The name of the log file 
#define SOURCE_FILE "./txt/source.txt"         // The name of the source file

/*################################################################################################################*/

/*
* This enum stores the tokens' types
*/
enum TOK_TYPE
{
    ARITH_OP, 
    ASSIGN_OP, 
    OP_BRACE, 
    CL_BRACE, 
    INT_NUMBER,
    FLOAT_NUMBER, 
    DIGIT, 
    OTHER, 
    ID_OBJ, 
    ID_TYPE, 
    EOFILE, 
    KEYWORD, 
    STRING, 
    LOG_OP, 
    COMMENT, 
};

/*
* This enum stores the error codes
*/
enum ERR_CODES
{
    OK,
    ERR_BRACKETS_MATCH,
    ERR_INV_STRING,
    ERR_INV_FLOAT,
    ERR_NO_OPEN_BRC,
    ERR_UNKNOWN_TOK,
};

/*################################################################################################################*/

#endif
