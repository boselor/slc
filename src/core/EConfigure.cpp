#include <core/EConfigure.hpp>
#include <fstream>

namespace slc {
    EConfigure::EConfigure() {}
    EConfigure::~EConfigure() {}

    bool EConfigure::loadFile(EString file) {
        if(file.isEmpty()) return false;

        std::ifstream reader;
        reader.open(file.toStdChars(),std::ios::ate);

        if(!reader.is_open())
            return false;

        std::string s;
        while(getline(reader,s))
        {
            EString::format("%s",s.c_str());
        }
        reader.close();

        return true;
    }

    EString EConfigure::readString(EString path, const EString val) {
        if(path.isEmpty())
            return val;
        EString res;

        return res;
    }
}