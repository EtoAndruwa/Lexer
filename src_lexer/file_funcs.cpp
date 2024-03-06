#include "file_funcs.hpp"

/*################################################################################################################*/

FILE* open_file(const char* const file_name, FILE* const log_ptr)
{
      FILE* file_ptr = fopen(file_name, "r");

      if (log_ptr != nullptr)
      {
            if (file_ptr == nullptr)
            {
                  printf("================ERROR================\n");
                  fprintf(log_ptr, "ERROR: enable to open file\n");
                  printf("================ERROR================\n");
            }
      }
      else 
      {
            printf("================WARNING================\n");
            printf("The log file wasn't opened yet.");
            printf("================WARNING================\n");

            if (file_ptr == nullptr)
            {
                  printf("================ERROR================\n");
                  printf("ERROR: enable to open file\n");
                  printf("================ERROR================\n");
            }
      }

      return file_ptr;
}

void close_file(FILE* file_ptr, FILE* log_ptr)
{
      if (fclose(file_ptr) != 0)
      {
            printf("ERROR: enable to close the file\n");
            fprintf(log_ptr, "ERROR: enable to open source file\n");
      }

      if (fclose(log_ptr) != 0)
      {
            printf("ERROR: enable to close the log file\n");
      }

      source_ptr = nullptr;
      log_ptr    = nullptr;
}
