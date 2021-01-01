#include <core/EString.hpp>
#include <core/IniConfigure.hpp>
#include <io/Directory.hpp>
#include <cv/videos/VideoCapture.hpp>

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

    cv::Mat mat;
    capture >> mat;

    MatrixOperator opt;
    opt.load(mat);
    opt.show(EString::format("show"), 0 , 800, 800);

    capture.dispose();
    log.Info(EString::format("Works done."));
    return 0;
}