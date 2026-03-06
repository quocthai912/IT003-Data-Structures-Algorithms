/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
    int tmp;
    cin >> tmp;
    while (tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
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
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (left != right)
    {
        cout << "Phan hoach doan left=" << left << " - right=" << right << " - pivot=" << pivot << ":" << endl;
        for (int k = 0; k < A.size(); k++)
            cout << A[k] << " ";
        cout << endl;
    }
    QuickSort(A, left, j);
    QuickSort(A, i, right);
}
void Sort(vector<int> &A)
{
    QuickSort(A, 0, A.size() - 1);
}
int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
