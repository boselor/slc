#include <cv/videos/VideoCapture.hpp>
#include <io/Directory.hpp>
#include <io/File.hpp>

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
        if(val.isEmpty() || !File(val).isExist()){
            this->logger.Error(EString::format("Cannot open the file: %s , because it is an empty inputs or the file may not exist!", val.toStdString().c_str()));
            return;
        }

        bool open = this->capture.open(val.toStdString().c_str());
        if(!open){
            this->logger.Error(EString::format("Cannot open the file: %s ", val.toStdString().c_str()));
            return;
        }

        this->logger.Info(EString::format("Open file %s success!",val.toStdString().c_str()));
    }
    bool VideoCapture::tryOpen(EString val) {
        this->open(val);
        return this->isOpen();
    }
    bool VideoCapture::isOpen() { return this->capture.isOpened();}

    void VideoCapture::setLogger(Logger &log) {
        this->logger = log;
    }
    cv::Mat & VideoCapture::operator>>(cv::Mat &res) {
        this->capture >> res;
        return res;
    }

    void VideoCapture::dispose() {
        this->capture.release();
        logger.Info(EString::format("Videocapture instance has been disposed!"));
    }
}