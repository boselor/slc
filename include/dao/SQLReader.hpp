//
// Created by xiaoyong on 2020/12/30.
//

#ifndef SLC_SQLADAPTER_HPP
#define SLC_SQLADAPTER_HPP
#include <core/EString.hpp>
namespace slc{
    class SQLAdapter{
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
        EString scalarAction(EString sql);
    };
}
#endif //SLC_SQLADAPTER_HPP
