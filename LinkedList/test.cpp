#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> li;
    int n,k,tmp;
    cout<<"您将要构造一个有n个结点的链表，请输入n：";
    cin>>n;
    for (int i = 1 ; i<=n ; i++)
    {
        cout<<"请输入第"<<i<<"个结点的值，值为整数：";
        cin>>tmp;
        li.BehindInsert(tmp);
    }
    cout<<"您输入的链表是：";
    li.print();
    while (1)
    {
        cout<<"\n\n\n请输入您的选择：\n1.在表头插入值为item的结点\t\t2.在表尾插入值为item的结点\n3.在第K个结点后插入值为item的结点\t"
            <<"4.在表头删除结点\n5.在表尾删除结点\t\t\t6.在第K个结点后删除结点\n7.输出第K个结点的值\t\t\t8.查找链表结点是否有值为item的结点\n"
            <<"9.打印链表\n0.退出程序\n";
        cout<<"input:";
        cin>>n;
        switch (n)
        {
            case 0: return 0;
            case 1: cout<<"请输入item的值：";
                    cin>>tmp;
                    li.FrontInsert(tmp);
                    cout<<"操作成功";
                    break;
            case 2: cout<<"请输入item的值：";
                    cin>>tmp;
                    li.BehindInsert(tmp);
                    cout<<"操作成功";
                    break;
            case 3: cout<<"请输入k：";
                    cin>>k;
                    cout<<"请输入item的值：";
                    cin>>tmp;
                    if ( !li.NowInsert(k,tmp) )
                        cout<<"链表长度小于K，插入失败";
                    else
                        cout<<"操作成功";
                    break;
            case 4: if (!li.FrontDelete())
                        cout<<"此链表为空，无法删除";
                    else
                        cout<<"操作成功";
                    break;
            case 5: if (!li.BehindDelete())
                        cout<<"此链表为空，无法删除";
                    else
                        cout<<"操作成功";
                    break;
            case 6: cout<<"请输入k：";
                    cin>>k;
                    if (!li.NowDelete(k))
                        cout<<"链表长度小于K，删除失败";
                    else
                        cout<<"操作成功";
                    break;
            case 7: cout<<"请输入k：";
                    cin>>k;
                    if (!li.Find(k,tmp))
                        cout<<"链表长度小于K，查找失败";
                    else
                        cout<<tmp;
                    break;
            case 8: cout<<"请输入item的值：";
                    cin>>tmp;
                    if (li.Search(tmp))
                        cout<<"链表存在值为"<<tmp<<"的结点";
                    else
                        cout<<"链表不存在值为"<<tmp<<"的结点";
                    break;
            case 9: li.print();
                    cout<<endl;
                    break;

        }

    }
    return 0;
}
