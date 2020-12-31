/**
* 作者   : 牧轩居士
* 时间   : 2020-12-24 20:52:09
* 文件名 : File.cpp
* 描述   : 日志系统的实现
**/
#include <log/File.hpp>

namespace slc {
    File::File(/* args */) {}

    File::~File() {}

    File& File::getInstance() { return *this; }

    void File::Info(EString info) {
        write(EString::format("[I]:%s",info.toStdString().c_str()));
    }

    void File::Warn(EString info) {
        write(EString::format("[W]:%s",info.toStdString().c_str()));
    }

    void File::Error(EString info) {
        write(EString::format("[E]:%s",info.toStdString().c_str()));
    }

    void File::write(EString val) {
        std::cout << val.toStdString() << std::endl;
    }
} // namespace slc
