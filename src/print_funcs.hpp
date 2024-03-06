#ifndef PRINT_FUNCS_HPP
#define PRINT_FUNCS_HPP

#include "lexer.hpp"

void print_summary(FILE* const log_ptr, const time_t* const t);
void print_token_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const line_num, FILE* const log_ptr);

#endif
