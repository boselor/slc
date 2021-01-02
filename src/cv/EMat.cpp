//
// Created by Xiaoyong on 2021/1/2.
//

#include <cv/EMat.hpp>

namespace slc{
    EMat::EMat() {}
    EMat::~EMat() {}
    EMat::EMat(cv::Mat& val) {
        this->_mat = val;
        std::cout<<"flag"<<std::endl;
    }
    EMat EMat::clone() {
        auto m = this->_mat.clone();
        return EMat(m);
    }
    EMat EMat::load(cv::Mat &val) {
        this->_mat = val;
        std::cout<<this->_mat.size<<std::endl;
    }
    EMat EMat::show(EString title, int waitKey, cv::Size size, bool opengl) {
        std::cout<<"flag"<<std::endl;
//        if(opengl)
//            cv::namedWindow(title.toStdChars(),cv::WindowFlags::WINDOW_OPENGL);
//        else
//            cv::namedWindow(title.toStdChars(),cv::WindowFlags::WINDOW_NORMAL);

//        cv::moveWindow(title.toStdChars(),100,0);
//        if(size.width > 0 && size.height > 0)
//            cv::resizeWindow(title.toStdChars(),size);
//        else
//            cv::resizeWindow(title.toStdChars(),cv::Size(this->_mat.cols,this->_mat.rows));
//        cv::imshow(title.toStdChars(),this->_mat);
//        std::cout<<"flag"<<std::endl;
//        cv::waitKey(waitKey);
        return *this;
    }
    void EMat::dispose() {
        this->_mat.release();
    }
}