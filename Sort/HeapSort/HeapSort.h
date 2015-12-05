#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#define parent(i) ((i - 1) / 2)
#define left(i)   (2 * i + 1)
#define right(i)  (2 * i + 2)

template <class T>
void maxHeapify(T *A, int i, int heapsize)
{
    int l, r, largest;
    T tmp;
    while (1)
    {
        l = left(i), r = right(i);
        if ( l < heapsize && A[l] > A[i] )
            largest = l;
        else
            largest = i;
        if ( r < heapsize && A[r] > A[largest] )
            largest = r;
        if ( i == largest )
            return;

        tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;

        i = largest;
    }
}

template <class T>
void buildMaxHeap( T *A ,int n)
{
    for ( int i = (n-1)/2; i >= 0; i-- )
    {
        maxHeapify(A,i,n);
    }
}

template <class T>
void HeapSort(T* A, int n)
{
    T tmp;
    buildMaxHeap(A,n);
    for(int i = n-1; i > 0; i-- )
    {
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        maxHeapify(A,0,i);
    }
}


#endif // HEAPSORT_H_INCLUDED
