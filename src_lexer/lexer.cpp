#include "lexer.hpp"

/*################################################################################################################*/

size_t cur_tok_num   = 1;   //
size_t line_num      = 1;   // 
size_t total_tok_num = 1;   // 
size_t brackets_num  = 0;
size_t error_tok_num = 0;
bool without_errs    = true;
FILE*  log_ptr       = nullptr; //
FILE*  output_ptr    = nullptr; // 
