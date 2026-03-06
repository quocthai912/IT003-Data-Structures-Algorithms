#include <bits/stdc++.h>
using namespace std;
void QuickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}
int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    QuickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
