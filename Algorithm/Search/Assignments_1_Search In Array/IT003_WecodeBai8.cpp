/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_last_occurrence(int A[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int find = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            find = mid;
            left = mid + 1;
        }
        else if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return find;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}