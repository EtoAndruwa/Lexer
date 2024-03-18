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
      fprintf(output_ptr, "Total number of error tokens: %ld\n", total_err_tok_num);
      fprintf(output_ptr, "============SUMMARY============\n\n");
}

/*
* This function prints the 
* tokens' data to the output file
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
                  fprintf(output_ptr, "%-13s", "ASSIGN_OP");
                  break;
      case OP_BRACE:
                  fprintf(output_ptr, "%-13s", "OP_BRACE");
                  break;
      case CL_BRACE:
                  fprintf(output_ptr, "%-13s", "CL_BRACE");
                  break;
      case INT_NUMBER:
                  fprintf(output_ptr, "%-13s", "INT_NUMBER");
                  break;
      case DIGIT:
                  fprintf(output_ptr, "%-13s", "DIGIT");
                  break;
      case ID_OBJ:
                  fprintf(output_ptr, "%-13s", "ID_OBJ");
                  break;
      case ID_TYPE:
                  fprintf(output_ptr, "%-13s", "ID_TYPE");
                  break;
      case FLOAT_NUMBER:
                  fprintf(output_ptr, "%-13s", "FLOAT_NUMBER");
                  break;
      case EOFILE:
                  fprintf(output_ptr, "%-13s", "EOFILE");
                  break;
      case KEYWORD:
                  fprintf(output_ptr, "%-13s", "KEYWORD");
                  break;
      case STRING:
                  fprintf(output_ptr, "%-13s", "STRING");
                  break;
      case COMMENT:
                  fprintf(output_ptr, "%-13s", "COMMENT");
                  break;
      case LOG_OP:
                  fprintf(output_ptr, "%-13s", "LOG_OP");
                  break;
      default:
                  fprintf(output_ptr, "%-13s", " ");
                  break;
      }
      
      if (tok_type == EOFILE)
      {
            fprintf(output_ptr, " TOK_TEXT: $\n");
      }
      else if (tok_type != EOFILE)
      {
            if (tok_type == OTHER)
            {
                  fprintf(output_ptr, " TOK_TEXT: %-10s <---------- ERROR TOKEN\n", tok_text);
            }
            else 
            {     
                  if (tok_type == COMMENT)
                  {     
                        size_t str_len = strlen(tok_text);
                        
                        if (tok_text[str_len - 1] == '\n')
                        {
                              fprintf(output_ptr, " TOK_TEXT: %-10s", tok_text);
                        }
                        else 
                        {
                              fprintf(output_ptr, " TOK_TEXT: %-10s\n", tok_text);
                        }
                  }
                  else 
                  {
                        fprintf(output_ptr, " TOK_TEXT: %-10s\n", tok_text);
                  }
            }
      }
}

/* 
* This function prints the error messages to the log file 
*/
void print_err_to_log(int const err_code, size_t last_err_tok_num, FILE* const log_ptr)
{
      if (log_ptr == nullptr)
      {
            printf("================ERROR================\n");
            printf("Cannot output the error message (%d) to the log file.\n", err_code);
            printf("================ERROR================\n\n");
      }
      else 
      {       
            if (err_code == OK)
            {
                  fprintf(log_ptr,"No errors occured during lexical analysis\n");
            }
            else 
            {
                  fprintf(log_ptr,"================ERROR================\n");

                  switch (err_code)
                  {     
                  case ERR_BRACKETS_MATCH:
                        fprintf(log_ptr,"ERR_BRACKETS_MATCH(%d): something with bracket's sequence\n", err_code);
                        break;
                  case ERR_INV_STRING:
                        fprintf(log_ptr,"ERR_INV_STRING(%d): invalid string. NUM_IN_FILE: %d\n", err_code, last_err_tok_num);
                        break;
                  case ERR_INV_FLOAT:
                        fprintf(log_ptr,"ERR_INV_FLOAT(%d): invalid float. NUM_IN_FILE: %d\n", err_code, last_err_tok_num);
                        break;
                  case ERR_UNKNOWN_TOK:
                        fprintf(log_ptr,"ERR_UNKNOWN(%d): invalid token. NUM_IN_FILE: %d\n", err_code, last_err_tok_num);
                        break;
                  case ERR_NO_OPEN_BRC:
                        fprintf(log_ptr,"ERR_NO_OPEN_BRC(%d): no opened bracket before closing one. NUM_IN_FILE: %d\n", err_code, last_err_tok_num);
                        break;
                  default:
                        fprintf(log_ptr,"NEW ERROR CODE\n");
                        break;
                  }
                  
                  fprintf(log_ptr,"================ERROR================\n\n");
            }
      }
}
