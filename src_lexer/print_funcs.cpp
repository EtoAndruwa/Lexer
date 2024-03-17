#include "print_funcs.hpp"

/*################################################################################################################*/

/*
* This function prints the summary of 
* lexical analysis of the source file
*/
void print_summary(FILE* const output_ptr) // OK
{
      time_t time_val;   // variable to store the current time
      int time_ret = time(&time_val);   // gets the current time

      fprintf(output_ptr, "\n============SUMMARY============\n");
      if (time_ret == -1)
      {
            fprintf(output_ptr, "Updated: ERR_TO_GET_TIME\n");
      }
      else 
      {
            fprintf(output_ptr, "Updated: %s", ctime(&time_val));
      }

      fprintf(output_ptr, "Total number of token: %ld\n", total_tok_num);
      fprintf(output_ptr, "Total number of lines: %ld\n", line_num);
      fprintf(output_ptr, "============SUMMARY============\n\n");
}

/*
* This function prints the 
* tokens' data to the outputf ile
*/
void print_tok_data(size_t const tok_type, const char* const tok_text, size_t const cur_tok_num, size_t const total_tok_num, 
      size_t const line_num, FILE* const output_ptr) // OK
{
      fprintf(output_ptr, "(LINE: %-3ld, NUM_IN_LINE: %-3ld, NUM_IN_FILE: %-3ld) TOK_TYPE: ", line_num, cur_tok_num, total_tok_num);
      
      switch (tok_type)
      {
      case ARITH_OP:
                  fprintf(output_ptr, "%-13s", "ARITH_OP");
                  break;
      case ASSIGN_OP:
                  fprintf(output_ptr, "%-13s","ASSIGN_OP");
                  break;
      case OP_BRACE:
                  fprintf(output_ptr, "%-13s","OP_BRACE");
                  break;
      case CL_BRACE:
                  fprintf(output_ptr, "%-13s","CL_BRACE");
                  break;
      case INT_NUMBER:
                  fprintf(output_ptr, "%-13s","INT_NUMBER");
                  break;
      case DIGIT:
                  fprintf(output_ptr, "%-13s","DIGIT");
                  break;
      case NEW_LINE:
                  fprintf(output_ptr, "%-13s","NEW_LINE");
                  break;
      case ID_OBJ:
                  fprintf(output_ptr, "%-13s","ID_OBJ");
                  break;
      case ID_TYPE:
                  fprintf(output_ptr, "%-13s","ID_TYPE");
                  break;
      case FLOAT_NUMBER:
                  fprintf(output_ptr, "%-13s","FLOAT_NUMBER");
                  break;
      case EOFILE:
                  fprintf(output_ptr, "%-13s","EOFILE");
                  break;
      case OTHER:
                  fprintf(output_ptr, "%-13s","ERROR_TOKEN");
                  break;
      default:
                  fprintf(output_ptr, "NEW TOKEN TOK_TEXT: %-13s <---------- NEW TOKEN\n", tok_text);
                  
                  return;
      }
      
      if (tok_type == EOFILE)
      {
            fprintf(output_ptr, " TOK_TEXT: $\n");
      }
      else if (tok_type != NEW_LINE && tok_type != EOFILE)
      {
            if (tok_type == OTHER)
            {
                  fprintf(output_ptr, " TOK_TEXT: %-10s <---------- ERROR TOKEN\n", tok_text);
            }
            else 
            {
                  fprintf(output_ptr, " TOK_TEXT: %-10s\n", tok_text);
            }
      }
      else
      {
            fprintf(output_ptr, " TOK_TEXT: \\n\n");
      }
}
