#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int B[MAX], C[MAX];
void Input(int A[], int &N)
{
    N = 0;
    int temp = 0;
    while (temp != -1)
    {
        cin >> temp;
        if (temp != -1)
            A[N++] = temp;
    }
}
void merge(int A[], int nB, int nC, int k)
{
    int pA, pB, pC, iB, iC, kB, kC;
    pA = pB = pC = iB = iC = 0;
    kB = min(k, nB);
    kC = min(k, nC);
    while (nB > 0 && nC > 0)
    {
        if (B[pB + iB] >= C[pC + iC])
        {
            A[pA++] = B[pB + iB];
            iB++;
            if (iB == kB)
            {
                for (; iC < kC; iC++)
                {
                    A[pA++] = C[pC + iC];
                }
                pB += iB;
                pC += iC;
                iB = 0;
                iC = 0;
                nB -= kB;
                nC -= kC;
                kB = min(k, nB);
                kC = min(k, nC);
            }
        }
        else
        {
            A[pA++] = C[pC + iC];
            iC++;
            if (iC == kC)
            {
                for (; iB < kB; iB++)
                {
                    A[pA++] = B[pB + iB];
                }
                pB += iB;
                pC += iC;
                iB = 0;
                iC = 0;
                nB -= kB;
                nC -= kC;
                kB = min(k, nB);
                kC = min(k, nC);
            }
        }
    }
}
void mergeSort(int A[], int size)
{
    int pA, pB, pC, k = 1;
    while (k < size)
    {
        pA = pB = pC = 0;
        while (pA < size)
        {
            for (int i = 0; pA < size && i < k; i++)
            {
                B[pB++] = A[pA++];
            }
            for (int i = 0; pA < size && i < k; i++)
            {
                C[pC++] = A[pA++];
            }
        }
        merge(A, pB, pC, k);
        cout << "K=" << k << ":" << endl;
        cout << "A: ";
        for (int i = 0; i < pA; i++)
        {
            cout << A[i];
            if (i != pA - 1)
            {
                cout << "-";
            }
        }
        cout << endl;
        k *= 2;
    }
}
void Sort(int A[], int N)
{
    if (N == 0)
    {
        cout << "Empty";
    }
    else
    {
        mergeSort(A, N);
    }
}
int main()
{
    int A[MAX], N;
    Input(A, N);
    Sort(A, N);
    return 0;
}
