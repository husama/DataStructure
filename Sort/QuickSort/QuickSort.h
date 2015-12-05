#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

template <class T>
int Partition(T* A, int p, int r)
{
    T x = A[r], tmp;
    int i, j;
    i = p - 1;
    for ( j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;
}

template <class T>
void QuickSort(T *A, int p, int r)
{
    if ( p < r )
    {
        int q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
template <class T>
void qsort2(T *A, int n)
{
    QuickSort(A,0,n-1);
}

template <class T>
void qsort(T *A, int n)
{
    if (n<=1) return;
    T mid = A[n-1];
    T tmp;
    int i = -1, j = 0;
    while ( j < n-1 )
    {
        if (A[j] <= mid)
        {
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        j++;
    }
    i++;
    tmp = A[i];
    A[i] = A[n-1];
    A[n-1] = tmp;
    qsort(A,i);
    qsort(A+i+1,n-i-1);
}

#endif // QUICKSORT_H_INCLUDED
