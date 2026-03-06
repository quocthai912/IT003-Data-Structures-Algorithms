// Nối các thành phần liên thông
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
vector<bool> Visited(100001, 0);

void InputGraph(map<int, set<int>> &Graph, int &n, int &m)
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

void DFS(map<int, set<int>> &Graph, int u)
{
    Visited[u] = true;
    for (const auto &v : Graph[u])
    {
        if (!Visited[v])
            DFS(Graph, v);
    }
}

int main()
{
    int n, m;
    map<int, set<int>> Graph;
    InputGraph(Graph, n, m);
    int soLuongThanhPhanLienThong = 0;
    vector<pair<int, int>> cacCapCanh;
    for (int i = 1; i <= n; i++)
    {
        if (!Visited[i])
        {
            // Thành phần liên thông mới
            soLuongThanhPhanLienThong++;
            DFS(Graph, i);
            if (i != 1)
            {
                // Lưu các cặp cạnh dùng để nối các thành phần liên thông
                cacCapCanh.push_back({i - 1, i});
            }
        }
    }
    cout << soLuongThanhPhanLienThong - 1 << endl;
    for (int i = 0; i < cacCapCanh.size(); i++)
    {
        cout << cacCapCanh[i].first << " " << cacCapCanh[i].second << endl;
    }
    return 0;
}