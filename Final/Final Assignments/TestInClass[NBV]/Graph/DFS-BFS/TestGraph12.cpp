#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> path;

void InputGraph(map<int, set<int>> &Graph, int &n, int &m)
{
    cin >> n >> m;
    visited.resize(n + 1, false);
    path.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
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
    int countPath = 0;
    path[source] = countPath;
    // source -> source = 0
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
                // Đường đi của Node con = Đường đi của Node cha + 1
                // u -> v = (u -> u + 1)
                path[v] = path[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    map<int, set<int>> Graph;
    int n, m;
    InputGraph(Graph, n, m);
    BFS(Graph, 1);
    for (int i = 2; i <= n; i++)
        cout << path[i] << " ";
    return 0;
}
