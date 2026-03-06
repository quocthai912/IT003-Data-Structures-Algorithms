#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right)
{
    int sizeLeft = (mid - left) + 1;
    int sizeRight = right - mid;
    vector<int> arrLeft(sizeLeft);
    vector<int> arrRight(sizeRight);
    for (int i = 0; i < sizeLeft; i++)
    {
        arrLeft[i] = arr[left + i];
    }
    for (int j = 0; j < sizeRight; j++)
    {
        arrRight[j] = arr[mid + 1 + j];
    }
    // Tiến hành trộn
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight)
    {
        if (arrLeft[i] > arrRight[j])
        {
            arr[k++] = arrRight[j];
            j++;
        }
        else
        {
            arr[k++] = arrLeft[i];
            i++;
        }
    }
    while (i < sizeLeft)
    {
        arr[k++] = arrLeft[i];
        i++;
    }
    while (j < sizeRight)
    {
        arr[k++] = arrRight[j];
        j++;
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}