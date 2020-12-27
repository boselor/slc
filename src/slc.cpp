#include <log/Logger.hpp>
#include <core/Stopwatch.hpp>
#include <core/Platform.hpp>

using namespace slc;

int main() {
    Logger log;
    Stopwatch watch;
    watch.start();
    log.params.colorful = false;
    log.Info(EString::format("Hello, I am %s and my age is %d. I am in %s!", "Zhang san", 18, "Caijin"));
    watch.stop();
    EString(EString::format("time cost %d ", watch.timeSpan())).print();

    Platform plt;
    plt.Name.print();

    if(Platform::IsWindows())
        std::cout<<"Windows"<<std::endl;
    if(Platform::IsLinux())
        std::cout<<"Linux"<<std::endl;

    return 0;
}