// Sử Dụng Thuật Toán Dijkstra Để In Ra Trọng Số Đường Đi Ngắn Nhất Từ Đỉnh 1 -> 2,3,4,...n
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;
vector<ii> adj[100001];
int n, m;
void InputGraph()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

void ShortestRoutes()
{
    int s = 1;
    vector<long long> distance(n + 1, 1e18);
    distance[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({distance[s], s});
    while (!q.empty())
    {
        ii t = q.top();
        q.pop();
        int u = t.second;
        long long dis = t.first;
        if (dis > distance[u])
            continue;
        for (ii e : adj[u])
        {
            int v = e.first;
            long long w = e.second;
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                q.push({distance[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << distance[i] << " ";
    }
}

int main()
{
    InputGraph();
    ShortestRoutes();
    return 0;
}
