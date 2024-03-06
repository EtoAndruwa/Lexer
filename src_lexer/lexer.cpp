#include "lexer.hpp"

/*################################################################################################################*/

#define OUTPUT_FILE "./txt/symbols_table.txt";
#define LOG_FILE "./log/log.txt";
#define SOURCE_FILE "./txt/source.txt"   

size_t cur_tok_num   = 1;
size_t line_num      = 1;
size_t total_tok_num = 1;
FILE*  log_ptr       = nullptr;
