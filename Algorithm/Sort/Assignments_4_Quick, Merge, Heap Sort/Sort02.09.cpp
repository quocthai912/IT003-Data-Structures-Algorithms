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

void heapify(vector<int> &a, int size, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && a[left] < a[min])
    {
        min = left;
    }
    if (right < size && a[right] < a[min])
    {
        min = right;
    }
    if (min != i)
    {
        swap(a[min], a[i]);
        heapify(a, size, min);
    }
}
void buildMinHeap(vector<int> &a, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }
}
void HeapSort(vector<int> &a, int size)
{
    buildMinHeap(a, size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void Sort(vector<int> &A)
{
    HeapSort(A, A.size());
    if (A.size() == 0)
        cout << 0;
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
}
int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
