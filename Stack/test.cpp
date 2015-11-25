#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> s;
    int tmp, n;
    cout<<"您创建了一个空栈\n";
    while (1)
    {
        cout<<"1.入栈\n2.出栈\n3.只输出栈顶元素，不出栈\n4.输出栈所有元素\n0.退出程序\n";
        cout<<"请输入您想要对栈进行的操作：";
        cin>>n;
        switch (n)
        {
            case 1: if (s.isFull())
                        cout<<"\n栈已满，无法入栈\n\n";
                    else
                    {
                        cout<<"\n请输入您想要入栈的值（整数）：";
                        cin>>tmp;
                        s.push(tmp);
                        cout<<"\n操作完成\n\n";
                    }
                    break;
            case 2: if (s.isEmpty())
                        cout<<"\n栈为空，无法出栈\n\n";
                    else
                    {
                        tmp = s.pop();
                        cout<<"\n出栈的元素是"<<tmp<<endl;
                        cout<<"\n操作完成\n\n";
                    }
                    break;
            case 3: if (s.isEmpty())
                        cout<<"\n栈为空\n\n";
                    else
                    {
                        tmp = s.top();
                        cout<<"\n栈顶元素是"<<tmp<<endl;
                        cout<<"\n操作完成\n\n";
                    }
                    break;
            case 4: if (s.isEmpty())
                        cout<<"\n栈为空\n\n";
                    else
                    {
                        cout<<"\n栈所有的元素如下：\n";
                        s.print();
                        cout<<endl<<endl;
                    }
                    break;
            case 0: return 0;
        }

    }
    return 0;
}
