#include "print_funcs.hpp"

/*################################################################################################################*/

void print_summary(FILE* const log_ptr)
{
      time_t time_str;   // for the current time
      time(&time_str);   // for the current time

      fprintf(log_ptr, "\n============SUMMARY============\n");
      fprintf(log_ptr, "Updated: %s", ctime(&time_str));
      fprintf(log_ptr, "Total number of token: %ld\n", total_tok_num);
      fprintf(log_ptr, "Total number of lines: %ld\n", line_num);
      fprintf(log_ptr, "============SUMMARY============\n");
}

void print_tok_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const total_tok_num, size_t const line_num, FILE* const log_ptr)
{
      fprintf(log_ptr, "(LINE: %ld, NUM_IN_LINE: %ld, NUM_IN_FILE: %ld) TOK_TYPE: ", line_num, cur_tok_num, total_tok_num);
      
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
      else if (tok_type != NEW_LINE && tok_type != EOFILE)
      {
            fprintf(log_ptr, " TOK_TEXT: %s\n", tok_text);
      }
      else
      {
            fprintf(log_ptr, " TOK_TEXT: \\n\n");
      }
}
