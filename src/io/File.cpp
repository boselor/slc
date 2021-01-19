//
// Created by xiaoyong on 2020/12/30.
//

#include <io/File.hpp>
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif


namespace slc{
    File::File() {}
    File::~File() {}
    File::File(EString val) {
        this->_file = val;
    }

    bool File::isExist() {
#ifdef _MSC_VER
        return _access(this->_file.toStdChars(),0) == 0;
#else
        return access(this->_file.toStdChars(),F_OK) == 0;
#endif
    }

    EString File::getAbsolute() {
        return this->_file;
    }
    EString File::getParent() {
        int valS = this->_file.lastIndexOf('\\');
        int valRS = this->_file.lastIndexOf('/');
        return this->_file.substr(0,(valS >= valRS ? valS: valRS));
    }
}