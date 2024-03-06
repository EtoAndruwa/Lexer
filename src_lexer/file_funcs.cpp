#include "file_funcs.hpp"

/*################################################################################################################*/

FILE* open_source(const char* const source_name, FILE* const log_ptr)
{
      FILE* source_ptr = fopen(source_name, "r");

      if (source_ptr == nullptr)
      {
            fprintf(log_ptr, "ERROR: enable to open source file\n");
      }

      return source_ptr;
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
