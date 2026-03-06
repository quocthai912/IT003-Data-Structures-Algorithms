/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        A.push_back(key);
        cin >> key;
    }
}

void QuickSort(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;
    int pivot = A[left + (right - left) / 2];
    cout << "[" << left << " - " << right << "]: pivot=" << pivot << endl;
    int i = left;
    int j = right;
    while (i < j)
    {
        while (A[i] > pivot)
            i++;
        while (A[j] < pivot)
            j--;
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    QuickSort(A, left, j);
    QuickSort(A, i, right);
}

void SAPXEP(vector<int> &A)
{
    QuickSort(A, 0, A.size() - 1);
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    vector<int> A;
    Input(A);
    SAPXEP(A);
    return 0;
}
