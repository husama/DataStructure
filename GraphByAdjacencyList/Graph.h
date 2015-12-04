#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#define MaxGraphSize 100
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
struct Edge
{
    T NodeName;
    Edge<T> * link;
    int cost;//边的权值
};

//图的邻接表的顶点表结点
template <class T>
struct Vertex
{
    T NodeName;
    Edge<T> * adjacent;
};

template<class T>
class Graph
{
private:
    Vertex<T> *head;
    int graphsize;
    T *value;//用来存储每个结点的值所对应的序号
    int numOfVertex(T Node);//返回结点Node所在头结点表的序号，若无，-1
   // bool isInVertex(T name);
public:
    Graph(){head = NULL;value = NULL;}
    ~Graph();
    void creatGraph();
    int getCost(T from, T to);//返回权值
    bool Insert(T from, T to, int cost);//插入从from到to全值为cost的边
    bool Delete(T from, T to);//删除从from到to的边
    int SearchFirst(T from);
    void getSearchFirst(T from);
    int SearchNext(T v1 , T v2);//求序号为v1的顶点相对于v2的顶点的下个顶点
    void DepthFirstSearch(T Begin);
    void BreadthFirstSearch(T Begin);
    int shortest();
};

template <class T>
Graph<T>::~Graph()
{
    for ( int i = 0 ; i < graphsize ; i++)
    {
        Edge<T> * p = head[i].adjacent;
        while(p!=NULL)
        {
            head[i].adjacent = p->link;
            delete p;
            p = head[i].adjacent;
        }
    }
    delete[] head;
}

template <class T>
int Graph<T>::numOfVertex(T Node)
{
    int k;//Node结点所在头结点表的序号
    for ( k = 0 ; k < graphsize; k++)
    {
        if ( head[k].NodeName == Node)
        {
            break;
        }
    }
    if (  head[k].NodeName != Node)
    {
        //cout<<"不存在值为"<<Node<<"的结点!\n";
        return -1;
    }
    return k;
}

template <class T>
bool Graph<T>::Insert(T from , T to , int cost )
{
    int k , k2;//from结点所在头结点表的序号
    k = numOfVertex(from);
    k2 = numOfVertex(from);
    if ( k == -1 || k2 == -1 )
    {
        return false;
    }
    Edge<T> * q = head[k].adjacent;
    if ( q == NULL )
    {
        Edge<T> *tmp = new Edge<T>;
        tmp->cost = cost;
        tmp->link = NULL;
        tmp->NodeName = to;
        head[k].adjacent = tmp;
    }
    else
    {
        while ( q->link != NULL && q->link->NodeName != to)
        {
            q = q->link;
        }
        if ( q -> link == NULL)
        {
            Edge<T> *tmp = new Edge<T>;
            tmp->cost = cost;
            tmp->link = NULL;
            tmp->NodeName = to;
            q->link = tmp;
        }
        else
        {
            cout<<from<<"到"<<to<<"之间存在边，此操作将权值覆盖\n\n";
            q->link->cost = cost;
        }
    }

    return true;
}

template <class T>
bool Graph<T>::Delete( T from , T to )
{
    int k , k2;//from结点所在头结点表的序号
    k = numOfVertex(from);
    k2 = numOfVertex(from);
    if ( k == -1 || k2 == -1 )
    {
        return false;
    }
    Edge<T> * q = head[k].adjacent;
    if ( q == NULL )
    {
        cout<<"结点"<<from<<"与结点"<<to<<"之间没有边";
        return false;
    }
    else
    {
        if (q->link == NULL&& q->NodeName == to)
        {
            delete q;
            q = NULL;
            return true;
        }
        while ( q->link!= NULL && q->link->NodeName != to )
        {
            q = q->link;
        }
        if ( q->link == NULL )
        {
            cout<<"结点"<<from<<"与结点"<<to<<"之间没有边";
            return false;
        }
        else
        {
            Edge<T> *tmp = q->link->link;
            delete q->link;
            q->link = tmp;
            return true;
        }
    }
}

