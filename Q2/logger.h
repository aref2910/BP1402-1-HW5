#ifndef LOGGER_H
#define LOGGER_H

// Log levels
#define LOG_DEBUG   0
#define LOG_INFO    1
#define LOG_WARN    2
#define LOG_ERROR   3

// Event types
#define PROCESS_SCHEDULING 0
#define MEMORY_MANAGEMENT  1
#define I_O_OPERATIONS     2

// Conditional logging
#ifdef ENABLE_LOGGING
#define LOG(level, eventType, message) kernel_log(level, eventType, message, __FILE__, __LINE__)
#else
#define LOG(level, eventType, message) 
#endif

void kernel_log(int level, int eventType, const char* message, const char* file, int line);

const char* get_log_level_name(int level);
const char* get_event_type_name(int eventType);

#endif
