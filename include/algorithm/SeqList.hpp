//
// Created by xiaoyong on 2020/12/29.
//

#ifndef SLC_SEQLIST_H
#define SLC_SEQLIST_H
#include <iostream>

namespace slc{
    const int MaxSize = 100;
    template <class T>
    class SeqList
    {
    public:
        SeqList(){length=0;}            //
        SeqList(T a[],int n);    //
        ~SeqList(){}                    //
        int Length(){return length;}    //
        T Get(int i);            //
        int Locate(T x);         //
        void Insert(int i,T x);  //
        T Delete(int i);         //
        void PrintList();               //
    private:
        T data[MaxSize];         //
        int length;                     //
    };
}

#endif //SLC_SEQLIST_H
