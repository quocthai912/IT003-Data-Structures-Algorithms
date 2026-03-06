#include <iostream>
#include <vector>
using namespace std;
// Stable Sort
void InsertionSortKiemKe(vector<pair<string, int>> &kiemKe)
{
    for (int i = 1; i < kiemKe.size(); i++)
    {
        int j = i - 1;
        pair<string, int> temp = kiemKe[i];
        while (j >= 0 && kiemKe[j].second < temp.second)
        {
            kiemKe[j + 1] = kiemKe[j];
            j--;
        }
        kiemKe[j + 1] = temp;
    }
}

bool soSanhString(string &s, string &t)
{
    if (s.length() == t.length())
        return s < t;
    return s.length() < t.length();
}

void QuickSortString(vector<string> &v, int left, int right)
{
    if (left >= right)
        return;
    string pivot = v[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (soSanhString(v[i], pivot))
            i++;
        while (soSanhString(pivot, v[j]))
            j--;
        if (i <= j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    QuickSortString(v, left, j);
    QuickSortString(v, i, right);
}

int main()
{
    int N;
    cin >> N;
    if (N == 0)
        return 0;
    vector<string> v;
    for (int i = 0; i < N; i++)
    {
        string masp;
        cin >> masp;
        v.push_back(masp);
    }
    QuickSortString(v, 0, v.size() - 1);
    int count = 1;
    vector<pair<string, int>> kiemKe;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
            count++;
        else
        {
            kiemKe.push_back({v[i - 1], count});
            count = 1;
        }
    }
    kiemKe.push_back({v[v.size() - 1], count});
    InsertionSortKiemKe(kiemKe);
    for (int i = 0; i < kiemKe.size(); i++)
    {
        cout << kiemKe[i].first << " " << kiemKe[i].second << endl;
    }
    return 0;
}