template <class T>
void Graph<T>::creatGraph()
{
    int num , weight;
    T from ,to;
    head = new Vertex<T>[MaxGraphSize];
    cout<<"请输入图的结点数: ";
    cin>>graphsize;
    value = new T[graphsize];
    for (int i = 0; i < graphsize; i++)
    {
        cout<<"请输入第"<<i+1<<"个结点的值:";
        cin>>head[i].NodeName;
        //value[i-1] = head[i].NodeName;
        head[i].adjacent = NULL;
    }
  //  for (int i =0;i<graphsize;i++)
       // cout<<head[i].NodeName;
    cout<<"请输入图的边数: ";
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"请输入第"<<i+1<<"条边的始点：";
        cin>>from;
        cout<<"请输入第"<<i+1<<"条边的终点：";
        cin>>to;
        cout<<"请输入第"<<i+1<<"条边的权：";
        cin>>weight;
        Edge<T> *p = new Edge<T>;
        p->cost = weight;
        p->link = NULL;
        p->NodeName = to;
        int k,k2;
        k = numOfVertex(from);
        k2 = numOfVertex(to);
        //cout<<k<<" "<<k2;
        if ( k == -1)
        {

            cout<<"无"<<k<<"结点！请重新输入！\n";
            i--;
            continue;
        }
        if ( k == -1)
        {
            cout<<"无"<<k2<<"结点！请重新输入！\n";
            i--;
            continue;
        }
        Edge<T> * q = head[k].adjacent;
        if ( q == NULL )
        {
          //  cout<<3;
            head[k].adjacent = p;
        }
        else
        {
            while ( q->link != NULL )
            {  // cout<<q->link->NodeName<<endl;
                q = q->link;
            }
            q->link = p;
        }
        cout<<"\n";
    }
}

template <class T>
int Graph<T>::getCost( T from , T to )
{
    int k;//from结点所在头结点表的序号
    k = numOfVertex(from);
    if ( k == -1 )
        return int(~(unsigned int)0 / 2);
    Edge<T> * q = head[k].adjacent;
    while ( q!= NULL && q->NodeName != to )
    {
        q = q->link;
    }
    if ( q == NULL )
    {
        //cout<<"结点"<<from<<"与结点"<<to<<"之间没有边\n";
        return int(~(unsigned int)0 / 2);
    }
    else
    {
            return q->cost;
    }
}

template <class T>
int Graph<T>::SearchFirst(T from)
{
    int k;
    k = numOfVertex(from);
    if ( k == -1 )
    {
        return -1;
    }

    else
    {
        Edge<T> * q = head[k].adjacent;
        if ( q == NULL )
        {
            return -1;
        }
        else
        {
            return numOfVertex(q->NodeName) ;
        }
    }
}

template <class T>
int Graph<T>::SearchNext(T v1 , T v2)
{
    int k , k2;
    k = numOfVertex(v1);
    k2 = numOfVertex(v2);
    if ( k == -1 || k2 == -1 )
    {
        return -1;
    }
    else
    {
        Edge<T> * q = head[k].adjacent;

        while (q!=NULL && q->NodeName != v2)
        {
            q = q->link;
        }
        if ( q == NULL )
        {
            return -1;
        }
        else
        {
            q = q->link;
            if ( q == NULL )
            {
                return -1;
            }
            else
            {
                return numOfVertex(q->NodeName);
            }
        }
    }
}

template <class T>
void Graph<T>::DepthFirstSearch( T Begin)
{
    int * visited = new int[graphsize];
    int k , v;
    for ( k = 0; k<graphsize; k++)
    {
        visited[k] = 0;
    }
    v = numOfVertex(Begin);
    //cout<<v<<endl;
    stack<int> s;
    s.push(v);
    int w;
    cout<<"begin test!\n";
    while (!s.empty())
    {
        //cout<<"loop\n";
        w = s.top();
        s.pop();
        visited[w] = 1;
        cout<<head[w].NodeName<<" ";
        k = SearchFirst(head[w].NodeName);
        while ( k != -1 )
        {//   cout<<k<<endl;
            if (visited[k] == 0)
            {
                s.push(k);
            }
            k = SearchNext(head[w].NodeName,head[k].NodeName);

        }
    }
    delete[] visited;
}

