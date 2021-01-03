/**
* 作者   : 牧轩居士
* 时间   : 2020-12-26 22:25:42
* 文件名 : Emat.hpp
* 描述   : 矩阵扩展类，矩阵扩展类是SLC库内置的一种特殊矩阵，它是一个矩阵的集合，是一个矩阵立方体。
* 约束   : 所有矩阵必须是同一种类型，具有相同尺寸构造的立方体
 * 1. 如果是从cv::Mat 构造，则 0、1、2、3分别为：灰度图、红色波段、绿色波段、蓝色波段组成。
 * 2. 如果是来自GDAL，则默认按照GDAL顺序存储。
**/
#include <opencv2/opencv.hpp>
#include <core/EString.hpp>
#ifndef SLC_EMAT_H
#define SLC_EMAT_H
namespace slc{
    class EMat{
    private:
        std::vector<cv::Mat> _list;
        void bind(std::vector<cv::Mat> list);
    public:
        int rows = -1, cols = -1, type = -1;
        cv::Size size;
        EMat();
        ~EMat();
        EMat(cv::Mat val);
        EMat(std::vector<cv::Mat> val);
        EMat clone();
        EMat show(EString title, int waitKey = 0, cv::Size size = cv::Size(-1,-1), bool opengl = false);
        EMat details();
        EMat bindType(EString& val, int type = -1);

        static EMat fromList(std::vector<cv::Mat> list);
        static EMat fromMat(cv::Mat mat);
        static EMat fromGDAL();

        cv::Mat getMat(int index = -1);
        EMat get(int channel);

        template<typename T> T at(int rows, int cols);

        void dispose();
    };
}
#endif //SLC_EMAT_H
