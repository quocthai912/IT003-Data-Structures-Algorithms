/*Yêu Cầu:
+ Biểu Diễn Đồ Thị Bằng Danh Sách Kề (Set, Map)
+ Xuất Các Đỉnh Có Bậc Bằng k
+ Đồ Thị Có Hướng */
#include <bits/stdc++.h>
using namespace std;

int BacCuaDinh(map<int, set<int>> number_list, int dinh)
{
    // Các đỉnh mà nối tới nó
    int dinhVao = 0;
    for (const auto h : number_list)
    {
        if (h.second.count(dinh))
            dinhVao++;
    }
    // Các đỉnh mà nó nối tới
    int dinhRa = 0;
    if (number_list.count(dinh))
    {
        dinhRa = number_list[dinh].size();
    }
    return dinhRa + dinhVao;
}
void Input(map<int, set<int>> &number_list, int &n)
{
    cin >> n;
    set<int> dsDinh;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        // x -> y
        number_list[x].insert(y);
        dsDinh.insert(x);
        dsDinh.insert(y);
    }
    int k;
    cin >> k;
    vector<int> result;
    for (int Dinh : dsDinh)
    {
        if (BacCuaDinh(number_list, Dinh) == k)
            result.push_back(Dinh);
    }
    if (result.size() == 0)
    {
        cout << "No find";
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}
