#include "Log.h"

Logger * Logger::GetInstance(const std::string &value)
{
    if(p_logger == nullptr) {
        p_logger = new Logger(value);
    }

    return p_logger;
}