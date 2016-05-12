/******
author: huxiangming
e-mail: husama@qq.com
blog: husama.com
******/
#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <iostream>
#include <queue>
using namespace std;
template <class ElementType>
struct TreeNode
{
	ElementType val;//Data
	TreeNode *left;
	TreeNode *right;
	int height;
};

template <class ElementType>
class AVL
{
public:
	AVL(){root = NULL;}//构造函数，创建一个空的AVL树
	~AVL();
	bool Insert(ElementType val);//插入成功返回true
	void Delete(ElementType val);//删除成功返回true
	void PreOrder();//前序遍历
	void LevelOrder();//层次遍历;
	void InOrder();//中序遍历
private:
    TreeNode<ElementType> * root;
    TreeNode<ElementType> *FindMin(TreeNode<ElementType> *t);
    int Height(TreeNode<ElementType> *t);//t指向的树的层数(高度)
    TreeNode<ElementType> *SingleRotateWithLeft(TreeNode<ElementType> *t);//单旋转(左)
    TreeNode<ElementType> *DoubleRotateWithLeft(TreeNode<ElementType> *t);//双旋转(左)
    TreeNode<ElementType> *SingleRotateWithRight(TreeNode<ElementType> *t);//单旋转(右)
    TreeNode<ElementType> *DoubleRotateWithRight(TreeNode<ElementType> *t);//双旋转(右)
    TreeNode<ElementType> *_Insert(ElementType val, TreeNode<ElementType> *t);//封装AVL树的Insert操作
    TreeNode<ElementType> *_Delete(ElementType val, TreeNode<ElementType> *t);//封装AVL树的Delete操作
    void MakeEmpty(TreeNode<ElementType> *t);
    void _PreOrder(TreeNode<ElementType> *t);//封装前序遍历
    void _InOrder(TreeNode<ElementType> *t);//封装中序遍历
};

template<class ElementType>
void AVL<ElementType>::MakeEmpty(TreeNode<ElementType> *t)
{
    if ( t !=NULL)
    {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        delete t;
    }
}

template<class ElementType>
AVL<ElementType>::~AVL()
{
	MakeEmpty(root);
}

template <class ElementType>
int AVL<ElementType>::Height(TreeNode<ElementType> *t)
{
    if ( t == NULL)
        return -1;
    else
        return t->height;
}

template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::FindMin(TreeNode<ElementType> *t)
{
    if  (t != NULL)
        while (t->left!=NULL)
            t=t->left;
    return t;
}

template<class ElementType>
void AVL<ElementType>::PreOrder()
{
	_PreOrder(root);
	cout<<endl;
}

template<class ElementType>
void AVL<ElementType>::InOrder()
{
	_InOrder(root);
	cout<<endl;
}

template<class ElementType>
void AVL<ElementType>::_PreOrder(TreeNode<ElementType> *t)
{
	if (t ==NULL)
        return;
    cout<<t->val<<" "<<"height:"<<t->height<<endl;
    _PreOrder(t->left);
    _PreOrder(t->right);
}

template<class ElementType>
void AVL<ElementType>::_InOrder(TreeNode<ElementType> *t)
{
	if (t ==NULL)
        return;
    _InOrder(t->left);
    cout<<t->val<<" "<<"height:"<<t->height<<endl;
    _InOrder(t->right);
}

template<class ElementType>
void AVL<ElementType>::LevelOrder()
{
    queue<TreeNode<ElementType>*> q;
	TreeNode<ElementType> *t;
	t=root;
	q.push(t);
	while (!q.empty() ){
        t=q.front();
        q.pop();
        cout<<t->val<<" "<<"height:"<<t->height<<endl;
        if (t->left)
            q.push( t->left);
        if (t->right)
            q.push(t->right);
	}
}

template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::SingleRotateWithLeft(TreeNode<ElementType> *t )
{
    TreeNode<ElementType> * result;
    result = t->left;
    t->left = result->right;
    result->right = t;
    t->height = (Height(t->left)>Height(t->right)?Height(t->left):Height(t->right))+1;
    result->height = (Height(result->left)>t->height?Height(t->left):t->height)+1;
    return result;
}

template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::SingleRotateWithRight(TreeNode<ElementType> *t )
{
    TreeNode<ElementType> * result;
    result = t->right;
    t->right = result->left;
    result->left = t;
    t->height = ( Height(t->left) > Height(t->right) ? Height(t->left) : Height(t->right) )+1;
    result->height = ( Height(result->right) > t->height ? Height(t->right) : t->height )+1;
    return result;
}
template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::DoubleRotateWithLeft(TreeNode<ElementType> *t )
{
    t->left = SingleRotateWithRight(t->left);
    return SingleRotateWithLeft(t);
}

template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::DoubleRotateWithRight(TreeNode<ElementType> *t )
{
    t->right = SingleRotateWithLeft(t->right);
    return SingleRotateWithRight(t);
}

template <class ElementType>
bool AVL<ElementType>::Insert(ElementType val)
{
    if ( (root = _Insert(val,root)) )
        return true;
    else
        return false;
}

template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::_Insert(ElementType val, TreeNode<ElementType> *t)
{
    if (t == NULL)
    {
        //cout<<"insert"<<endl;
        t = new TreeNode<ElementType>;
        t->left = t->right =NULL;
        t->val = val;
        t->height = 0;
    }
    else
    if ( val < t->val )
    {
        t->left = _Insert(val,t->left);
        if (Height(t->left)-Height(t->right)==2)
        {
            if ( val < t->left->val)
                t = SingleRotateWithLeft(t);
            else
                t = DoubleRotateWithLeft(t);
        }
    }
    else
    if ( val > t->val )
    {
        t->right = _Insert(val,t->right);
        if (Height(t->right)-Height(t->left)==2)
        {
            if ( val < t->right->val)
                t = DoubleRotateWithRight(t);
            else
                t = SingleRotateWithRight(t);
        }
    }
    t->height = (Height(t->left)>Height(t->right)?Height(t->left):Height(t->right))+1;
    return t;
}
template <class ElementType>
void AVL<ElementType>::Delete(ElementType val)
{
    _Delete( val ,root );
}
template <class ElementType>
TreeNode<ElementType> *AVL<ElementType>::_Delete(ElementType val, TreeNode<ElementType> *t)
{
    TreeNode<ElementType> *tmp;
    if ( t == NULL)
        cout<<"ERROR: THE ELEMENT NOT FOUND!"<<endl;
    else
    if ( val < t->val )
    {
        t->left = _Delete(val, t->left);
        if (Height(t->right)-Height(t->left)==2)
        {
            if ( val < t->right->val)
                t = DoubleRotateWithRight(t);
            else
                t = SingleRotateWithLeft(t);
        }
    }
    else
    if ( val > t->val )
    {
        t->right = _Delete(val, t->right);
        if (Height(t->left)-Height(t->right)==2)
        {
            if ( val < t->left->val)
                t = SingleRotateWithLeft(t);
            else
                t = DoubleRotateWithLeft(t);
        }
    }
    else
    if ( t->left != NULL && t->right != NULL)
    {
        tmp = FindMin( t );
        t->val = tmp->val;
        t->right = _Delete(t->val , t->right);
        if (Height(t->left)-Height(t->right)==2)
        {
            if ( val < t->left->val)
                t = SingleRotateWithLeft(t);
            else
                t = DoubleRotateWithLeft(t);
        }
    }
    else
    {
        tmp = t;
        if ( t->left == NULL)
            t = t->left;
        else
            t = t->right;
        delete tmp;
    }
    return t;
}
#endif // AVL_H_INCLUDED
