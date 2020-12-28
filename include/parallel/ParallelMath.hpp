//
// Created by Xiaoyong on 2020/12/28.
//

#ifndef SLC_MATH_H
#define SLC_MATH_H

#include <core/EString.hpp>
#include <configure/IniConfigure.hpp>
#include <log/Logger.hpp>

namespace slc {
    class ParallelMath {
    private:
        Logger logger;
        IniConfiguration configuration;
    public:
        void setLogger(Logger &log);
        void setConfigure(IniConfiguration &config);

        int* add (const int* a , const int* b, int c);
    };
}
#endif //SLC_MATH_H
