/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
void NhapMang(int A[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
void SapXepSoAmTangDan(int A[], int n)
{
    vector<int> mangSoAm;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
            mangSoAm.push_back(A[i]);
    }
    sort(mangSoAm.begin(), mangSoAm.end());
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            A[i] = mangSoAm[k++];
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
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
