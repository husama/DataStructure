#ifndef RADIXSORT_H_INCLUDED
#define RADIXSORT_H_INCLUDED
#include <cmath>
int maxDigit(int * A ,int n)
{
    int tmp = A[0], m = 0;
    for ( int i = 0 ; i < n; i++)
    {
        if ( A[i] > tmp)
        {
            tmp = A[i];
        }
    }
    m = int(log10(tmp)+1);
    return m;
}

void RadixSort(int * A ,int n)
{
    int d = maxDigit(A,n);
    int* tmp = new int[n];
    int* count = new int[10];
    int radix = 1, j, k, i;
    for (i = 1; i <= d; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            count[j] = 0;
        }
        for ( j = 0; j < n; j++ )
        {;
            k = (A[j]/radix)%10;
            count[k]++;
        }
        for ( j = 1; j < n; j++ )
        {
            count[j] += count[j-1];
        }
        for ( j = n-1; j>= 0; j-- )
        {
            k = (A[j]/radix)%10;
            tmp[count[k]-1] = A[j];
            count[k]--;
        }
        for ( j = 0; j < n; j++ )
        {
            A[j] = tmp[j];
        }
        radix *= 10;
    }
    delete[] tmp;
    delete[] count;
}

#endif // RADIXSORT_H_INCLUDED
