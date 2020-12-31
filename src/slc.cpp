#include <core/Stopwatch.hpp>
#include <core/EString.hpp>
#include <core/EConfigure.hpp>
#include <log/Logger.hpp>
#include <io/File.hpp>
#include <dao/SQLAdapter.hpp>

using namespace slc;
int main(){

    Logger log;
    log.Info(EString::format("Works start..."));
    EConfigure config;
    config.loadFile(EString::format("../app.ini"));

    auto file = EString::format("E:/slc/app.ini");
    SQLAdapter adapter;
    adapter.connect(file);


    log.Info(EString::format("Works done."));
    return 0;
}