#define ENABLE_LOGGING 
#include "logger.h"

int main() {
    // Debug log example
    LOG(LOG_DEBUG, PROCESS_SCHEDULING, "Process scheduling operation started");

    // Information log example
    LOG(LOG_INFO, MEMORY_MANAGEMENT, "Memory allocation successful");

    // Warning log example
    LOG(LOG_WARN, MEMORY_MANAGEMENT, "Memory usage is high");

    // Error log example
    LOG(LOG_ERROR, I_O_OPERATIONS, "Error encountered during I/O operation");

    return 0;
}
