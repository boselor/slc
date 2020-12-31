//
// Created by xiaoyong on 2020/12/30.
//

#ifndef SLC_FILE_HPP
#define SLC_FILE_HPP
#include <core/EString.hpp>
namespace slc{
    class File{
    private:
        EString _file;
    public:
        File();
        File(EString val);
        ~File();
        bool isExist();

        EString getAbsolute();
    };
}
#endif //SLC_FILE_HPP
