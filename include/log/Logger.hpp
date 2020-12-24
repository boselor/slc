/**
* 作者   : 牧轩居士
* 时间   : 2020-12-24 20:10:12
* 文件名 : Logger.hpp
* 描述   : 这是一个日志系统组件，用来处理系统日志
**/

#ifndef SLC_LOGGER
#define SLC_LOGGER
#include <defination.hpp>
#include <core/EString.hpp>
namespace slc
{
    class Logger
    {
    private:
        int MAX_SIZE = 1024;

    public:
        Logger(/* args */);
        ~Logger();
        Logger* getInstance();
        struct Params
        {
            EString folder = "";
            bool colorful = false;
        } params;
        void Info(EString info,...);
        void Warn(EString info,...);
        void Error(EString info,...);
    };
} // namespace slc
#endif