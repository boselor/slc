//
// Created by xiaoyong on 2020/12/30.
//
#include <dao/SQLAdapter.hpp>

namespace slc{
    SQLAdapter::SQLAdapter() {}
    SQLAdapter::~SQLAdapter() {}
    SQLAdapter::SQLAdapter(EString connectStrings) {
        if(!connectStrings.isEmpty())
            connect(connectStrings);
    }

    bool SQLAdapter::connect(EString connectStrings) {
        int rc = sqlite3_open(connectStrings.toStdString().c_str(),&this->_db);
        std::cout << rc << std::endl;
    }
    bool SQLAdapter::isConnected() {}
    SQLAdapter SQLAdapter::createInstance(EString connectStrings) {}
    int SQLAdapter::insertAction(EString sql) {}
    int SQLAdapter::deleteAction(EString sql) {}
    int SQLAdapter::updateAction(EString sql) {}
    SQLAdapter SQLAdapter::readAction(EString sql) {}
}