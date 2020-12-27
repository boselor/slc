#include <core/EString.hpp>
#include<cstdarg>
#include <stdio.h>
#include <stdarg.h>

namespace slc {
    EString EString::empty() {
        EString res;
        res.entity = "";
        return res;
    }

    void EString::print() {
        std::cout << this->toStdString() << std::endl;
    }

    EString EString::fromInt(int val) { return EString(val); }

    EString EString::fromDouble(double val) { return EString(val); }

    EString EString::fromBoolean(bool val) { return EString(val); }

    EString EString::fromStdString(const std::string val) { return EString(val); }

    EString EString::format(const char *format, ...) {
        va_list args;
        int len;
        char *buffer;

        va_start(args, format);
        len = _vscprintf(format, args) + 1;
        buffer = (char *) malloc(len * sizeof(char));
        std::vsprintf(buffer, format, args);
        EString res = EString(buffer);
        free(buffer);
        return res;
    }

#pragma region basic

    EString::~EString() {
    }

    EString::EString() {
    }

    EString EString::clone() {
        return EString(this->entity);
    }

#pragma endregion
//字符串操作
#pragma region string

    EString EString::operator+(const std::string val) {
        std::string buf = this->entity + val;
        return EString(buf);
    }

    EString::EString(std::string val) {
        this->entity = val;
    }

    std::string EString::toStdString() {
        return this->entity;
    }

#pragma endregion

#pragma region number

    EString EString::operator+(int val) {
        std::string buf;
        return EString(buf);
    }

    EString::EString(int val) {
        this->entity = std::to_string(val);
    }

    int EString::toInt32() {
        return std::atoi(this->entity.c_str());
    }

    EString EString::operator+(double val) {
        std::string buf;
        return EString(buf);
    }

    EString::EString(double val) {
        this->entity = std::to_string(val);
    }

    double EString::toDouble() {
        return std::atof(this->entity.c_str());
    }

#pragma endregion

#pragma region logic

    EString::EString(const bool val) {
        this->entity = val ? "TRUE" : "FALSE";
    }

#pragma endregion

#pragma region chars

    EString::EString(char *val) {
        this->entity = val;
    }

#pragma endregion

} // namespace slc