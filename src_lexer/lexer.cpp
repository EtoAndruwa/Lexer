#include "lexer.hpp"

/*################################################################################################################*/

size_t cur_tok_num   = 1;   // The number of current token in the LINE
size_t line_num      = 1;   // The number of the line 
size_t total_tok_num = 1;   // The total number of the tokens in the source file
size_t brackets_num  = 0;   // The number of opened brackets for close-state processing 
size_t total_err_tok_num = 0;   // The total number of error tokens in the source file
bool without_errs    = true;    // The flag for log file message
FILE*  log_ptr       = nullptr; // The pointer to the log file
FILE*  output_ptr    = nullptr; // The pointer to the output file
