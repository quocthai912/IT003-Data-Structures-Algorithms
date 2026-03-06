#include <bits/stdc++.h>
using namespace std;
void Input(vector<int> &A)
{
    int temp = 0;
    while (temp != -1)
    {
        cin >> temp;
        if (temp != -1)
            A.push_back(temp);
    }
}
void QuickSort(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;
    int pivot = A[(left + right) / 2];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (A[i] > pivot)
        {
            i++;
        }
        while (A[j] < pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (left != right)
    {
        cout << "[" << left << "-" << right << "]: ";
        for (int k = 0; k < A.size(); k++)
        {
            cout << A[k];
            if (k != A.size() - 1)
                cout << "-";
        }
        cout << endl;
    }
    QuickSort(A, left, j);
    QuickSort(A, i, right);
}
void Sort(vector<int> &A)
{
    if (A.size() == 0)
    {
        cout << "Empty";
    }
    else
    {
        QuickSort(A, 0, A.size() - 1);
    }
}
int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
