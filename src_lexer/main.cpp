#include "file_funcs.hpp"
#include "../src_flex/flex_header.hpp"
#include "print_funcs.hpp"   

/*################################################################################################################*/

int main()
{           
    size_t tok = 0;

    log_ptr          = fopen("./log/log.txt", "w"); // opens the log file
    FILE* source_ptr = open_source("./txt/source.txt", log_ptr); // opens the source file
    
    yyin = source_ptr;

    yylex();

    print_summary(log_ptr); 

    close_files(source_ptr, log_ptr); // closes the files 

    return 0;
}
