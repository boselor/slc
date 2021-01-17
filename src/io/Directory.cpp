//
// Created by xiaoyong on 2021/1/1.
//
#include <io/Directory.hpp>
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif

namespace slc{
    Directory::Directory() {}
    Directory::~Directory() {}
    Directory::Directory(EString val) { this->_entity = val; }
    std::vector<Directory> Directory::listDirs(bool loop = false) {
        return std::vector<Directory>();
    }
    std::vector<File> Directory::listFiles(bool loop = false, EString ext = EString::format("*.*")) {
        return std::vector<File>();
    }
    bool Directory::mk_dirs() {
        uint32_t beginCmpPath = 0;
        uint32_t endCmpPath = 0;

        std::string fullPath = "";
        //Absolute path
        fullPath = this->_entity.toStdChars();
        beginCmpPath = 1;

        if (fullPath[fullPath.size() - 1] != '/')
        {
            fullPath += "/";
        }
        endCmpPath = fullPath.size();
        //create dirs;
        for(uint32_t i = beginCmpPath; i < endCmpPath ; i++ )
        {
            if('/' == fullPath[i])
            {
                std::string curPath = fullPath.substr(0, i);
                if(access(curPath.c_str(), F_OK) != 0)
                    if(mkdir(curPath.c_str()) == -1)
                        return false;
            }
        }

        return true;
    }
    bool Directory::mk_dir() {
        return mkdir(this->_entity.toStdChars()) == 0;
    }
    bool Directory::exist() {
        return File(this->_entity).isExist();
    }
}