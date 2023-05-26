#include <stdio.h>
#include <stdlib.h>

void ShellSort(ElemType A[], int n)
{
    for (int dk = n / 2; dk >= 1; dk = dk / 2)
        for (int i = dk + 1; i <= n; ++i)
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                int j;
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk)
                    A[j + dk] = A[j];
                A[j + dk] = A[0];
            }
}