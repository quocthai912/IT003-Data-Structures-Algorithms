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
    if (left < right)
    {
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
        QuickSort(A, left, j);
        QuickSort(A, i, right);
    }
    if (left == 0 && right == A.size() - 1)
    {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << " ";
    }
}

int main()
{
    vector<int> A;
    Input(A);
    QuickSort(A, 0, A.size() - 1);
    return 0;
}
