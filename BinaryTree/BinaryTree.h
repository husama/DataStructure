#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <class T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    int xoffset;
    //int yoffset;
};

template <class T>
class BinaryTree
{
private:
    TreeNode<T> *root;
    TreeNode<T>* father (TreeNode<T> *r,TreeNode<T> *t);
    TreeNode<T>* _Insert(TreeNode<T> *t,T data);//Insert的封装
    TreeNode<T>* _preOrderCreate(T tostop);
    void setx();
    vector< vector<TreeNode<T>*> > sety();
public:
    BinaryTree();
    ~BinaryTree();
    void Father(T item){if (Search(item)&&father(root,Search(item)))cout<<father(root,Search(item))->data;else cout<<"无";}
    void Create(T tostop){cout<<"请输入二叉树前序序列";root = _preOrderCreate(tostop);}//tostop值代表空结点
    void Delete(TreeNode<T> *t);
    void Insert(T data){ root=_Insert(root,data); }//按照二叉查找树的方式插入
    void levelOrder();
    void preOrder();
    void inOrder();
    void postOrder();
    TreeNode<T>* Search(T data);
    void printTree();
    void visit(TreeNode<T> *t);
    bool isCompleteBinaryTree();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    Delete(root);
}

template <class T>
void BinaryTree<T>::Delete(TreeNode<T> *t)
{
    if (t==NULL)
        return;
    Delete(t->left);
    Delete(t->right);
    delete t;
}
template <class T>
void BinaryTree<T>::visit(TreeNode<T> *t)
{
    cout<<t->data<<"  ";
}

template <class T>
void BinaryTree<T>::levelOrder()
{
    queue<TreeNode<T>*> q;
    TreeNode<T> *t = root;
    if (t == NULL)
        return;
	q.push(t);
	while(!q.empty()){
        t = q.front();
		q.pop();
		visit(t);
		if(t->left!=NULL)
			q.push(t->left);
		if(t->right!=NULL)
			q.push(t->right);
	}
}

template <class T>
void BinaryTree<T>::preOrder()
{
    stack<TreeNode<T>*> s;
    TreeNode<T> *t = root;
    while (t!=NULL||!s.empty())
    {
        if (t != NULL)
        {
            visit(t);
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.top();
            s.pop();
            t = t->right;
        }
    }
}

template <class T>
TreeNode<T>* BinaryTree<T>::_preOrderCreate(T tostop)
{
    TreeNode<T>* t;
    T tmp;
    cin>>tmp;
    if (tmp == tostop)
        return NULL;
    else
    {
        t = new TreeNode<T>;
        t->data = tmp;
        t->left = _preOrderCreate(tostop);
        t->right = _preOrderCreate(tostop);
    }
    return t;
}

template <class T>
void BinaryTree<T>::inOrder()
{

    stack<TreeNode<T>*> s;
    TreeNode<T> *t = root;
    if (t==NULL)
        cout<<"NULL";
    while (t!=NULL||!s.empty())
    {
        if (t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.top();
            s.pop();
            visit(t);
            t = t->right;
        }
    }
}



template <class T>
void BinaryTree<T>::postOrder()
{
    //双栈法
    TreeNode<T> * t = root;
    stack<TreeNode<T>*> s1, s2;
    if (t == NULL )
        return;
    s1.push(t);
    while (!s1.empty())
    {
        t = s1.top();
        s1.pop();
        s2.push(t);
        if(t->left!=NULL)
            s1.push(t->left);
        if(t->right!=NULL)
            s1.push(t->right);
    }
    while(!s2.empty()){
        t=s2.top();
        s2.pop();
        visit(t);
    }
}

template <class T>
TreeNode<T>* BinaryTree<T>::father (TreeNode<T> *r, TreeNode<T> *t)
{
    TreeNode<T> * fa;
    if (r==NULL)
    {
        return NULL;
    }
    if (r->left == t || r->right == t)
        return r;
    fa = father(r->left,t);
    if (fa!=NULL)
        return fa;
    else
    {
        fa = father(r->right,t);
        return fa;
    }
}

