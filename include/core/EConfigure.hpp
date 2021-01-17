//
// Created by xiaoyong on 2020/12/27.
//

#ifndef SLC_INICONFIGURE_H
#define SLC_INICONFIGURE_H

#include <log/Logger.hpp>
#include <map>

namespace slc {
    class EConfigure{
    private:
        std::map<std::string,std::string> _factory;
    public:
        EConfigure();
        ~EConfigure();

        bool loadFile(EString file);
        void setLogger(Logger &logger);
        EString readString(EString path, const EString val = EString::empty());
        int readInt(EString path, const int val = 0);
        float readFloat(EString path, const double val = 0);
    };
}
#endif //SLC_INICONFIGURE_H
