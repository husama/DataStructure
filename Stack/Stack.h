#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;
//顺序栈
template<class T>
class Stack
{
private:
    int Size;//数组的大小
    T * StackArray;//栈使用的数组
    int Top;//栈顶位置
public:
    Stack(int maxsize = 100);
    ~Stack();
    bool push(T item);
    T top();
    T pop();
    bool isFull();
    bool isEmpty();
    void print();
};

template <class T>
Stack<T>::Stack(int maxsize)
{
    Size = maxsize;
    StackArray = new T[maxsize];
    for (int i =0; i<maxsize; i++)
        StackArray[i]=-1;
    Top = -1;
}
template <class T>
Stack<T>::~Stack()
{
    delete[] StackArray;
}
template <class T>
bool Stack<T>::isFull()
{
    if (Top == Size-1)
        return true;
    else
        return false;
}
template <class T>
bool Stack<T>::isEmpty()
{
    if (Top == -1)
        return true;
    else
        return false;
}
template <class T>
bool Stack<T>::push(T item)
{
    if (isFull())
        return false;
    Top++;
    StackArray[Top] = item;
    return true;
}

template <class T>
T Stack<T>::top()
{
    if (Top == -1)
    {
        cout<<"ERROR:STACK IS EMPTY!!!!";
        exit(-1);
    }

    return StackArray[Top];
}

template <class T>
T Stack<T>::pop()
{
    if (Top == -1)
    {
        cout<<"ERROR:STACK IS EMPTY!!!!";
        exit(-1);
    }
    Top--;
    return StackArray[Top+1];
}

template <class T>
void Stack<T>::print()
{
    for (int i=Top; i>-1; i--)
        cout<<StackArray[i]<<" ";
}

#endif // STACK_H_INCLUDED
