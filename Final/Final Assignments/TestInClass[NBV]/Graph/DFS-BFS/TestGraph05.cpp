#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
// Tối đa 100000 đỉnh
bool Visited[100001];
// Đếm số lượng thành phần liên thông dùng BFS
void Input(map<int, set<int>> &Graph, int &m, int &n)
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void BFS(map<int, set<int>> &Graph, int dinhDuyet)
{
    // Đánh dấu đỉnh xuất phát
    Visited[dinhDuyet] = true;
    queue<int> q;
    q.push(dinhDuyet);
    while (!q.empty())
    {
        int dinhDangDuyet = q.front();
        q.pop();
        for (const auto &dinhKe : Graph[dinhDangDuyet])
        {
            if (!Visited[dinhKe])
            {
                // Đánh dấu là đã thăm
                Visited[dinhKe] = true;
                // Thêm đỉnh này vào để tiếp tục đánh dấu tiếp các đỉnh kề của nó
                q.push(dinhKe);
            }
        }
    }
}

int soLuongThanhPhanLienThong(map<int, set<int>> &Graph, int m)
{
    int soLuong = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!Visited[i])
        {
            // Đỉnh chưa thăm bao giờ, tức là một thành phần liên thông mới
            // Vì nếu thuộc một thành phần liên thông cũ thì nó đã được thăm (đánh dấu) trong lúc duyệt đồ thị
            soLuong++;
            // Ta sử dụng BFS để đánh dấu toàn bộ các đỉnh tạo thành thành phần liên thông mới này
            BFS(Graph, i);
        }
    }
    return soLuong;
}

int main()
{
    int m, n;
    map<int, set<int>> Graph;
    Input(Graph, m, n);
    cout << soLuongThanhPhanLienThong(Graph, m);
    return 0;
}
