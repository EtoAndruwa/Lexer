%{
      #include "lexer.hpp"
      #include "print_funcs.hpp"
      #include "file_funcs.hpp"
      extern int yylex();
%}

DIGIT0 [0-9] 
DIGIT1 [1-9]
az     [a-z]
AZ     [A-Z] 


%%


"+"|"-"|"*"|"/"   {
                        total_tok_num++;
                        print_token_data(ARITH_OP, yytext, cur_tok_num, line_num, log_ptr);
                        cur_tok_num++;
                  }

{az}[a-zA-Z0-9_]*      {
                              total_tok_num++;
                              print_token_data(ID_OBJ, yytext, cur_tok_num, line_num, log_ptr);
                              cur_tok_num++;
                        }

{AZ}[a-zA-Z0-9_]*      {
                              total_tok_num++;
                              print_token_data(ID_TYPE, yytext, cur_tok_num, line_num, log_ptr);
                              cur_tok_num++;
                        }

{DIGIT0}    {
                  total_tok_num++;
                  print_token_data(DIGIT, yytext, cur_tok_num, line_num, log_ptr);
                  cur_tok_num++;
            }

{DIGIT1}{DIGIT0}+ {
                        total_tok_num++;
                        print_token_data(NUMBER, yytext, cur_tok_num, line_num, log_ptr);
                        cur_tok_num++;
                  }

"true"      {
                  total_tok_num++;
                  cur_tok_num++;
            }

"false"     {
                  total_tok_num++;
                  cur_tok_num++;
            }

\n          {
                  total_tok_num++;
                  print_token_data(NEW_LINE, yytext, cur_tok_num, line_num, log_ptr);
                  cur_tok_num = 1;
                  line_num++;
            }

.           {
                  print_token_data(OTHER, yytext, cur_tok_num, line_num, log_ptr);
                  total_tok_num++;
                  cur_tok_num++;
            }

<<EOF>>     {
                  print_token_data(EOFILE, yytext, cur_tok_num, line_num, log_ptr);
                  total_tok_num++; 
                  return 0; 
            } 


%%

int yywrap()
{


}

int main()
{           
      time_t t;   // for the current time
      time(&t);   // for the current time

      size_t tok = 0;

      log_ptr    = fopen("../log/log.txt", "w"); // opens the log file
      FILE* source_ptr = open_source("../txt/source.txt", log_ptr); // opens the source file
      
      yyin = source_ptr;

      yylex();

      print_summary(log_ptr, &t); 

      close_files(source_ptr, log_ptr); // closes the files 

      return 0;
}
