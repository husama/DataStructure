#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph<char> g;
    int choice , cost;
    char from , to;
    cout<<"����ʹ���ڽӱ�ķ�ʽ����һ��Graph!!!\n";
    g.creatGraph();
    cout<<"�������!\n";
    while (1)
    {
        cout<<"\n����������ѡ��"
            <<"\n1.����ָ���ߵ�Ȩֵ��"
            <<"\n2.��ͼ�в���һ���ߡ�"
            <<"\n3.��ͼ��ɾ��һ���ߡ�"
            <<"\n4.����ͼ��ĳ����ĵ�һ���ڽӶ��㡣"
            <<"\n5.������ȱ�����"
            <<"\n6.������ȱ�����"
            <<"\n7.����������ֱ������ȷ���������ͼ���޻���ͨͼ��������������������"
            <<"\n0.�˳�����\n\n";
        cout<<"please input:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"��������ʼ���㣺";
            cin>>from;
            cout<<"��������ʼ���㣺";
            cin>>to;
            cost = g.getCost(from,to);
            if (cost == int(~(unsigned int)0 / 2) )
            {
                cout<<"���"<<from<<"����"<<to<<"֮��û�б�\n\n";
            }
            else
            {
                cout<<"���"<<from<<"����"<<to<<"֮��ߵ�ȨֵΪ"<<cost<<"\n\n";
            }
            break;
        case 2:
            cout<<"��������ʼ���㣺";
            cin>>from;
            cout<<"������������㣺";
            cin>>to;
            cout<<"������Ȩֵ�� ";
            cin>>cost;
            if(g.Insert(from,to,cost))
            {
                cout<<"����ɹ�";
            }
            else
            {
                cout<<"����ʧ��";
            }
            break;
        case 3:
            cout<<"��������ʼ���㣺";
            cin>>from;
            cout<<"������������㣺";
            cin>>to;
            if (g.Delete(from,to))
            {
                cout<<"ɾ���ɹ�";
            }
            else
            {
                cout<<"ɾ��ʧ��";
            }
            break;
        case 4:
            cout<<"������˶��㣺";
            cin>>from;
            g.getSearchFirst(from);
            break;
        case 5:
            cout<<"����������Ҫ�Ӻδ���ʼ������ȱ���: ";
            cin>>from;
            g.DepthFirstSearch(from);
            cout<<endl;
            break;
        case 6:
            cout<<"����������Ҫ�Ӻδ���ʼ������ȱ���: ";
            cin>>from;
            g.BreadthFirstSearch(from);
            cout<<endl;
            break;
        case 7:
            cout<<"��������ֱ��Ϊ��"<<g.shortest()<<endl;
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}
