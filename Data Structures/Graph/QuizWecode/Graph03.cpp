/*Yêu Cầu:
+ Biểu Diễn Đồ Thị Bằng Danh Sách Kề (Set, Map)
+ Xuất Ra Số Lượng Đỉnh Và Tất Cả Các Đỉnh Của Đồ Thị */

#include <bits/stdc++.h>
using namespace std;
void Input(map<int, set<int>> &number_list, int &n)
{
    cin >> n;
    int x, y;
    set<int> danhSachDinh;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        number_list[x].insert(y);
        danhSachDinh.insert(x);
        danhSachDinh.insert(y);
    }
    cout << danhSachDinh.size() << endl;
    for (int ds : danhSachDinh)
    {
        cout << ds << " ";
    }
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}
