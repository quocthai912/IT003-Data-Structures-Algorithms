/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
void NhapMang(int A[], int &n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
void selection_sort_ascending(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        if (A[i] > A[minIndex])
            swap(A[i], A[minIndex]);
    }
}
bool is_ascending(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_sort_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
