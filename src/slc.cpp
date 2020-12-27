#include <log/Logger.hpp>
#include <core/Stopwatch.hpp>
#include <configure/IniConfigure.hpp>
#include <cv/videos/VideoCapture.hpp>
#include <cv/videos/VideoCapture.hpp>

using namespace slc;

int main() {
    Logger log;
    Stopwatch watch;
    watch.start();
    log.params.colorful = false;
    IniConfiguration config;
    config.loadFile(EString::format("E:/slc/app.ini"));
    EString file = EString::fromStdString(config.readString("app","wspace")).concatWith("/").concatWith(config.readString("app","file"));

    EString::format("ADJpsdjSDSjkdSJIPOsadkpJOIDsdjoi").toUpper().print();

//    VideoCapture capture;
//    capture.setConfigure(config);
//    capture.setLogger(log);
//    capture.open(file);
//
//    if(capture.isOpen())
//        log.Info("capture is opened!");
//    else
//        log.Info("capture is not opened!");

    // capture.dispose();

    watch.stop();
    EString(EString::format("time cost %d ", watch.timeSpan())).print();
    return 0;
}