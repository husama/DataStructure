#include <iostream>
#include "ShellSort.h"
using namespace std;

int main()
{
    int A[10] ={1,21,15,261,627,16,273,26,3726,26};
    ShellSort(A,10);
    for (int i=0;i<10;i++)
        cout<<A[i]<<endl;
    return 0;
}
