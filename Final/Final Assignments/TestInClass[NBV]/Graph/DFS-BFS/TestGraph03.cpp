// Dem so luong dinh co lap
#include <iostream>
#include <set>
#include <map>
using namespace std;
int main()
{
    map<int, set<int>> Graph;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        // Đồ thị vô hướng
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
    // Đỉnh cô lập là đỉnh không có bất kì tập đỉnh kề nào
    // Hay nói cách khác đỉnh này không nằm trong Graph ở phần nhập Input
    int soLuongDinhCoLap = m - Graph.size();
    cout << soLuongDinhCoLap;
    return 0;
}