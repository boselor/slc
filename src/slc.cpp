#include <core/EString.hpp>
#include <core/IniConfigure.hpp>
#include <io/Directory.hpp>
#include <cv/videos/VideoCapture.hpp>
#include <cv/EMat.hpp>

using namespace slc;
int main(){

    Logger log;
    log.Info(EString::format("Works start..."));
    IniConfiguration config;
    config.loadFile(EString::format("../data/app.ini"));

    VideoCapture capture;
    capture.setLogger(log);
    capture.setConfigure(config);

    if(!capture.tryOpen(EString::format("%s/%s"
            ,config.readString("app","wspace","").c_str()
            ,config.readString("app","file","").c_str()))){
        log.Error(EString::format("Cannot open the file!"));
        exit(SLC_EXIT_IO);
    }
    log.Info(EString::format("open video success!"));

    EMat opt;
    capture >> opt;
    auto am = opt.clone();
    log.Info(EString::format("width = %d, height = %d",am.cols,am.rows));
    // opt.details().show(EString::format("show"));

    std::cout<< opt.at<int>(100,100)<<std::endl;

    opt.dispose();

    capture.dispose();
    log.Info(EString::format("Works done."));
    return 0;
}