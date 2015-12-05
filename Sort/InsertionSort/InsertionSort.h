#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

template<class T>
void InsertionSort(T *A ,int n)
{
    int j, p;
    T tmp;
    for (p=1; p<n; p++)
    {
        tmp = A[p];
        for (j=p; j>0&&A[j-1]>tmp; j--)
            A[j] = A[j-1];
        A[j] = tmp;
    }
}

#endif // INSERTIONSORT_H_INCLUDED
