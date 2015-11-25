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
    LinkedList(){ head = new Node<T>; head->next = NULL; }//�����ͷ��λ�ڵ�
    ~LinkedList();//�����������ͷ�����ռ�
    bool FrontInsert(T item);//�ڱ�ͷ����ֵΪitem�Ľ��
    bool BehindInsert(T item);//�ڱ�β����ֵΪitem�Ľ��
    bool NowInsert(int k,T item);//�ڵ�K���������ֵΪitem�Ľ��
    bool Insert(T item, Node<T> * nowptr);//�ڵ�ǰ�������ֵΪitem�Ľ��
    bool Delete( Node<T> * nowptr);//�ڵ�ǰ����ɾ�����
    bool FrontDelete();//�ڱ�ͷɾ�����
    bool BehindDelete();//�ڱ�βɾ�����
    bool NowDelete(int k);//�ڵ�K������ɾ�����
    bool Find(int k ,T &item);//�������K������item��ֵ��item���������ڣ�����false!!!
    T FindNow(Node<T> *nowptr);//���ص�ǰ����item
    bool IsEmpty(){return head->next == NULL;}
    int length ();
    int Search(T item);//�����������Ƿ���ֵΪitem�Ľ�㣬���У�������ţ��ޣ�����-1
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
    p = p->next;//�ƶ�����β���
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
        cout<<"������Ԫ��";
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
