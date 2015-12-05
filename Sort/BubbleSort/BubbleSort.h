#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

template <class T>
void BubbleSort(T *a, int n)
{
    int i, j;
    T tmp;
    for(i=n-1; i>=0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(a[j]>a[j+1])
            {
                tmp = a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }

}

template <class T>
void BubbleSort2(T *A, int n)
{
    int i;
    T tmp;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (i = 0; i < n-1; i++ )
            if (A[i] > A[i+1])
            {
                tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                flag = true;
            }
    }

}

template <class T>
void BubbleSort3(T * a, int n)
{
    int i,t,bound=n-1;
    T tmp;
    while (bound!=0)
    {
        t = 0;
        for (i=0;i < bound;i++)
            if(a[i]>a[i+1])
            {
                tmp = a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                t=i;
            }
        bound = t;
    }
}
#endif // BUBBLESORT_H_INCLUDED
