#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<char> tree;
    int n;
    tree.Create('#');
    cout<<"������������£�\n";
    tree.printTree();

    while (1)
    {   cout<<"\n1.ǰ�����\n2.�������\n3.�������\n4.��α���\n5.����Ƿ���ȫ������\n6.�����������з��������������Ľ��\n7.����ĳ�����ݵĸ��ڵ�\n0.�˳�����\n ";
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
                cout<<"�˶���������ȫ������\n";
            else
                cout<<"�˶�����������ȫ������\n";
            break;
        case 6:
            cout<<"����������Ҫ���������ݣ�";
            char item;
            cin>>item;
            if(tree.Search(item))
                cout<<"�˶�����������Ϊ"<<item<<"�Ľ��";
            else
                cout<<"�˶�����û������Ϊ"<<item<<"�Ľ��";
            break;
        case 7:
            cout<<"����������Ҫ�������ڵ�����ݣ�";
            cin>>item;
            tree.Father(item);
            break;

        case 0:
            return 0;
        }
    }
    return 0;
}
