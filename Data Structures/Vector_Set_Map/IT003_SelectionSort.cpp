#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[201];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        // Gáng điều kiện tránh swap dư thừa
        if (a[i] > a[minIndex])
        {
            swap(a[i], a[minIndex]);
            for (int k = 0; k < n; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}