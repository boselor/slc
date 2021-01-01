#include <core/EString.hpp>
#include <core/EConfigure.hpp>
#include <io/Directory.hpp>

using namespace slc;
int main(){

    Logger log;
    log.Info(EString::format("Works start..."));
    EConfigure config;
    config.loadFile(EString::format("../app.ini"));

//    auto file = EString::format("E:/slc/app.ini");
//    if(Directory(File(file).getParent()).exist())
//        EString::format("ok").print();

    if(Directory(EString::format("E:/slc/x/d/e/q/w/ds/")).mk_dirs())
        log.Info(EString::format("create folder done!"));

    log.Info(EString::format("Works done."));
    return 0;
}