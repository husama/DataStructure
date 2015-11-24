#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <iostream>
using namespace std;
template <class T>
class heap
{
private:
    int maxsize;//堆最大的大小
    int size;//堆大小
    T *items;//堆数组,且items[0]是哨位结点
public:
    heap( int max = 100 );
    ~heap();
    void Insert( T item );
    T DeleteMin();
    bool IsEmpty();
    bool IsFull();
};

template <class T>
heap<T>::heap(int max)
{
    maxsize = max;
    items = new T[maxsize+1];//因为items[0]是哨位结点
    if (items == NULL)
        cout<<"OUT OF SPACE!!!";
    size = 0;
   // items[0] = -10000;
}

template <class T>
heap<T>::~heap()
{
    delete[] items;
}

template <class T>
bool heap<T>::IsEmpty()
{
    if (size == 0)
        return true;
    return false;
}

template <class T>
bool heap<T>::IsFull()
{
    if (size == maxsize)
        return true;
    return false;
}


template <class T>
void heap<T>::Insert( T item)
{
    int i = 1;
    if (size == maxsize)
    {
        cout<<"HEAP IS FULL!!!";
        return;
    }

    size++;
    if ( size == 1 )
    {
        items[size] = item;
        return;
    }

    for ( i = size; i/2>0 && item < items[i/2]; i/=2 )
        items[i] = items[i/2];
    items[i] = item;
    //cout<<items[1]<<endl;
}

template <class T>
T heap<T>::DeleteMin()
{
    int i , child;
    T lastItem, minItem;
    if (size == 0)
        cout<<"THE HEAP IS EMPTY!!!";
    lastItem = items[size];
    minItem = items[1];
    size--;
    for ( i =1; i*2 <= size; i = child)
    {
        child = i*2;
        if (child != size && items[child] > items[child+1])
            child++;
        if (lastItem > items[child])
            items[i] = items[child];
        else
            break;
    }
    items[i] = lastItem;
    return minItem;
}
#endif // HEAP_H_INCLUDED