template <class T>
void Graph<T>::BreadthFirstSearch( T Begin )
{
    int *visited = new int[graphsize];
    for (int k = 0 ;k<graphsize;k++)
    {
        visited[k] = 0;
    }
    int s = numOfVertex(Begin);
    cout<<Begin<<" ";
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        int w = SearchFirst(head[v].NodeName);
       // cout<<"<"<<w<<">\n";
        while ( w != -1 )
        {
            if (visited[w] == 0 )
            {
                cout<<head[w].NodeName<<" ";
                visited[w] = 1;
                q.push(w);
            }
            w = SearchNext(head[v].NodeName,head[w].NodeName);
        }
    }
    delete[] visited;

}

template <class T>
void Graph<T>::getSearchFirst(T from)
{
    int k = SearchFirst(from);
    if ( k == -1)
    {
        cout<<"无此节点或此节点无邻接结点";
    }
    else
    {
        cout<<"此节点的首个邻接顶点是"<<head[k].NodeName;
    }
}

template <class T>
int Graph<T>::shortest()
{
    int result = 0;
    int tmp = int(~(unsigned int)0 / 2);
 int ** matrix = new int *[graphsize];
    for (int i = 0 ;i<graphsize;i++)
        matrix[i] = new int[graphsize];
    for (int i = 0; i<graphsize ; i++)
    {
        for (int j =0 ;j<graphsize;j++)
        {
            if(i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = tmp;
        }

    }
    for (int i = 0; i<graphsize ; i++)
    {
        Edge<T> *p = head[i].adjacent;
        while (p!=NULL)
        {
            matrix[i][numOfVertex(p->NodeName)] = p->cost;
            p = p->link;
        }
    }
    for (int k =0;k<graphsize;k++)
    {
        for (int i = 0; i<graphsize;i++)
        {
            if (i != k)
            {
                for (int j =0 ;j<graphsize;j++)
                {
                    if ( j!=k && j!=i && matrix[i][k]< tmp && matrix[k][j]<tmp &&matrix[i][k]+matrix[k][j]<matrix[i][j])
                    {
                        matrix[i][j] = matrix[i][k]+matrix[k][j];
                    }
                }
            }
        }
    }
    for (int i =0 ; i<graphsize ; i++)
    {
        for (int j = 0;j<graphsize;j++)
        {
            if (matrix[i][j]>result && matrix[i][j]!=tmp)
            {
                result = matrix[i][j];
            }
        }
    }
    return result;
}

 /*  Vertex<T> * tmphead = new Vertex<T>[graphsize];
    for ( int i = 0; i < graphsize ;i++)
    {
        tmphead[i].NodeName = head[i].NodeName;
        Edge<T> * p = head[i].adjacent;
        Edge<T> * q = tmphead[i].adjacent;
        if ( p == NULL)
        {
            q = NULL;
        }
        else
        {
            Edge<T> tmp = new Edge<T>;
            tmp->cost = p->cost;
            tmp->NodeName = p->NodeName;
            tmp->link = NULL;
            q = tmp;
            while (p->link!=NULL)
            {
                Edge<T> * tmp = new Edge<T>;
                tmp->cost = p->link->cost;
                tmp->NodeName = p->link->NodeName;
                tmp->link = NULL;
                q->link = tmp;
                p = p->link;
                q = q->link;
            }
        }

    }
    for (int k = 0; k <graphsize; k++)
    {
        for (int i = 0;i<graphsize;i++)
        {
            if (i!=k)
            {
                Edge<T> * p = tmphead[i].adjacent;
                Edge<T> *q = p;
                while (p!=NULL)
                {
                    if ( numOfVertex(p->NodeName) == k)
                    {
                        Edge<T> * t = tmphead[k].adjacent;
                        while ( t!= NULL)
                        {
                            bool flag = false;;
                            while (q!=NULL)
                            {
                                if (t->NodeName == q->NodeName)
                                    flag = true;
                            }
                            if (!flag)
                            {
                                Edge<T> * tmp =new Edge<T>;
                                tmp->cost = t->cost;
                                t->NodeName = t->NodeName;

                            }
                        }
                    }
                    p = p->link;
                }
            }
        }
    }


    */
#endif // GRAPH_H_INCLUDED
