/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

void XuatMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;
}
#define MAXN 100000
using namespace std;
void NhapMang(int A[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
void HoanVi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void selectionSortGiamDan(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] > A[maxIndex])
                maxIndex = j;
        }
        if (A[i] < A[maxIndex])
            HoanVi(A[i], A[maxIndex]);
    }
}
void insertionSortTangDan(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
void SapXepSoDuongGiamAmTangVa0(int A[], int n)
{
    int sizeMangDuong = 0;
    int sizeMangAm = 0;
    int sizeMang0 = 0;
    int mangDuong[MAXN];
    int mangAm[MAXN];
    int mang0[MAXN];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
            mangDuong[sizeMangDuong++] = A[i];
        else if (A[i] < 0)
            mangAm[sizeMangAm++] = A[i];
        else
            mang0[sizeMang0++] = A[i];
    }
    selectionSortGiamDan(mangDuong, sizeMangDuong);
    insertionSortTangDan(mangAm, sizeMangAm);
    int k = 0;
    for (int i = 0; i < sizeMangDuong; i++)
    {
        A[k++] = mangDuong[i];
    }
    for (int i = 0; i < sizeMangAm; i++)
    {
        A[k++] = mangAm[i];
    }
    for (int i = 0; i < sizeMang0; i++)
    {
        A[k++] = mang0[i];
    }
}
int main()
{
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoDuongGiamAmTangVa0(a, n);
    XuatMang(a, n);
    return 0;
}
