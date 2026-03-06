/*Yêu Cầu:
+ Biểu Diễn Đồ Thị Bằng Danh Sách Kề (Set, Map)
+ Kiểm Tra Xem Hai Đỉnh Có Phải Là Đỉnh Kề Của Nhau Không
+ A Là Đỉnh Kề Của B Khi B -> A
+ B Là Đỉnh Kề Của A Khi A -> B */

#include <bits/stdc++.h>
using namespace std;

void Input(map<int, set<int>> &number_list, int &n)
{
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        number_list[x].insert(y);
    }
    int a, b;
    cin >> a >> b;
    // b -> a, vậy a là đỉnh kề của b
    if (number_list[b].count(a) == 1)
    {
        cout << a << " la dinh ke cua dinh " << b;
    }
    // a -> b, vậy b là đỉnh kề của a
    else if (number_list[a].count(b) == 1)
    {
        cout << b << " la dinh ke cua dinh " << a;
    }
    else
    {
        cout << "2 dinh khong ke nhau";
    }
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}
