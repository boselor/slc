#include <iostream>
#include <string>
namespace slc
{
    class EString
    {
    private:
        char *p;
        std::string entity = "";

    public:
        int Length = -1;
        
        EString(/* args */);
        ~EString();
        //字符串操作
        EString operator+(const std::string val);
        EString(std::string val);
        std::string toStdString();
        EString operator=(const EString val);
        EString clone();

        //数字的操作
        EString operator+(int val);
        EString(int val);
        int toInt32();
        EString operator+(double val);
        EString(double val);
        double toDouble();

        //逻辑操作符
        EString(bool val);
    };
} // namespace slc