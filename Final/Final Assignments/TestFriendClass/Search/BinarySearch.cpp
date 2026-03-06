/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
// Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x;
    while (q--)
    {
        cin >> x;
        if (myBinarySearch(arr, n, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

bool myBinarySearch(int a[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return true;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
