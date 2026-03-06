#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    int pivot = v[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    QuickSort(v, left, j);
    QuickSort(v, i, right);
}

int FindMex(vector<int> v)
{
    QuickSort(v, 0, v.size() - 1);
    if (v[0] != 0)
        return 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
            continue;
        if (v[i + 1] != v[i] + 1)
            return v[i] + 1;
    }
    return v[v.size() - 1] + 1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cout << FindMex(v);
    return 0;
}