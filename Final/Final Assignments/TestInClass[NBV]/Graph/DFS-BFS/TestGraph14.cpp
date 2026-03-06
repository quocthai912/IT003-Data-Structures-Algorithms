#include <bits/stdc++.h>
using namespace std;
// Tìm Độ Sâu Của Các Node
// Bài Toán Quy Về Bài Toán Tính Trọng Số Đường Đi Từ Đỉnh 1 -> Tới Các Đỉnh Còn Lại Trong Đồ Thị
vector<int> level;
vector<bool> visited;
void InputGraph(map<int, set<int>> &Graph, int &n)
{
    cin >> n;
    level.resize(n + 1, 0);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void BFS(map<int, set<int>> &Graph, int source)
{
    visited[source] = true;
    level[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (const auto &v : Graph[u])
        {
            if (!visited[v])
            {
                level[v] = level[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    map<int, set<int>> Graph;
    int n;
    InputGraph(Graph, n);
    BFS(Graph, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << level[i] << " ";
    }
    return 0;
}