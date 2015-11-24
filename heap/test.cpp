#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    heap<int> h;
    int tmp,n;
    cin>>n;
    for (int i =n;i>0;i--)
    {
        cout<<"input:";
        cin>>tmp;
        h.Insert(tmp);
    }

    for (int i =n;i>0;i--)
        cout<<h.DeleteMin()<<endl;
    return 0;
}
