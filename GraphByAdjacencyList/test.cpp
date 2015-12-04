#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph<char> g;
    int choice , cost;
    char from , to;
    cout<<"您将使用邻接表的方式构造一个Graph!!!\n";
    g.creatGraph();
    cout<<"构造完成!\n";
    while (1)
    {
        cout<<"\n请输入您的选择："
            <<"\n1.返回指定边的权值。"
            <<"\n2.向图中插入一条边。"
            <<"\n3.从图中删除一条边。"
            <<"\n4.查找图中某顶点的第一个邻接顶点。"
            <<"\n5.深度优先遍历。"
            <<"\n6.广度优先遍历。"
            <<"\n7.求自由树的直径（请确保您输入的图是无环连通图，即自由树！！！）。"
            <<"\n0.退出程序\n\n";
        cout<<"please input:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"请输入起始顶点：";
            cin>>from;
            cout<<"请输入起始顶点：";
            cin>>to;
            cost = g.getCost(from,to);
            if (cost == int(~(unsigned int)0 / 2) )
            {
                cout<<"结点"<<from<<"与结点"<<to<<"之间没有边\n\n";
            }
            else
            {
                cout<<"结点"<<from<<"与结点"<<to<<"之间边的权值为"<<cost<<"\n\n";
            }
            break;
        case 2:
            cout<<"请输入起始顶点：";
            cin>>from;
            cout<<"请输入结束顶点：";
            cin>>to;
            cout<<"请输入权值： ";
            cin>>cost;
            if(g.Insert(from,to,cost))
            {
                cout<<"插入成功";
            }
            else
            {
                cout<<"插入失败";
            }
            break;
        case 3:
            cout<<"请输入起始顶点：";
            cin>>from;
            cout<<"请输入结束顶点：";
            cin>>to;
            if (g.Delete(from,to))
            {
                cout<<"删除成功";
            }
            else
            {
                cout<<"删除失败";
            }
            break;
        case 4:
            cout<<"请输入此顶点：";
            cin>>from;
            g.getSearchFirst(from);
            break;
        case 5:
            cout<<"请输入您想要从何处开始深度优先遍历: ";
            cin>>from;
            g.DepthFirstSearch(from);
            cout<<endl;
            break;
        case 6:
            cout<<"请输入您想要从何处开始广度优先遍历: ";
            cin>>from;
            g.BreadthFirstSearch(from);
            cout<<endl;
            break;
        case 7:
            cout<<"自由树的直径为："<<g.shortest()<<endl;
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}
