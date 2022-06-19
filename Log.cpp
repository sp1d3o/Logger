#include "Log.h"


/*Logger::Logger(const Logger &logger)
{
    m_message = logger.m_message;
    //creating ofstream copy
    f_stream.copyfmt(logger.f_stream);
    f_stream.clear(logger.f_stream.rdstate());
    f_stream.basic_ios<char>::rdbuf(logger.f_stream.rdbuf());
}
*/

Logger &operator<<(Logger &logger, const char *message)
{
    logger.f_stream << message << "Log message text";
    return logger;
}

bool Logger::FileExist(const std::filesystem::path &p, std::filesystem::file_status s = std::filesystem::file_status{})
{
    std::cout << p;
    if(std::filesystem::status_known(s) ? std::filesystem::exists(s) : std::filesystem::exists(p)) {
        return true;
    }
    else {
        return false;
    }
}
std::fstream & Logger ::CreateFile(const std::string & name)
{
    std::fstream Log_file;
    Log_file.open("Logs.txt", std::ios::out);

    if(!Log_file) {
        std::cout << "Cannot create file" <<std::endl;
        Log_file.close();
    }

    else {
        return Log_file;
    }
}