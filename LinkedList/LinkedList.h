#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T item;
    Node<T> *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
public:
    LinkedList(){ head = new Node<T>; head->next = NULL; }//构造表头哨位节点
    ~LinkedList();//析构函数，释放链表空间
    bool FrontInsert(T item);//在表头插入值为item的结点
    bool BehindInsert(T item);//在表尾插入值为item的结点
    bool NowInsert(int k,T item);//在第K个结点后插入值为item的结点
    bool Insert(T item, Node<T> * nowptr);//在当前结点后插入值为item的结点
    bool Delete( Node<T> * nowptr);//在当前结点后删除结点
    bool FrontDelete();//在表头删除结点
    bool BehindDelete();//在表尾删除结点
    bool NowDelete(int k);//在第K个结点后删除结点
    bool Find(int k ,T &item);//将链表第K个结点的item赋值给item，若不存在，返回false!!!
    T FindNow(Node<T> *nowptr);//返回当前结点的item
    bool IsEmpty(){return head->next == NULL;}
    int length ();
    int Search(T item);//查找链表结点是否有值为item的结点，若有，返回序号，无，返回-1
    void print();
};

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = head;
    Node<T> *q = NULL;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>
bool LinkedList<T>::Insert(T item, Node<T> *nowptr)
{
    if (nowptr == NULL)
        return false;
    Node<T> *tmp = new Node<T>;
    tmp->item = item;
    tmp->next = nowptr->next;
    nowptr->next = tmp;
    return true;
}

template <class T>
bool LinkedList<T>::BehindInsert( T item )
{
    Node<T> *p = head;
    while (p->next)
    p = p->next;//移动到表尾结点
    return Insert(item ,p);
}

template <class T>
bool LinkedList<T>::FrontInsert(T item)
{
    return Insert(item ,head);

}

template <class T>
bool LinkedList<T>::Delete(Node<T> *nowptr)
{
    if (nowptr == NULL)
        return false;
    Node<T> *tmp = nowptr->next;
    nowptr->next = tmp->next;
    delete tmp;
    return true;
}

template <class T>
bool LinkedList<T>::BehindDelete()
{
    Node<T> *p = head;
    while (p->next->next==NULL)
        p=p->next;
    return Delete(p);
}
template <class T>
bool LinkedList<T>::FrontDelete()
{
    return Delete(head);
}
template <class T>
T LinkedList<T>::FindNow(Node<T> *nowptr)
{
    return nowptr->item;
}

template <class T>
bool LinkedList<T>::Find(int k, T &item)
{
    int i=0;
    Node<T> *p = head;
    while ( i<k )
    {
        if (p->next == NULL)
            return false;
        p = p->next;
        i++;
    }
    item = FindNow(p);
    return true;
}

template <class T>
bool LinkedList<T>::NowInsert(int k, T item)
{
    int i=0;
    Node<T> *p = head;
    while ( i<k )
    {
        if (p->next == NULL)
            return false;
        p = p->next;
        i++;
    }
    Insert(item,p);
    return true;
}

template <class T>
bool LinkedList<T>::NowDelete(int k)
{
    int i=0;
    Node<T> *p = head;
    while ( i<k )
    {
        if (p->next == NULL)
            return false;
        p = p->next;
        i++;
    }
    Delete(p);
    return true;
}
template <class T>
int LinkedList<T>::Search(T item)
{
    Node<T> *p = head->next;
    int k = 0;
    while (p)
    {
        k++;
        if (p->item==item)
            return k;
        p = p->next;
    }
    return -1;
}
template <class T>
void LinkedList<T>::print()
{
    if(head->next == NULL)
        cout<<"链表无元素";
    else
    {
        Node<T> *p = head;
        while (p->next->next)
        {
            cout<<"["<<p->next->item<<"]"<<"->";
            p = p->next;
        }
        p=p->next;
        cout<<"["<<p->item<<"]";
    }
}
template <class T>
int LinkedList<T>::length()
{
    Node<T> *p=head;
    int k = 0;
    while (p->next)
    {
        k++;
        p = p->next;
    }
    return k;
}


#endif // LINKEDLIST_H_INCLUDED
