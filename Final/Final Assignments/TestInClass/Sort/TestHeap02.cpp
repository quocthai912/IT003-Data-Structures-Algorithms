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

void Heapify(vector<int> &A, int size, int &count, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && A[left] > A[largest])
        largest = left;
    if (right < size && A[right] > A[largest])
        largest = right;
    if (i != largest)
    {
        count++;
        swap(A[i], A[largest]);
        Heapify(A, size, count, largest);
    }
}

void BuildMaxHeap(vector<int> &A, int &count)
{
    for (int i = (A.size() - 1) / 2; i >= 0; i--)
    {
        Heapify(A, A.size(), count, i);
    }
}

void SAPXEP(vector<int> &A)
{
    int count = 0;
    cout << "N=" << A.size() << ": ";
    for (int k = 0; k < A.size(); k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    BuildMaxHeap(A, count);
    cout << "swap: " << count << endl
         << endl;
    for (int i = A.size() - 1; i > 0; i--)
    {
        count = 0;
        cout << "N=" << i << ": ";
        swap(A[i], A[0]);
        for (int k = 0; k < A.size(); k++)
        {
            cout << A[k] << " ";
        }
        Heapify(A, i, count, 0);
        cout << endl;
        cout << "swap: " << count << endl
             << endl;
    }
}

int main()
{
    vector<int> A;
    Input(A);
    SAPXEP(A);
    return 0;
}
