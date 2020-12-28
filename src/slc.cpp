#include <log/Logger.hpp>
#include <core/Stopwatch.hpp>
#include <parallel/ParallelMath.hpp>

using namespace slc;

int main() {
    Logger log;
    Stopwatch watch;

    log.params.colorful = false;
    IniConfiguration config;
    config.loadFile(EString::format("E:/slc/app.ini"));
    EString file = EString::fromStdString(config.readString("app","wspace")).concatWith("/").concatWith(config.readString("app","file"));

    ParallelMath pm;
    pm.setLogger(log);
    pm.setConfigure(config);

    int a[10]{42352441,5425364,9142356,1465243,454562436,342453621,462434,543524641,2546423,14524632};
    int b[10]{424653,424653,46565,41536,454236,458345,848923,892443,46423,442653};

    int* c;
    watch.start();
    c = pm.add(a,b,10);


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