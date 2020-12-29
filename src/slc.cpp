#include <core/Stopwatch.hpp>
#include <core/EString.hpp>
#include <core/IniConfigure.hpp>
#include <log/Logger.hpp>

using namespace slc;
int main(){

    Logger log;
    log.Info(EString::format("Works start..."));
    IniConfiguration config;
    config.loadFile(EString::format("../app.ini"));
    EString::format("%s",config.readString("app","wspace","").c_str()).print();

    log.Info(EString::format("Works done."));
    return 0;
}