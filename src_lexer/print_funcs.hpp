#ifndef PRINT_FUNCS_HPP
#define PRINT_FUNCS_HPP

/*################################################################################################################*/

#include "lexer.hpp"

/*################################################################################################################*/

void print_summary(FILE* const output_ptr);
void print_tok_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const total_tok_num, 
      size_t const line_num, FILE* const output_ptr);
void print_err_to_log(int const err_code, size_t last_err_tok_num, FILE* const log_ptr);
/*################################################################################################################*/

#endif
