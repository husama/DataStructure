#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> s;
    int tmp, n;
    cout<<"��������һ����ջ\n";
    while (1)
    {
        cout<<"1.��ջ\n2.��ջ\n3.ֻ���ջ��Ԫ�أ�����ջ\n4.���ջ����Ԫ��\n0.�˳�����\n";
        cout<<"����������Ҫ��ջ���еĲ�����";
        cin>>n;
        switch (n)
        {
            case 1: if (s.isFull())
                        cout<<"\nջ�������޷���ջ\n\n";
                    else
                    {
                        cout<<"\n����������Ҫ��ջ��ֵ����������";
                        cin>>tmp;
                        s.push(tmp);
                        cout<<"\n�������\n\n";
                    }
                    break;
            case 2: if (s.isEmpty())
                        cout<<"\nջΪ�գ��޷���ջ\n\n";
                    else
                    {
                        tmp = s.pop();
                        cout<<"\n��ջ��Ԫ����"<<tmp<<endl;
                        cout<<"\n�������\n\n";
                    }
                    break;
            case 3: if (s.isEmpty())
                        cout<<"\nջΪ��\n\n";
                    else
                    {
                        tmp = s.top();
                        cout<<"\nջ��Ԫ����"<<tmp<<endl;
                        cout<<"\n�������\n\n";
                    }
                    break;
            case 4: if (s.isEmpty())
                        cout<<"\nջΪ��\n\n";
                    else
                    {
                        cout<<"\nջ���е�Ԫ�����£�\n";
                        s.print();
                        cout<<endl<<endl;
                    }
                    break;
            case 0: return 0;
        }

    }
    return 0;
}
