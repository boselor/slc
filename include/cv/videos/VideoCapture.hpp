/**
* 作者   : 牧轩居士
* 时间   : 2020-12-26 22:25:42
* 文件名 : VideoCapture.hpp
* 描述   : 视频处理帮助类，用于视频的相关操作
**/
#ifndef SLC_CV_VIDEOCAPTURE
#define SLC_CV_VIDEOCAPTURE
#include <core/EString.hpp>
#include <opencv2/opencv.hpp>
#include <log/Logger.hpp>
#include <core/IniConfigure.hpp>
#include <cv/common/MatrixOperator.h>

namespace slc
{
    class VideoCapture
    {
    private:
        cv::VideoCapture capture;
        Logger logger;
        IniConfiguration configuration;

    public:
        VideoCapture(/* args */);
        ~VideoCapture();
        static VideoCapture fromString(EString val);
        void open(EString val = EString::empty());
        bool tryOpen(EString val = EString::empty());
        void dispose();

        bool isOpen();
        VideoCapture clone();
        void setLogger(Logger &log);
        void setConfigure(IniConfiguration config);

        cv::Mat& operator >> (cv::Mat& res);
    };
} // namespace slc
#endif
