#ifndef FILE_FUNCS_HPP
#define FILE_FUNCS_HPP

/*################################################################################################################*/

#include "lexer.hpp"

/*################################################################################################################*/

/*
* This function opens the file with 
* the given name (file_name)
*/
FILE* open_file(const char* const file_name, FILE* const log_ptr);

/*
* This function closes the opened
* file using pointer (file_ptr) 
*/
void close_file(FILE* file_ptr, FILE* log_ptr);

/*################################################################################################################*/

#endif
