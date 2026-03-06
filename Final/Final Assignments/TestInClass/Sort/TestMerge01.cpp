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
vector<int> temp;

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

void Merge(vector<int> &A, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (A[i] >= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= right)
        temp[k++] = A[j++];
    for (int m = left; m <= right; m++)
    {
        A[m] = temp[m];
    }
}

void MergeSort(vector<int> &A)
{
    for (int k = 1; k < A.size(); k *= 2)
    {
        cout << "--------------" << endl;
        cout << "K=" << k << ":" << endl;
        for (int left = 0; left < A.size() - 1; left += 2 * k)
        {
            int size = A.size();
            int mid = min((left + k) - 1, size - 1);
            int right = min((left + 2 * k) - 1, size - 1);
            if (mid < right)
                Merge(A, left, mid, right);
        }
        cout << "A: ";
        for (int n = 0; n < A.size(); n++)
        {
            cout << A[n];
            if (n != A.size() - 1)
                cout << "-";
        }
        cout << endl;
    }
}

void SAPXEP(vector<int> &A)
{
    if (A.size() == 0)
    {
        cout << "Empty";
        return;
    }
    temp.resize(A.size());
    MergeSort(A);
}

int main()
{
    vector<int> A;
    Input(A);
    SAPXEP(A);
    return 0;
}
