//
// Created by Xiaoyong on 2020/12/27.
//
#include <core/EString.hpp>
#ifndef SLC_PLATFORM_HPP
#define SLC_PLATFORM_HPP
namespace slc
{
    class Platform
    {
    private:
    public:
        EString Name;
        int Ver;
        static bool IsPlatform(EString val);
        static bool IsWindows();
        static bool IsLinux();
        Platform(/* args */);
        ~Platform();
    };

} // namespace slc
#endif //SLC_PLATFORM_HPP