template <class T>
TreeNode<T>* BinaryTree<T>::Search(T data)
{
    stack<TreeNode<T>*> s;
    TreeNode<T>* flag = NULL;
    TreeNode<T> *t = root;
    while (t!=NULL||!s.empty())
    {
        if (t != NULL)
        {
            if (t->data == data)
            {
                flag = t;
                break;
            }
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.top();
            s.pop();
            t = t->right;
        }
    }
    return flag;
}

template <class T>
TreeNode<T>* BinaryTree<T>::_Insert(TreeNode<T> *t,T data)
{
    if (t == NULL)
    {
        t = new TreeNode<T>;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
    }
    else
    if (t->data > data)
    {
        t->left = _Insert(t->left,data);

    }
    else
    if (t->data < data)
    {
        t->right = _Insert(t->right,data);
    }
    return t;
}

template <class T>
bool BinaryTree<T>::isCompleteBinaryTree()
{
    queue<TreeNode<T> *> Q;
    Q.push(root);
    TreeNode<T> *t;
    //层次遍历，并且把NULL也放入队列中
    while ( (t=Q.front()) !=NULL){
        Q.pop();
        Q.push(t->left);
        Q.push(t->right);
    }
    while (!Q.empty()){
        t=Q.front();
        Q.pop();
        if (t !=NULL)
            return false;  // 有未访问到的的非NULL节点，则非完全二叉树
    }
    return true;
}

template <class T>
void BinaryTree<T>::printTree()
{
    vector<vector<TreeNode<T>*> > v;
    vector<TreeNode<T> *> tmp;
    setx();
    v = sety();
    //cout<<v.size();
    //cout<<v[3][0]->data;
    for (int k = 0;k<v.size();k++)
    {
        tmp = v[k];
        string s;
        //cout<<tmp[tmp.size()-1]->xoffset;
        s.assign(tmp[tmp.size()-1]->xoffset+10,' ');
        //cout<<s<<endl;//用n个字符c赋值给当前字符串
        for (int i = tmp.size()-1; i>=0;i--)
        {
            s[tmp[i]->xoffset] = tmp[i]->data;
        }
        cout<<s<<endl;
        s.assign(tmp[tmp.size()-1]->xoffset+10,' ');
        for (int i = 0;i < tmp.size();i++)
        {
            if(tmp[i]->left!=NULL || tmp[i]->right!=NULL)
                s[tmp[i]->xoffset] = '|';
            if (tmp[i]->left!=NULL)
            {
                for (int j = tmp[i]->left->xoffset; j < tmp[i]->xoffset; j++)
                    s[j] = '_';
            }
            if (tmp[i]->right!=NULL)
            {
                for (int j = tmp[i]->xoffset+1 ;j <= tmp[i]->right->xoffset;j++)
                    s[j] = '_';

            }
        }
        cout<<s<<endl;
        s.assign(tmp[tmp.size()-1]->xoffset+10,' ');
        for (int i = 0;i < tmp.size();i++)
        {
            if(tmp[i]->left!=NULL)
                s[tmp[i]->left->xoffset] = '|';
            if (tmp[i]->right!=NULL)
                s[tmp[i]->right->xoffset] = '|';
        }
        cout<<s<<endl;
    }

}

template <class T>
void BinaryTree<T>::setx()
{
    TreeNode<T> * t = root;
    stack<TreeNode<T> *> s;
    int i = 1;
    while (t!=NULL||!s.empty())
    {
        if (t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {//cout<<1;
            t = s.top();
            s.pop();
            t->xoffset = i;
            i++;
            t = t->right;
        }
    }

}

template <class T>
vector< vector<TreeNode<T> *> > BinaryTree<T>::sety()
{
    queue<TreeNode<T> *> q;
    vector< vector<TreeNode<T> *> > result;
    //int i =0;
    if(root ==NULL)
        return result;
    vector<TreeNode<T>*> tmp;
    q.push(root);
    q.push(NULL);
    do{
        TreeNode<T> * t=q.front();
        q.pop();
        if (t!=NULL)
        {
            tmp.push_back(t);
           // t->yoffset = i;
            if(t->left !=NULL)
                q.push(t->left);
            if(t->right !=NULL)
                q.push(t->right);
        }
        else
        {
            result.push_back(tmp);
            if (!q.empty())
            {

                q.push(NULL);
               // i++;
                tmp.clear();
            }
        }
    }while (!q.empty());
    return result;
}
#endif // BINARYTREE_H_INCLUDED
