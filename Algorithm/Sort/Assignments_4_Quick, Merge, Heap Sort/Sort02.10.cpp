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

void Heapify(vector<int> &a, int n, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] < a[min])
    {
        min = left;
    }
    if (right < n && a[right] < a[min])
    {
        min = right;
    }
    if (min != i)
    {
        swap(a[min], a[i]);
        Heapify(a, n, min);
    }
}
void buildHeap(vector<int> &a, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }
}
void HeapSort(vector<int> &a, int n)
{
    int heapSize;
    heapSize = n;
    buildHeap(a, heapSize);
    for (int i = n - 1; i > 0; i--)
    {
        cout << "N=" << i + 1 << endl;
        swap(a[0], a[i]);
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << endl;
        heapSize -= 1;
        Heapify(a, heapSize, 0);
    }
}
void Sort(vector<int> &A)
{
    HeapSort(A, A.size());
}

int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
