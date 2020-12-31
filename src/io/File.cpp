//
// Created by xiaoyong on 2020/12/30.
//

#include <io/File.hpp>

namespace slc{
    File::File() {}
    File::~File() {}
    File::File(EString val) {
        this->_file = val;
    }

    bool File::isExist() {
        return false;
    }

    EString File::getAbsolute() {
        return this->_file;
    }
}