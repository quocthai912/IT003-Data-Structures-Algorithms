// In ra đường đi từ đỉnh 1 đến đỉnh n
#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;
vector<bool> visited(100001, 0);
vector<int> parent(100001, -1);
void Input(map<int, set<int>> &Graph, int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].insert(v);
        Graph[v].insert(u);
    }
}

void BFS(map<int, set<int>> &Graph, int u, int n)
{
    // u, đỉnh xuất phát, chính là 1
    // n, đỉnh kết thúc, chính là n
    // Nếu tìm được đường đi tới đỉnh n, kết thúc hàng đợi
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int dinhDangDuyet = q.front();
        q.pop();
        for (const auto &v : Graph[dinhDangDuyet])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = dinhDangDuyet;
                if (v == n)
                {
                    // Đã đến đích, không cần duyệt tiếp
                    return;
                }
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    map<int, set<int>> Graph;
    Input(Graph, n, m);
    BFS(Graph, 1, n);
    // Truy xuất ngược đường đi
    vector<int> path;
    for (int i = n; i != -1; i = parent[i])
    {
        path.push_back(i);
    }
    // Kích thước đường đi, không tính đỉnh xuất phát
    cout << path.size() - 1 << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    return 0;
}