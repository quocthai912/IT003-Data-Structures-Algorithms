#include <bits/stdc++.h>
using namespace std;
int MAX = 100;
bool checkTangDan(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}
bool checkGiamDan(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] < A[i + 1])
            return false;
    }
    return true;
}
void binarySearchTangDan(int A[], int N, int target)
{
    int left = 0;
    int right = N - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            cout << mid;
            return;
        }
        else if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "NotFound";
}
void binarySearchGiamDan(int A[], int N, int target)
{
    int left = 0;
    int right = N - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            cout << mid;
            return;
        }
        else if (A[mid] > target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "NotFound";
}
void Input(int A[], int &N)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
}
void Find(int A[], int N)
{
    if (!checkTangDan(A, N) && !checkGiamDan(A, N))
    {
        cout << "Invalid";
        return;
    }
    int target;
    cin >> target;
    if (checkTangDan(A, N))
        binarySearchTangDan(A, N, target);
    else
        binarySearchGiamDan(A, N, target);
}
int main()
{
    int A[MAX], N;
    Input(A, N);
    Find(A, N);
    return 0;
}
