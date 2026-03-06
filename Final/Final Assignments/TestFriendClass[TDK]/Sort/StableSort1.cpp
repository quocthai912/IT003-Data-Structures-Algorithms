// Tìm số loại hàng khác nhau
#include <iostream>
#include <vector>
using namespace std;

bool SoSanh(string &s, string &t)
{
    if (s.length() == t.length())
        return s < t;
    return s.length() < t.length();
}

void QuickSort(vector<string> &v, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    string pivot = v[left + (right - left) / 2];
    while (i <= j)
    {
        while (SoSanh(v[i], pivot))
            i++;
        while (SoSanh(pivot, v[j]))
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
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    QuickSort(v, 0, v.size() - 1);
    vector<pair<string, int>> kiemKe;
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (v[i] == v[i - 1])
        {
            count++;
        }
        else
        {
            kiemKe.push_back({v[i - 1], count});
            count = 1;
        }
    }
    kiemKe.push_back({v[N - 1], count});
    cout << kiemKe.size();
    return 0;
}
