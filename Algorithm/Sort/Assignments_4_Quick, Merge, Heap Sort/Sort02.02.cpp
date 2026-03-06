/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge(int input[], int left, int mid, int right)
{
    int sizeLeft = (mid - left) + 1;
    int sizeRight = (right - mid);
    int arrayLeft[sizeLeft], arrayRight[sizeRight];
    for (int i = 0; i < sizeLeft; i++)
    {
        arrayLeft[i] = input[left + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        arrayRight[i] = input[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight)
    {
        if (arrayLeft[i] <= arrayRight[j])
        {
            input[k++] = arrayLeft[i++];
        }
        else
        {
            input[k++] = arrayRight[j++];
        }
    }
    while (i < sizeLeft)
    {
        input[k++] = arrayLeft[i++];
    }
    while (j < sizeRight)
    {
        input[k++] = arrayRight[j++];
    }
}

void mergeSortRange(int input[], int from, int to)
{
    if (from < to)
    {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n)
{
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N)
{
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
