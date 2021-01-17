//
// Created by xiaoyong on 2020/12/30.
//

#ifndef SLC_SQLADAPTER_HPP
#define SLC_SQLADAPTER_HPP
#include <core/EString.hpp>
#include <dao/SQLReader.hpp>
#include <log/Logger.hpp>

namespace slc{
    class SQLAdapter{
    private:
        Logger logger;
    public:
        SQLAdapter();
        SQLAdapter(EString connectStrings);
        ~SQLAdapter();
        SQLAdapter static createInstance(EString connectStrings);
        bool connect(EString connectStrings);
        bool isConnected();

        int insertAction(EString sql);
        int deleteAction(EString sql);
        int updateAction(EString sql);
        SQLAdapter readAction(EString sql);
    };
}
#endif //SLC_SQLADAPTER_HPP
