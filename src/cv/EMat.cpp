//
// Created by Xiaoyong on 2021/1/2.
//

#include <cv/EMat.hpp>

namespace slc{
    EMat::EMat() {}
    EMat::~EMat() {}
    EMat::EMat(cv::Mat& val) {
        this->_mat = val;
    }
    EMat EMat::clone() {
        auto m = this->_mat.clone();
        return EMat(m);
    }
    EMat EMat::load(cv::Mat &val) {
        this->_mat = val;
        return *this;
    }
    EMat EMat::show(EString title, int waitKey, cv::Size size, bool opengl) {
        if(opengl)
            cv::namedWindow(title.toStdChars(),cv::WindowFlags::WINDOW_OPENGL);
        else
            cv::namedWindow(title.toStdChars(),cv::WindowFlags::WINDOW_NORMAL);

        cv::moveWindow(title.toStdChars(),100,0);
        if(size.width > 0 && size.height > 0)
            cv::resizeWindow(title.toStdChars(),size);
        else
            cv::resizeWindow(title.toStdChars(),cv::Size(this->_mat.cols / 2,this->_mat.rows / 2));
        cv::imshow(title.toStdChars(),this->_mat);
        cv::waitKey(waitKey);
        return *this;
    }

    EMat EMat::details() {
        std::cout<<"------------------------------"<<std::endl;
        std::cout << "type = " << this->_mat.type() << std::endl;
        std::cout << "size = " << this->_mat.size << std::endl;
        double maxVal = 0.0, minVal = 0.0;
        int    minIdx[2] = {}, maxIdx[2] = {};	// minnimum Index, maximum Index
        cv::Mat tmp;
        cv::cvtColor(this->_mat,tmp,cv::COLOR_BGR2GRAY);
        minMaxIdx(tmp, &minVal, &maxVal, minIdx, maxIdx);
        std::cout << "mine value : [ " << minIdx[0] <<" , " << minIdx[1]  << " , " << minVal <<" ]" <<std::endl;
        std::cout << "max  value : [ " << maxIdx[0] <<" , " << maxIdx[1] << " , " << maxVal <<" ]" <<std::endl;
        std::cout << "" <<std::endl;

        std::cout<<"------------------------------"<<std::endl;
        return *this;
    }

    void EMat::dispose() {
        this->_mat.release();
    }
}