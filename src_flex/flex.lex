%{
      #include "../src_lexer/lexer.hpp"
      #include "../src_lexer/print_funcs.hpp"
      #include "../src_lexer/file_funcs.hpp"
%}

DIGIT0 [0-9] 
DIGIT1 [1-9]
az     [a-z]
AZ     [A-Z] 


%%

"+"|"-"|"*"|"/"   {
                        print_tok_data(ARITH_OP, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                        total_tok_num++;
                        cur_tok_num++;
                  }

{az}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_OBJ, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }

{AZ}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_TYPE, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }

[+-]?{DIGIT0}    {
                  print_tok_data(DIGIT, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                  total_tok_num++;
                  cur_tok_num++;
            }

[+-]?{DIGIT1}{DIGIT0}+ {
                        print_tok_data(NUMBER, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                        total_tok_num++;
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
                  print_tok_data(NEW_LINE, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                  total_tok_num++;
                  cur_tok_num = 1;
                  line_num++;
            }

.           {
                  print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                  total_tok_num++;
                  cur_tok_num++;
            }

<<EOF>>     {
                  print_tok_data(EOFILE, yytext, cur_tok_num, total_tok_num, line_num, log_ptr);
                  return 0; 
            } 


%%

int yywrap()
{
      
}
