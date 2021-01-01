//
// Created by xiaoyong on 2021/1/1.
//

#include <cv/common/MatrixOperator.h>

namespace slc{
    MatrixOperator::MatrixOperator() {}
    MatrixOperator::~MatrixOperator() {}

    MatrixOperator MatrixOperator::load(cv::Mat matrix) {
        this->entity = matrix;
        return *this;
    }
    MatrixOperator MatrixOperator::show(EString title, int waitKey, int width, int height, bool openGL) {
//        if(openGL)
//            cv::namedWindow(title.toStdString(),cv::WindowFlags::WINDOW_OPENGL);
//        else {
//            if(width == -1 || height == -1)
//                cv::namedWindow(title.toStdString());
//            else
//                cv::namedWindow(title.toStdString(),cv::WindowFlags::WINDOW_AUTOSIZE);
//        }

        cv::namedWindow(title.toStdString(),cv::WindowFlags::WINDOW_NORMAL);
        cv::resizeWindow(title.toStdString(), width <= 0? this->entity.cols: width, height <= 0 ?this->entity.rows: height);

        cv::moveWindow(title.toStdString(), 100, 0);
        cv::imshow(title.toStdString(),this->entity);
        cv::waitKey(waitKey);
        return *this;
    }
}