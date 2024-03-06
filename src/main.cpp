#include "file_funcs.hpp"
#include "flex_header.hpp"
#include "print_funcs.hpp"   

int main()
{           
    time_t t;   // for the current time
    time(&t);   // for the current time

    size_t tok = 0;

    log_ptr          = fopen("./log/log.txt", "w"); // opens the log file
    FILE* source_ptr = open_source("./txt/source.txt", log_ptr); // opens the source file
    
    yyin = source_ptr;

    yylex();

    print_summary(log_ptr, &t); 

    close_files(source_ptr, log_ptr); // closes the files 

    return 0;
}
