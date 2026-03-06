#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &v, int x)
{
    int left = 0;
    int right = v.size() - 1;
    int found = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] >= x)
        {
            found = v[mid];
            right = mid - 1;
        }
        else
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
    vector<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < Q; i++)
    {
        int truyVan;
        cin >> truyVan;
        q.push_back(binarySearch(v, truyVan));
    }
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << endl;
    }
    return 0;
}