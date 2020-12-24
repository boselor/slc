#include <log/Logger.hpp>
using namespace slc;
int main()
{
    Logger log;
    log.params.colorful = false;
    log.params.folder = "";
    log.Info("Show...");
    return 0;
}