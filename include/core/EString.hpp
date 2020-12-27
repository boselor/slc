#include <iostream>
#include <string>
#include <Defination.hpp>
#ifndef SLC_ESTRING
#define SLC_ESTRING
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

        static EString fromInt(int val);
        static EString fromDouble(double val);
        static EString fromBoolean(bool val);
        static EString fromStdString(const std::string val);
        static EString fromChars(const char* val);
        static EString format(const char* formater, ...);
        static EString empty();

        void print();

        //字符串操作
        EString operator+(const std::string val);
        EString(std::string val);
        std::string toStdString();
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

        //逻辑操作符
        EString(char* val);
    };
} // namespace slc
#endif