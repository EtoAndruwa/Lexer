#include "file_funcs.hpp"
#include "../src_flex/flex_header.hpp"
#include "print_funcs.hpp"   

/*################################################################################################################*/

int main()
{           
    log_ptr = fopen(, "w"); // opens the log file
    yyin = open_source_file("./txt/source.txt", log_ptr); // opens the source file;

    yylex();

    print_summary(log_ptr); 

    close_files(source_ptr, log_ptr); // closes the files 

    return 0;
}
