#include <bits/stdc++.h>
using namespace std;
void Input(vector<int> &A)
{
    int temp = -2;
    while (temp != -1)
    {
        cin >> temp;
        if (temp != -1)
            A.push_back(temp);
    }
}
bool checkTangDan(vector<int> A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}
bool checkGiamDan(vector<int> A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] < A[i + 1])
            return false;
    }
    return true;
}
void binarySearchTangDan(vector<int> A, int target)
{
    int left = 0;
    int right = A.size() - 1;
    while (left <= right)
    {
        cout << "[" << left << "-" << right << "]";
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            cout << endl << mid;
            return;
        }
        else if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "[" << left << "-" << right << "]";
    cout << endl << "NotFound";
}
void binarySearchGiamDan(vector<int> A, int target)
{
    int left = 0;
    int right = A.size() - 1;
    while (left <= right)
    {
        cout << "[" << left << "-" << right << "]";
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            cout << endl << mid;
            return;
        }
        else if (A[mid] > target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "[" << left << "-" << right << "]";
    cout << endl << "NotFound";
}
void Find(vector<int> A)
{
    if (!checkTangDan(A) && !checkGiamDan(A))
    {
        cout << "Invalid";
        return;
    }
    int target;
    cin >> target;
    if (checkTangDan(A))
        binarySearchTangDan(A, target);
    else
        binarySearchGiamDan(A, target);
}
int main()
{
    vector<int> A;
    Input(A);
    Find(A);
    return 0;
}
