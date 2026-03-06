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
vector<int> B;
vector<int> C;
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
    int k = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= right)
        temp[k++] = A[j++];
    for (int m = left; m <= right; m++)
        A[m] = temp[m];
}

void MergeSort(vector<int> &A)
{
    for (int k = 1; k < A.size(); k *= 2)
    {
        cout << "--------------" << endl;
        int pA = 0;
        cout << "K=" << k << ":" << endl;
        while (pA < A.size())
        {
            for (int i = 0; i < k; i++)
            {
                if (pA < A.size())
                    B.push_back(A[pA++]);
            }
            for (int j = 0; j < k; j++)
            {
                if (pA < A.size())
                    C.push_back(A[pA++]);
            }
        }
        for (int left = 0; left < A.size() - 1; left += 2 * k)
        {
            int size = A.size();
            int mid = min((left + k) - 1, size - 1);
            int right = min((left + 2 * k) - 1, size - 1);
            if (mid < right)
                Merge(A, left, mid, right);
        }
        cout << "B: ";
        for (int i = 0; i < B.size(); i++)
        {
            cout << B[i];
            if (i != B.size() - 1)
                cout << "-";
        }
        cout << endl;
        cout << "C: ";
        for (int j = 0; j < C.size(); j++)
        {
            cout << C[j];
            if (j != C.size() - 1)
                cout << "-";
        }
        cout << endl;
        B.clear();
        C.clear();
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
