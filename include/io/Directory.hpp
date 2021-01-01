//
// Created by xiaoyong on 2021/1/1.
//

#ifndef SLC_DIRECTORY_HPP
#define SLC_DIRECTORY_HPP
#include <core/EString.hpp>
#include <io/File.hpp>
#include <vector>
namespace slc{
    class Directory{
    private:
        EString _entity;
    public:
        Directory(EString val);
        Directory();
        ~Directory();
        std::vector<File> listFiles(bool loop, EString extension);
        std::vector<Directory> listDirs(bool loop);
        bool exist();
        bool mk_dirs();
        bool mk_dir();
    };
}
#endif //SLC_DIRECTORY_HPP
