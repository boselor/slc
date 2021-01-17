//
// Created by Xiaoyong on 2020/12/28.
//

#ifndef SLC_MATH_H
#define SLC_MATH_H

#include <core/EString.hpp>
#include <core/IniConfigure.hpp>
#include <log/File.hpp>

namespace slc {
    class ParallelMath {
    private:
        File logger;
        IniConfiguration configuration;
    public:
        void setLogger(File &log);
        void setConfigure(IniConfiguration &config);

        int* add (const int* a , const int* b, int c);
    };
}
#endif //SLC_MATH_H
