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
void heapify(vector<int> &A, int size, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && A[left] < A[min])
    {
        min = left;
    }
    if (right < size && A[right] < A[min])
    {
        min = right;
    }
    if (min != i)
    {
        swap(A[min], A[i]);
        heapify(A, size, min);
    }
}
void buildMinHeap(vector<int> &A, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(A, size, i);
    }
}
void heapSort(vector<int> &A, int size)
{
    buildMinHeap(A, size);
    cout << "buildHeap: ";
    for (int i = 0; i < size; i++)
    {
        cout << A[i];
        if (i != size - 1)
            cout << "-";
    }
    cout << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << "n=" << i << ": ";
        swap(A[i], A[0]);
        heapify(A, i, 0);
        for (int j = 0; j < size; j++)
        {
            cout << A[j];
            if (j != size - 1)
                cout << "-";
        }
        cout << endl;
    }
}
void Sort(vector<int> &A)
{
    if (A.size() == 0)
    {
        cout << "Empty";
    }
    else
    {
        heapSort(A, A.size());
    }
}
int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
