#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kernel_log(int level, int eventType, const char* message, 
                const char* file, int line) {
  FILE *log_file = fopen("txt.log_kernel", "a");  
    if (log_file != NULL) {
        fprintf(log_file, "[%s] [%s] %s at %s:%d\n", get_log_level_name(log_level), get_event_type_name(event_type), message, file_name, line);
        fclose(log_file);  
    } else {
        fprintf(stderr, "Error opening or creating txt.log_kernel file.\n");
    }
}
const char* get_log_level_name(int level) {
    switch (log_level) {
        case DEBUG_LOG:
            return "DEBUG";
        case INFO_LOG:
            return "INFO";
        case WARNING_LOG:
            return "WARNING";
        case ERROR_LOG:
            return "ERROR";
        default:
            return "UNKNOWN_LOG";
    }
}
const char* get_event_type_name(int eventType) {
    switch (event_type) {
        case SCHEDULING_PROCESS:
            return "SCHEDULING_PROCESS";
        case MEMORY_MANAGEMENT:
            return "MEMORY_MANAGEMENT";
        case IO_EVENT:
            return "IO_EVENT";
        default:
            return "UNKNOWN_EVENT";
    }
}
