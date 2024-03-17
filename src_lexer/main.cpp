#include "file_funcs.hpp"
#include "../src_flex/flex_header.hpp"
#include "print_funcs.hpp"  

/*################################################################################################################*/

int main()
{           
    log_ptr = open_file(LOG_FILE, nullptr); // opens the log file
    output_ptr = open_file(OUTPUT_FILE, log_ptr); // opens the output file
    yyin    = open_file(SOURCE_FILE, log_ptr); // opens the source file;

    yylex();

    print_summary(output_ptr); // prints the summary of lexical analysis 

    close_file(yyin, log_ptr); // closes the source file
    close_file(output_ptr, log_ptr); // closes the source file
    close_file(log_ptr, log_ptr); // closes the log file

    yylex_destroy(); // frees the memory allocated by the Flex
    return 0;
}
