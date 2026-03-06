// Tính Trọng Số Đường Đi Ngắn Nhất Từ 1 -> N và In Ra Bất Kì Đường Đi Nào Thỏa Mãn.
// Cài Đặt Thuật Toán Dijkstra (Được Học Trong IT003).
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;
vector<ii> adj[200001];
vector<long long> parent;
long long n, m;
void InputGraph()
{
    cin >> n >> m;
    parent.resize(n + 1, -1);
    for (long long i = 0; i < m; i++)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Dijkstra()
{
    int s = 1;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<long long> distance(n + 1, 1e18);
    distance[s] = 0;
    q.push({distance[s], s});
    while (!q.empty())
    {
        ii t = q.top();
        q.pop();
        long long dis = t.first;
        int u = t.second;
        if (dis > distance[u])
            continue;
        for (ii e : adj[u])
        {
            int v = e.first;
            long long w = e.second;
            if (distance[v] > distance[u] + w)
            {
                parent[v] = u;
                distance[v] = distance[u] + w;
                q.push({distance[v], v});
            }
        }
    }
    if (distance[n] == 1e18)
    {
        cout << -1 << endl
             << 1;
        return;
    }
    cout << distance[n] << endl;
    vector<int> path;
    for (int i = n; parent[i] != -1; i = parent[i])
    {
        path.push_back(i);
    }
    path.push_back(1);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}

int main()
{
    InputGraph();
    Dijkstra();
    return 0;
}
