#ifndef PRINT_FUNCS_HPP
#define PRINT_FUNCS_HPP

/*################################################################################################################*/

#include "lexer.hpp"

/*################################################################################################################*/

void print_summary(FILE* const log_ptr);
void print_tok_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const total_tok_num, size_t const line_num, FILE* const log_ptr);

/*################################################################################################################*/

#endif
