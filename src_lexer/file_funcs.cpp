#include "file_funcs.hpp"

/*################################################################################################################*/


/*
* This function opens the file with 
* the given name (file_name)
*/
FILE* open_file(const char* const file_name, FILE* const log_ptr) // OK
{
      static bool log_file_opnd = false;
      static bool output_opnd = false;
      FILE* file_ptr = nullptr;

      if (log_ptr == nullptr && log_file_opnd == false) // for the log file
      {
            file_ptr = fopen(file_name, "w");
            log_file_opnd = true;

            if (file_ptr == nullptr)
            {
                  printf("================ERROR================\n");
                  printf("ERROR(in open_file()): unable to open file.\n");
                  printf("================ERROR================\n\n");
            }
      }
      else if (log_file_opnd == true)
      {
            if (output_opnd == false)
            {
                  file_ptr = fopen(file_name, "w");
                  output_opnd = true;
            }
            else 
            {
                  file_ptr = fopen(file_name, "r");
            }

            if (log_ptr == nullptr)
            {
                  printf("================ERROR================\n");
                  printf("ERROR(in open_file()): The log file wasn't opened yet.\n");
                  printf("================ERROR================\n\n");

                  if (file_ptr == nullptr)
                  {
                        printf("================ERROR================\n");
                        printf("ERROR(in open_file()): unable to open file.\n");
                        printf("================ERROR================\n\n");
                  }
            }
            else 
            {
                  if (file_ptr == nullptr)
                  {
                        fprintf(log_ptr,"================ERROR================\n");
                        fprintf(log_ptr,"ERROR(in open_file()): unable to open file.\n");
                        fprintf(log_ptr,"================ERROR================\n\n");
                  }
            }
      }

      return file_ptr;
}

/*
* This function closes the opened
* file using pointer (file_ptr) 
*/
void close_file(FILE* file_ptr, FILE* log_ptr) // OK
{
      if (file_ptr == log_ptr) // if we are closing log_file
      {
            if (fclose(log_ptr) != 0)
            {
                  printf("ERROR(in close_file()): unable to close the log file.\n");
            }
            else 
            {
                 file_ptr = nullptr; 
            }

            return;
      }

      if (log_ptr != nullptr) // if we are closing another file 
      {
            if (fclose(file_ptr) != 0)
            {
                  printf("ERROR(in close_file()): unable to close the file.\n");
                  fprintf(log_ptr, "ERROR(in close_file()): unable to close the file.\n");
            }
            else 
            {
                 file_ptr = nullptr; 
            }
      }
      else 
      {
            if (fclose(file_ptr) != 0)
            {
                  printf("ERROR(in close_file()): unable to close the file.\n");
            }
            else 
            {
                 file_ptr = nullptr; 
            }
      }
}
