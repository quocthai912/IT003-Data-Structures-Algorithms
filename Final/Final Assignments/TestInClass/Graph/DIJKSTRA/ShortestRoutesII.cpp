// Cài Đặt Thuật Toán Dijkstra Để Xử Lí Các Truy Vấn
// Các Truy Vấn Yêu Cầu: In Ra Trọng Số Đường Đi Ngắn Nhất Giữa 2 Đỉnh Trong Truy Vấn q[i]
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;
vector<ii> adj[501];
long long dist_matrix[501][501];
int n, m, q;
vector<ii> queries;
void InputGraph()
{
    cin >> n >> m >> q;
    queries.resize(q);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }
}

void ShortestRoutes(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dist_matrix[s][i] = 1e18;
    }
    dist_matrix[s][s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        ii t = pq.top();
        pq.pop();
        int u = t.second;
        long long dis = t.first;
        if (dis > dist_matrix[s][u])
        {
            continue;
        }
        for (ii e : adj[u])
        {
            int v = e.first;
            long long w = e.second;
            if (dist_matrix[s][v] > dist_matrix[s][u] + w)
            {
                dist_matrix[s][v] = dist_matrix[s][u] + w;
                pq.push({dist_matrix[s][v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    InputGraph();
    for (int i = 1; i <= n; i++)
    {
        ShortestRoutes(i);
    }
    for (int i = 0; i < q; i++)
    {
        if (dist_matrix[queries[i].first][queries[i].second] == 1e18)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist_matrix[queries[i].first][queries[i].second] << "\n";
        }
    }
    return 0;
}