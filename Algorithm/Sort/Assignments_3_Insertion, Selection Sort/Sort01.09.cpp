/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
int Input()
{
    int n;
    cin >> n;
    return n;
}
void NhapMang(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
void SapXepSoChanGiamDan(int A[], int n)
{
    vector<int> mangSoChan;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
            mangSoChan.push_back(A[i]);
    }
    sort(mangSoChan.begin(), mangSoChan.end(), greater<int>());
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            A[i] = mangSoChan[k++];
        }
    }
}
void XuatMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main()
{
    int a[MAXN], n;
    n = Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
