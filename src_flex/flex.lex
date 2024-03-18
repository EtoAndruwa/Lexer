%{
      #include "../src_lexer/lexer.hpp"
      #include "../src_lexer/print_funcs.hpp"
      #include "../src_lexer/file_funcs.hpp"


%}

DIGIT0 [0-9] 
DIGIT1 [1-9]
az     [a-z]
AZ     [A-Z] 
COMMENT_V1 ("/*")([a-zA-Z0-9_\-\t\n ]*)("*/")
COMMENT_TEXT_V1 [a-zA-Z0-9_\-\t\n ]*
FULL_COMMENT_V1 {COMMENT_V1}|(("/*")((" "|\t)*({COMMENT_V1}*(" "|\t)*{COMMENT_TEXT_V1}*)*(" "|\t)*)*("*/"))

%%

("+"|"-"|"*"|"/")("=")?  {
                              print_tok_data(ARITH_OP, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              ++total_tok_num;
                              ++cur_tok_num;
                        }

"!="|"=="|">="|"<="|"&&"|">"|"<"|"||" {
                                          print_tok_data(LOG_OP, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                          ++total_tok_num;
                                          ++cur_tok_num;
                                      }

"="                        {
                                print_tok_data(ASSIGN_OP, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                ++total_tok_num;
                                ++cur_tok_num;
                           }


"("                     {
                              print_tok_data(OP_BRACE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              ++total_tok_num;
                              ++brackets_num;
                              ++cur_tok_num;
                        }

")"                     {
                              if (brackets_num > 0)
                              {
                                    --brackets_num; 
                                    print_tok_data(CL_BRACE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr); 
                              }
                              else 
                              {
                                    print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                    ++error_tok_num;
                                    brackets_num = 0;
                              }

                              ++total_tok_num;
                              ++cur_tok_num;
                        }

((i|I)(f|F))|((e|E)(l|L)(s|S)(E|e))|((L|l)([(o|O)]{2})(p|P))|((w|W)(h|H)(i|I)(L|l)(e|E))  {
                                                                                                print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                                                                                ++total_tok_num;
                                                                                                ++cur_tok_num;
                                                                                          }

((t|T)(H|h)(E|e)(n|N))|((N|n)(o|O)(T|t))|(((p|P)(r|R)(i|I)(n|N)(t|T))((L|l)(n|N))?) {
                                                                                          print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                                                                          ++total_tok_num;
                                                                                          ++cur_tok_num;
                                                                                    }

f(a|A)(L|l)(s|S)(E|e)|t(r|R)(u|U)(e|E) {
                                            print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                            ++total_tok_num;
                                            ++cur_tok_num;
                                       }

(\")([a-zA-Z\\n]*)(\")   {
                              print_tok_data(STRING, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              ++total_tok_num;
                              ++cur_tok_num;
                           }
            
(\").*(\")   {
                  print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  print_err_to_log(ERR_INV_STRING, total_tok_num, log_ptr);
                  ++error_tok_num;
                  without_errs = false;
                  ++total_tok_num;
                  ++cur_tok_num;
             } 


{FULL_COMMENT_V1}   { 
                        print_tok_data(COMMENT, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                        printf("Comment1\n");
                        ++total_tok_num;
                        ++cur_tok_num;
                  }  

{az}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_OBJ, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              ++total_tok_num;
                              ++cur_tok_num;
                        }
{AZ}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_TYPE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              ++total_tok_num;
                              ++cur_tok_num;
                        }

(0|{DIGIT1}+{DIGIT0}*)"."{DIGIT0}*  { 
                                          print_tok_data(FLOAT_NUMBER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                          ++total_tok_num;
                                          ++cur_tok_num;
                                    }

"."{DIGIT0}* {
                  print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  print_err_to_log(ERR_INV_FLOAT, total_tok_num, log_ptr);
                  ++error_tok_num;
                  without_errs = false;
                  ++total_tok_num;
                  ++cur_tok_num;
               }

{DIGIT0}    {
                  print_tok_data(DIGIT, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  ++total_tok_num;
                  ++cur_tok_num;
            }

{DIGIT1}{DIGIT0}+ {
                        print_tok_data(INT_NUMBER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                        ++total_tok_num;
                        ++cur_tok_num;
                  }

\n                {     
                        ++line_num;
                        cur_tok_num = 1;
                  }

(" "|\t)+

"--".*   {
                  print_tok_data(COMMENT, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  printf("Comment2\n");
                  ++total_tok_num;
                  ++cur_tok_num;
              }


<<EOF>>     {
                  print_tok_data(EOFILE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);

                  if (brackets_num != 0)
                  {
                        print_err_to_log(ERR_BRACKETS_MATCH, 0 , log_ptr);
                  }
                  
                  if (without_errs)
                  {
                        print_err_to_log(OK, 0 , log_ptr);
                  }

                  return 0; 
            } 

.           {
                  print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  print_err_to_log(ERR_UNKNOWN_TOK, total_tok_num, log_ptr);
                  ++error_tok_num;
                  without_errs = false;
                  ++total_tok_num;
                  ++cur_tok_num;
            }

%%

int yywrap()
{
      
}
