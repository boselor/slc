#include <log/Logger.hpp>
#include <compression/Compression.hpp>
#include <chrono>
#include <core/Stopwatch.hpp>

using namespace slc;

int main() {
    Logger log;
    Stopwatch watch;
    watch.start();
    log.params.colorful = false;
    log.Info(EString::format("Hello, I am %s and my age is %d. I am in %s!", "Zhang san", 18, "Caijin"));
    watch.stop();

    return 0;
}