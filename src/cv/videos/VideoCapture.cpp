#include <cv/videos/VideoCapture.hpp>

namespace slc{
    VideoCapture::VideoCapture(/* args */)
    {
    }
    
    VideoCapture::~VideoCapture()
    {
    }
    void VideoCapture::setConfigure(IniConfiguration config) {
        this->configuration = config;
    }
    void VideoCapture::open(EString val) {
        if(val.isEmpty()){
            exit(SLC_EXIT_IO);
        }

        bool open = this->capture.open(val.toStdString().c_str());
        if(!open){
            this->logger.Error(EString::format("Cannot open the file: %s ", val.toStdString().c_str()));
            exit(EXIT_FAILURE);
        }

        this->logger.Info(EString::format("Open file %s success!",val.toStdString().c_str()));
    }
    bool VideoCapture::isOpen() { return this->capture.isOpened();}

    void VideoCapture::setLogger(Logger &log) {
        this->logger = log;
    }

    void VideoCapture::dispose() {
        this->capture.release();
        logger.Info(EString::format("Instance has been disposed!"));
    }
}