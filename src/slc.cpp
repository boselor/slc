#include <core/Stopwatch.hpp>
#include <core/EString.hpp>
#include <core/EConfigure.hpp>
#include <log/Logger.hpp>

using namespace slc;
int main(){

    Logger log;
    log.Info(EString::format("Works start..."));
    EConfigure config;
    config.loadFile(EString::format("../app.ini"));
    EString::format("%s",config.readString(EString::format("")).toStdChars()).print();

    log.Info(EString::format("Works done."));
    return 0;
}