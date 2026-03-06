// Best case = O(N), Avr case and Worst Case = O(N^2)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[201];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
            for (int k = 0; k < n; k++)
                cout << a[k] << " ";
            cout << endl;
        }
        a[j + 1] = key;
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << endl;
    }
    return 0;
}
