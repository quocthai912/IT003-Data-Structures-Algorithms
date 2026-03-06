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
void QuickSort(vector<int> &A, int left, int right, int &count)
{
    if (left >= right)
        return;
    int pivot = A[(left + right) / 2];
    int i = left;
    int j = right;
    if (left != right)
        count++;
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
    QuickSort(A, left, j, count);
    QuickSort(A, i, right, count);
}
void Sort(vector<int> &A)
{
    int result = 0;
    QuickSort(A, 0, A.size() - 1, result);
    cout << result;
}

int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
