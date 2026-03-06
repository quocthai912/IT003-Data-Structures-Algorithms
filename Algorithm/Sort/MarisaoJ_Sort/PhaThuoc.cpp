#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nam(n);
    for (int i = 0; i < nam.size(); i++)
    {
        cin >> nam[i];
    }
    sort(nam.begin(), nam.end());
    int count = 0;
    int left = 0;
    int right = nam.size() - 1;
    while (left <= right)
    {
        if (nam[left] + nam[right] > k)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
        count++;
    }
    cout << count;
    return 0;
}