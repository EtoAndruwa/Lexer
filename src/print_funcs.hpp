#ifndef PRINT_FUNCS_HPP
#define PRINT_FUNCS_HPP

#include "lexer.hpp"

enum TOK_TYPE
{
    ARITH_OP,
    ASSIGN_OP,
    OP_BRACE,
    CL_BRACE,
    NUMBER,
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

void print_summary(FILE* const log_ptr, const time_t* const t);
void print_token_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const line_num, FILE* const log_ptr);

#endif
