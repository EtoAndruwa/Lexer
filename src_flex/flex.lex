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

("+"|"-"|"*"|"/")"="{0,1}  {
                              print_tok_data(ARITH_OP, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                           }

"="                        {
                              print_tok_data(ASSIGN_OP, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                           }

"("                     {
                              print_tok_data(OP_BRACE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }

")"                     {
                              print_tok_data(CL_BRACE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }

((i|I)(f|F))|((e|E)(l|L)(s|S)(E|e))|((L|l)([(o|O)]{2})(p|P))|((w|W)(h|H)(i|I)(L|l)(e|E))  {
                                                                                                print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                                                                                total_tok_num++;
                                                                                                cur_tok_num++;
                                                                                          }

((t|T)(H|h)(E|e)(n|N))|((N|n)(o|O)(T|t))|(((p|P)(r|R)(i|I)(n|N)(t|T))((L|l)(n|N))?) {
                                                                        printf("HIT!\n");
                                                                        print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                                                        total_tok_num++;
                                                                        cur_tok_num++;
                                                                      }

f(a|A)(L|l)(s|S)(E|e)|t(r|R)(u|U)(e|E) {
                                          print_tok_data(KEYWORD, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                                          total_tok_num++;
                                          cur_tok_num++;
                                       }
            
{az}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_OBJ, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }
{AZ}[a-zA-Z0-9_]*      {
                              print_tok_data(ID_TYPE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                              total_tok_num++;
                              cur_tok_num++;
                        }

(0|{DIGIT1}+{DIGIT0}*)"."{DIGIT0}* { 
                            print_tok_data(FLOAT_NUMBER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                            total_tok_num++;
                            cur_tok_num++;
                      }
{DIGIT0}    {
                  print_tok_data(DIGIT, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  total_tok_num++;
                  cur_tok_num++;
            }

{DIGIT1}{DIGIT0}+ {
                        print_tok_data(INT_NUMBER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
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
                  print_tok_data(NEW_LINE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  total_tok_num++;
                  cur_tok_num = 1;
                  line_num++;
            }

[[:space:]]+

.           {
                  print_tok_data(OTHER, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  total_tok_num++;
                  cur_tok_num++;
            }

<<EOF>>     {
                  print_tok_data(EOFILE, yytext, cur_tok_num, total_tok_num, line_num, output_ptr);
                  fprintf(log_ptr, "No errors occured.\n");
                  return 0; 
            } 


%%

int yywrap()
{
      
}
