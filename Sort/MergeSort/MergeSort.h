#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

template <class T>
void Merge( T *A , int p, int q, int r)
{
    T *L = new T[q-p+1];
    T *R = new T[r-q];
    int i, j;
    for ( i = 0; i < q-p+1; i++ )
        L[i] = A[p+i];
    for ( j = 0; j < r-q; j++)
        R[j] = A[q+j+1];
    i = j = 0;
    int k = p;
    while ( i < q-p+1 && j< r-q )
    {
        if ( L[i] < R[j])
        {
            A[k] = L[i];
            i++;
            k++;
        }
        else
        {
            A[k] = R[j];
            j++;
            k++;
        }
    }
    while ( i < q-p+1 )
    {
        A[k] =  L[i];
        i++;
        k++;
    }
    while ( j < r-q )
    {
        A[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

template <class T>
void MSort(T *A , int Begin, int End)
{
    if ( Begin <  End)
    {
        int mid = (Begin+End)/2;
        MSort(A,Begin,mid);
        MSort(A,mid+1,End);
        Merge(A,Begin,mid,End);
    }
}

template <class T>
void MergeSort(T *A, int n)
{
    MSort(A,0,n-1);
}
#endif // MERGESORT_H_INCLUDED
