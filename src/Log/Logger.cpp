/**
* 作者   : 牧轩居士
* 时间   : 2020-12-24 20:52:09
* 文件名 : Logger.cpp
* 描述   : 日志系统的实现
**/
#include <log/Logger.hpp>
namespace slc
{
    Logger::Logger(/* args */) {}
    Logger::~Logger() {}
    Logger Logger::*getInstance() { return nullptr; }
    void Logger::Info(EString info, ...)
    {
        std::cout << info.toStdString() << std::endl;
    }
    void Logger::Warn(EString info, ...)
    {
        std::cout << info.toStdString() << std::endl;
    }
    void Logger::Error(EString info, ...)
    {
        std::cout << info.toStdString() << std::endl;
    }
} // namespace slc
