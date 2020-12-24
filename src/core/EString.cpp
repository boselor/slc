#include <core/EString.hpp>

namespace slc
{
#pragma region basic
    EString::~EString()
    {
    }
    EString::EString()
    {
    }
    EString EString::operator=(const EString val)
    {
        return val;
    }
    EString EString::clone()
    {
        return EString(this->entity);
    }
#pragma endregion
//字符串操作
#pragma region string
    EString EString::operator+(const std::string val)
    {
        std::string buf = this->entity + val;
        return EString(buf);
    }
    EString::EString(std::string val)
    {
        this->entity = val;
    }
    std::string EString::toStdString()
    {
        return this->entity;
    }
#pragma endregion

#pragma region number
    EString EString::operator+(int val)
    {
        std::string buf;
        return EString(buf);
    }
    EString::EString(int val)
    {
        this->entity = std::to_string(val);
    }
    int EString::toInt32()
    {
        return std::atoi(this->entity.c_str());
    }
    EString EString::operator+(double val)
    {
        std::string buf;
        return EString(buf);
    }
    EString::EString(double val)
    {
        this->entity = std::to_string(val);
    }
    double EString::toDouble()
    {
        return std::atof(this->entity.c_str());
    }
#pragma endregion

#pragma region logic
    EString::EString(const bool val)
    {
        this->entity = val ? "TRUE" : "FALSE";
    }
#pragma endregion
} // namespace slc