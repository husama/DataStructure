/******
author: huxiangming
e-mail: husama@qq.com
blog: husama.com
******/
#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AVL<int> tree;
    tree.Insert(6);
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(4);
    tree.Insert(3);
    tree.Delete(3);
    tree.Insert(5);
    cout<<"层次遍历:"<<endl;
    tree.LevelOrder();
    cout<<"前序遍历:"<<endl;
    tree.PreOrder();
    cout<<"中序遍历:"<<endl;
    tree.InOrder();
    return 0;
}
