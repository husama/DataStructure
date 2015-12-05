#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

template <class T>
void ShellSort(T *A, int n)
{
    int i, j, Increment;
    T tmp;
    for (Increment = n/2; Increment > 0; Increment/=2)
    {
        for (i = Increment; i<n; i++)
        {
            tmp = A[i];
            for (j = i; j >= Increment; j-=Increment)
            {
                if (A[j-Increment] > tmp)
                    A[j] = A[j-Increment];
                else
                    break;
            }
            A[j] = tmp;
        }
    }
}

#endif // SHELLSORT_H_INCLUDED
