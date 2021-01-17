//
// Created by xiaoyong on 2020/12/29.
//
#include <algorithm/SeqList.hpp>
#include <Defination.hpp>
using namespace slc;

template <class T>
SeqList<T>::SeqList(T a[],int n)
{
    if(n>MaxSize)
        data = (T* )malloc(sizeof(T) * n);
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length=n;
}

template <class T>
T SeqList<T>::Get(int i)
{
    if(i<1 && i>length)
        throw "wrong Location";
    else return data[i-1];
}

template <class T>
int SeqList<T>::Locate(T x)
{
    for(int i=0;i<length;i++)
        if(data[i]==x) return i+1;
    return 0;
}

template <class T>
void SeqList<T>::Insert(int i,T x)
{
    if(length >= MaxSize)
    {
        if(i<1 && i>length)
            throw "wrong Location";
    }
    if(i<1 || i>length+1) throw "Location";
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

template <class T>
T SeqList<T>::Delete(int i)
{
    int x;
    if(length==0) throw "Underflow";
    if(i<1 || i>length) throw "Location";
    x = data[i-1];
    for(int j=i;j<length;j++)
        data[j-1] = data[j];
    length--;
    return x;
}
