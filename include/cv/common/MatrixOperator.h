//
// Created by xiaoyong on 2021/1/1.
//

#ifndef SLC_MATRIXOPERATOR_H
#define SLC_MATRIXOPERATOR_H
#include <opencv2/opencv.hpp>
#include <core/EString.hpp>

namespace slc{
    class MatrixOperator{
    private:
        cv::Mat entity;
    public:
        MatrixOperator();
        ~MatrixOperator();

        MatrixOperator load(cv::Mat matrix);
        MatrixOperator show(EString title = EString::format("show"), int waitKey = 0, int width = -1, int height = -1, bool openGL = true);
    };
}
#endif //SLC_MATRIXOPERATOR_H
