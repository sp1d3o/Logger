#ifndef LOGGER_LOG_H
#define LOGGER_LOG_H

//standard headers
#include <iostream>
#include <fstream>
#include <filesystem>

//custom headers
#include "Error.h"

class Logger {
private:
    const char *m_message;
    std::ofstream f_stream;

protected:
    Logger() = default;

public:
    //Handling deleted functions + destructor
    Logger(const Logger &) = delete;
    Logger(const Logger &&) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger &operator=(const Logger&&) = delete;
    ~Logger() = default;
    //function to create singleton
    static Logger & get_object()
    {
        static Logger logger;
        return logger;
    }

    friend Logger &operator<<(Logger & logger , const char *message);
    bool FileExist(const std::filesystem::path &p, std::filesystem::file_status s = std::filesystem::file_status{});
    std::fstream &CreateFile(const std::string & name);

};

Logger & logger = Logger::get_object();

#endif //LOGGER_LOG_H