#ifndef LOGGER_LOG_H
#define LOGGER_LOG_H

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>
#include <mutex>

/*
std::string get_current_dir()
{
    char buffer[FILENAME_MAX];
    GetCurrentDir(buffer, FILENAME_MAX);
    std::string current_working_dir(buffer);
    return current_working_dir;
}
*/

 class Logger {
 protected:
    Logger(const std::string value) : p_value(value) {}
    static Logger * p_logger;
    std::string p_value;
public:
    Logger(const Logger &) = delete;
    void operator=(const Logger &) = delete;

    static Logger * GetInstance(const std::string & value);
    std::string value() const {
        return p_value;
    }
};

Logger * Logger::p_logger = nullptr;



#endif //LOGGER_LOG_H
