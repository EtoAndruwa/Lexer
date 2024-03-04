%{
      #include <time.h>

      void print_token_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const line_num, FILE* const log_ptr);

      size_t cur_tok_num = 1;
      size_t line_num  = 1;
      size_t total_tok_num = 1;


      FILE* log_ptr = nullptr;

      enum tok_type
      {
            ARITH_OP,
            ASSIGN_OP,
            OP_BRACE,
            CL_BRACE,
            NUMBER,
            DIGIT,
            NEW_LINE,
            KEY_WORD,
            OTHER,
            ID_OBJ,
            ID_TYPE,
            EOFILE,

            // below must be checked
            STRING,
            CHAR,
            OBJ_NAME,
            VARIABLE,
            COMMENT,
      };
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

FILE* open_source(const char* const source_name, FILE* const log_ptr)
{
      FILE* source_ptr = fopen(source_name, "r");

      if (source_ptr == nullptr)
      {
            fprintf(log_ptr, "ERROR: enable to open source file\n");
      }

      return source_ptr;
}

void print_summary(FILE* const log_ptr, const time_t* const t)
{
      fprintf(log_ptr, "\n============SUMMARY============\n");
      fprintf(log_ptr, "Updated: %s", ctime(t));
      fprintf(log_ptr, "Total number of token: %ld\n", total_tok_num);
      fprintf(log_ptr, "Total number of lines: %ld\n", line_num);
      fprintf(log_ptr, "============SUMMARY============\n");
}

void print_token_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const line_num, FILE* const log_ptr)
{
      fprintf(log_ptr, "(LINE: %ld, TOKEN_NUM: %ld) TOK_TYPE: ", line_num, cur_tok_num);
      
      switch (tok_type)
      {
      case ARITH_OP:
            {
                  fprintf(log_ptr, "ARITH_OP");
                  break;
            }
      case ASSIGN_OP:
            {
                  fprintf(log_ptr, "ASSIGN_OP");
                  break;
            }
      case OP_BRACE:
            {
                  fprintf(log_ptr, "OP_BRACE");
                  break;
            }
      case CL_BRACE:
            {
                  fprintf(log_ptr, "CL_BRACE");
                  break;
            }
      case NUMBER:
            {
                  fprintf(log_ptr, "NUMBER");
                  break;
            }
      case DIGIT:
            {
                  fprintf(log_ptr, "DIGIT");
                  break;
            }
      case NEW_LINE:
            {
                  fprintf(log_ptr, "NEW_LINE");
                  break;
            }
      case ID_OBJ:
            {
                  fprintf(log_ptr, "ID_OBJ");
                  break;
            }
      case ID_TYPE:
            {
                  fprintf(log_ptr, "ID_TYPE");
                  break;
            }
      case EOFILE:
            {
                  fprintf(log_ptr, "EOFILE");
                  break;
            }
      default:
            {
                  fprintf(log_ptr, "DEFAULT CASE");
                  break;
            }
      }
      
      if (tok_type == EOFILE)
      {
            fprintf(log_ptr, " TOK_TEXT: $\n");
      }
      
      if (tok_type != NEW_LINE)
      {
            fprintf(log_ptr, " TOK_TEXT: %s\n", tok_text);
      }
      else
      {
            fprintf(log_ptr, " TOK_TEXT: \\n\n");
      }
}

void close_files(FILE* source_ptr, FILE* log_ptr)
{
      if (fclose(source_ptr) != 0)
      {
            printf("ERROR: enable to close the source file\n");
            fprintf(log_ptr, "ERROR: enable to open source file\n");
      }

      if (fclose(log_ptr) != 0)
      {
            printf("ERROR: enable to close the log file\n");
      }

      source_ptr = nullptr;
      log_ptr    = nullptr;
}

int main()
{           
      time_t t;   // for the current time
      time(&t);   // for the current time

      size_t tok = 0;

      log_ptr    = fopen("log.txt", "w"); // opens the log file
      FILE* source_ptr = open_source("source.txt", log_ptr); // opens the source file
      
      yyin = source_ptr;

      yylex();

      print_summary(log_ptr, &t); 

      close_files(source_ptr, log_ptr); // closes the files 

      return 0;
}
