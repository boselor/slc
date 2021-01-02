//
// Created by Xiaoyong on 2021/1/2.
//
#include <opencv2/opencv.hpp>
#include <core/EString.hpp>
#ifndef SLC_EMAT_H
#define SLC_EMAT_H
namespace slc{
    class EMat{
    private:
        cv::Mat _mat;
    public:
        EMat();
        ~EMat();
        EMat load(cv::Mat& val);
        EMat(cv::Mat& val);
        EMat clone();
        EMat show(EString title, int waitKey = 0, cv::Size size = cv::Size(-1,-1), bool opengl = false);
        EMat details();

        void dispose();
    };
}
#endif //SLC_EMAT_H
