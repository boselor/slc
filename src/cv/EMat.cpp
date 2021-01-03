//
// Created by Xiaoyong on 2021/1/2.
//

#include <cv/EMat.hpp>

namespace slc {
    EMat::EMat() {}

    EMat::~EMat() {}

    void EMat::bind(std::vector<cv::Mat> list) {
        this->_list = list;
        this->type = list[0].type();
        this->rows = list[0].rows;
        this->cols = list[0].cols;
    }

    EMat::EMat(std::vector<cv::Mat> val) {
        if(val.size() <= 0)
        {
            return;
        }
        auto tm = val[0];
        int width = val[0].cols, height = val[0].rows, tp = tm.type();
        for(auto m : val){
            if(tp != CV_8UC1 && tp != CV_16SC1
            && tp != CV_16UC1 && tp != CV_16FC1 && tp != CV_32FC1
            && tp != CV_32SC1 && tp != CV_64FC1)
            {
                assert("Mat with single channel only supported.");
                return;
            }

            if(m.type() != tp){
                assert("Mat in the list must be a same type.");
                return;
            }
        }
        bind(val);
    }

    EMat::EMat(cv::Mat val) {
        rows = val.rows;
        cols = val.cols;
        type = val.type();

        this->size = cv::Size(rows, cols);
    }

    EMat EMat::clone() {
        std::vector<cv::Mat> list;
        for(auto mat: this->_list)
            list.push_back(mat);
        EMat res = EMat::fromList(list);
        return res;
    }
    EMat EMat::fromList(std::vector<cv::Mat> list) {
        return EMat(list);
    }
    EMat EMat::fromMat(cv::Mat mat) {
        std::vector<cv::Mat> list;
        int tp = mat.type();
        if(tp == CV_8UC1 || tp == CV_8SC1 || tp == CV_16SC1 ||
        tp == CV_16UC1 || tp == CV_16FC1 || tp == CV_32FC1 ||
        tp == CV_32SC1 || tp == CV_64FC1){
            //First one is gray matrix, the secondary one is the matrix
            list.push_back(mat);
            list.push_back(mat);
        }else{
            cv::split(mat,list);
            //move the matrix
            list.push_back(mat);
            for(int i = list.size() - 1; i > 0; i--)
                list[i] = list[i-1];
            cv::cvtColor(mat,mat,cv::COLOR_BGR2GRAY);
            list[0] = mat;
        }
        return EMat::fromList(list);
    }

    EMat EMat::show(EString title, int waitKey, cv::Size size, bool opengl) {
        if (opengl)
            cv::namedWindow(title.toStdChars(), cv::WindowFlags::WINDOW_OPENGL);
        else
            cv::namedWindow(title.toStdChars(), cv::WindowFlags::WINDOW_NORMAL);

        cv::moveWindow(title.toStdChars(), 100, 0);
        if (size.width > 0 && size.height > 0)
            cv::resizeWindow(title.toStdChars(), size);
        else
            cv::resizeWindow(title.toStdChars(), cv::Size(cols / 2, rows / 2));

        cv::Mat mat;
        std::vector<cv::Mat> list;
        for(int i = 1; i < this->_list.size(); i++)
            list.push_back(this->_list[i]);

        cv::merge(list,mat);

        cv::imshow(title.toStdChars(), mat);
        cv::waitKey(waitKey);
        return *this;
    }

    EMat EMat::details() {
        std::cout << "------------------------------" << std::endl;
        EString type;
        bindType(type);
        std::cout << "type\t\t= " << type.toStdString() << std::endl;
        std::cout << "size\t\t= " << this->size << std::endl;
        double maxVal = 0.0, minVal = 0.0;
        int minIdx[2] = {}, maxIdx[2] = {};    // minnimum Index, maximum Index
        minMaxIdx(this->_list[0], &minVal, &maxVal, minIdx, maxIdx);
        std::cout << "min value\t= [ " << minIdx[0] << " , " << minIdx[1] << " , " << minVal << " ]" << std::endl;
        std::cout << "max value\t= [ " << maxIdx[0] << " , " << maxIdx[1] << " , " << maxVal << " ]" << std::endl;
        std::cout << "------------------------------" << std::endl;
        return *this;
    }

    EMat EMat::bindType(EString &val, int _type) {
        if (_type = -1) {
            _type = this->_list[0].type();
        }
        switch (_type) {
            case CV_8UC1:
                val = EString::format("CV_8UC1");
                break;
            case CV_8SC1:
                val = EString::format("CV_8SC1");
                break;
            case CV_16FC1:
                val = EString::format("CV_16FC1");
                break;
            case CV_16SC1:
                val = EString::format("CV_16SC1");
                break;
            case CV_32FC1:
                val = EString::format("CV_32FC1");
                break;
            case CV_64FC1:
                val = EString::format("CV_64FC1");
                break;
            default:
                val = EString::format("NULL");
                break;
        }
        return *this;
    }

    template<typename T> T EMat::at(int rows, int cols) {
        // return this->_mat.at<T>(rows,cols);
    }
    EMat EMat::get(int channel) {
        return EMat();
    }

    void EMat::dispose() {
        for(auto m: this->_list)
            m.release();
        this->_list.clear();
    }
}