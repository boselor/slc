#include <log/Logger.hpp>
using namespace slc;
int main()
{
    Logger log;
    log.params.colorful = false;
    log.params.folder = EString::fromStdString("测试！");
    log.Info(slc::EString::fromStdString("Show..."));
    log.Info(EString::format("Hello, I am %s and my age is %d. I am in %s!","Zhang san",18,"Caijin"));
    return 0;
}