#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<long long> &v, int left, int right)
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

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> gift(n);
    for (int i = 0; i < n; i++)
        cin >> gift[i];
    QuickSort(gift, 0, gift.size() - 1);
    int left = 0;
    int right = gift.size() - 1;
    long long sum;
    long long result = -1;
    while (left < right)
    {
        sum = gift[left] + gift[right];
        if (sum > x)
            right--;
        else
        {
            result = max(result, sum);
            left++;
        }
    }
    cout << result;
    return 0;
}
