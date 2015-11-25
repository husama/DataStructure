#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> li;
    int n,k,tmp;
    cout<<"����Ҫ����һ����n����������������n��";
    cin>>n;
    for (int i = 1 ; i<=n ; i++)
    {
        cout<<"�������"<<i<<"������ֵ��ֵΪ������";
        cin>>tmp;
        li.BehindInsert(tmp);
    }
    cout<<"������������ǣ�";
    li.print();
    while (1)
    {
        cout<<"\n\n\n����������ѡ��\n1.�ڱ�ͷ����ֵΪitem�Ľ��\t\t2.�ڱ�β����ֵΪitem�Ľ��\n3.�ڵ�K���������ֵΪitem�Ľ��\t"
            <<"4.�ڱ�ͷɾ�����\n5.�ڱ�βɾ�����\t\t\t6.�ڵ�K������ɾ�����\n7.�����K������ֵ\t\t\t8.�����������Ƿ���ֵΪitem�Ľ��\n"
            <<"9.��ӡ����\n0.�˳�����\n";
        cout<<"input:";
        cin>>n;
        switch (n)
        {
            case 0: return 0;
            case 1: cout<<"������item��ֵ��";
                    cin>>tmp;
                    li.FrontInsert(tmp);
                    cout<<"�����ɹ�";
                    break;
            case 2: cout<<"������item��ֵ��";
                    cin>>tmp;
                    li.BehindInsert(tmp);
                    cout<<"�����ɹ�";
                    break;
            case 3: cout<<"������k��";
                    cin>>k;
                    cout<<"������item��ֵ��";
                    cin>>tmp;
                    if ( !li.NowInsert(k,tmp) )
                        cout<<"������С��K������ʧ��";
                    else
                        cout<<"�����ɹ�";
                    break;
            case 4: if (!li.FrontDelete())
                        cout<<"������Ϊ�գ��޷�ɾ��";
                    else
                        cout<<"�����ɹ�";
                    break;
            case 5: if (!li.BehindDelete())
                        cout<<"������Ϊ�գ��޷�ɾ��";
                    else
                        cout<<"�����ɹ�";
                    break;
            case 6: cout<<"������k��";
                    cin>>k;
                    if (!li.NowDelete(k))
                        cout<<"������С��K��ɾ��ʧ��";
                    else
                        cout<<"�����ɹ�";
                    break;
            case 7: cout<<"������k��";
                    cin>>k;
                    if (!li.Find(k,tmp))
                        cout<<"������С��K������ʧ��";
                    else
                        cout<<tmp;
                    break;
            case 8: cout<<"������item��ֵ��";
                    cin>>tmp;
                    if (li.Search(tmp))
                        cout<<"�������ֵΪ"<<tmp<<"�Ľ��";
                    else
                        cout<<"��������ֵΪ"<<tmp<<"�Ľ��";
                    break;
            case 9: li.print();
                    cout<<endl;
                    break;

        }

    }
    return 0;
}
