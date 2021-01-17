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
        return false;
    }
    bool SQLAdapter::isConnected() {
        return false;
    }
    SQLAdapter SQLAdapter::createInstance(EString connectStrings) {
        return SQLAdapter();
    }
    int SQLAdapter::insertAction(EString sql) {
        return -1;
    }
    int SQLAdapter::deleteAction(EString sql) {
        return -1;
    }
    int SQLAdapter::updateAction(EString sql) {
        return -1;
    }
    SQLAdapter SQLAdapter::readAction(EString sql) {
        return SQLAdapter();
    }
}