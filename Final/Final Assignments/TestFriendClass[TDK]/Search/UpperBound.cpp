#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void QuickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int pivot = v[left + (right - left) / 2];
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

int binarySearch(vector<int> &v, int x)
{
    int found = -1;
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] > x)
        {
            found = v[mid];
            right = mid - 1;
        }
        else if (v[mid] <= x)
        {
            left = mid + 1;
        }
    }
    return found;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    QuickSort(v, 0, v.size() - 1);
    vector<int> q;
    for (int i = 0; i < Q; i++)
    {
        int truyVan;
        cin >> truyVan;
        q.push_back(binarySearch(v, truyVan));
    }
    for (int i = 0; i < Q; i++)
    {
        cout << q[i] << endl;
    }
    return 0;
}
