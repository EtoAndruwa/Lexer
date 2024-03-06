#ifndef FILE_FUNCS_HPP
#define FILE_FUNCS_HPP

#include "lexer.hpp"

FILE* open_source(const char* const source_name, FILE* const log_ptr);
void close_files(FILE* source_ptr, FILE* log_ptr);


#endif
