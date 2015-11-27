#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    int n;
    tree.Create('#');
    cout<<"您创造的树如下：\n";
    tree.printTree();

    while (1)
    {   cout<<"\n1.前序遍历\n2.中序遍历\n3.后序遍历\n4.层次遍历\n5.检查是否完全二叉树\n6.搜索二叉树中符合数据域条件的结点\n7.搜索某个数据的父节点\n0.退出程序！\n ";
        cout<<"input:";
        cin>>n;
        switch (n)
        {
        case 1:
            tree.preOrder();
            cout<<endl;
            break;
        case 2:
            tree.inOrder();
            cout<<endl;
            break;
        case 3:
            tree.postOrder();
            cout<<endl;
            break;
        case 4:
            tree.levelOrder();
            cout<<endl;
            break;
        case 5:
            if (tree.isCompleteBinaryTree())
                cout<<"此二叉树是完全二叉树\n";
            else
                cout<<"此二叉树不是完全二叉树\n";
            break;
        case 6:
            cout<<"请输入您想要搜索的数据：";
            char item;
            cin>>item;
            if(tree.Search(item))
                cout<<"此二叉树有数据为"<<item<<"的结点";
            else
                cout<<"此二叉树没有数据为"<<item<<"的结点";
            break;
        case 7:
            cout<<"请输入您想要搜索父节点的数据：";
            cin>>item;
            tree.Father(item);
            break;

        case 0:
            return 0;
        }
    }
    return 0;
}
