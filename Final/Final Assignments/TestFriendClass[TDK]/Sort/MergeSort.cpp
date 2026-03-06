// Merge Sort
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A, int left, int mid, int right)
{
    int sizeLeft = (mid - left) + 1;
    int sizeRight = right - mid;
    vector<int> arrayLeft(sizeLeft);
    vector<int> arrayRight(sizeRight);
    for (int i = 0; i < sizeLeft; i++)
    {
        arrayLeft[i] = A[left + i];
    }
    for (int j = 0; j < sizeRight; j++)
    {
        arrayRight[j] = A[j + mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight)
    {
        if (arrayLeft[i] < arrayRight[j])
            A[k++] = arrayLeft[i++];
        else
            A[k++] = arrayRight[j++];
    }
    while (i < sizeLeft)
        A[k++] = arrayLeft[i++];
    while (j < sizeRight)
        A[k++] = arrayRight[j++];
    for (int i = 0; i < A.size(); i++)
    {
        if (i == left)
            cout << "[ ";
        cout << A[i] << " ";
        if (i == right)
            cout << "] ";
    }
    cout << endl;
}

void MergeSort(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid + 1, right);
    Merge(A, left, mid, right);
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    MergeSort(A, 0, A.size() - 1);
    return 0;
}
