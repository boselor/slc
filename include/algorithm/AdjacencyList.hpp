//
// Created by xiaoyong on 2020/12/29.
//

#ifndef SLC_ADJACENCYLIST_H
#define SLC_ADJACENCYLIST_H

template<T>
class AdjacencyList<T>{
public:
    struct AdjacencyNode{
        AdjacencyList* pre;
        T element;
        AdjacencyList* next;
    };
};
#endif //SLC_ADJACENCYLIST_H
