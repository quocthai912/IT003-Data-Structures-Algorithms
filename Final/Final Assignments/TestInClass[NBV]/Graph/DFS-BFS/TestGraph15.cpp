#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> nodeLeaf;
void InputGraph(map<int, set<int>> &Graph, int &n)
{
    cin >> n;
    visited.resize(n + 1, false);
    nodeLeaf.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void DFS(map<int, set<int>> &Graph, int source)
{
    visited[source] = true;
    int countNodeLeaf = 0;
    if (Graph[source].size() == 1)
        countNodeLeaf = 1;
    nodeLeaf[source] = countNodeLeaf;
    for (const auto &v : Graph[source])
    {
        if (!visited[v])
        {
            DFS(Graph, v);
            nodeLeaf[source] += nodeLeaf[v];
        }
    }
}

int main()
{
    map<int, set<int>> Graph;
    int n;
    InputGraph(Graph, n);
    if (n == 1 || n == 2)
    {
        cout << 1;
        return 0;
    }
    DFS(Graph, 1);
    int maxLeaf = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nodeLeaf[i] > maxLeaf)
            maxLeaf = nodeLeaf[i];
    }
    cout << maxLeaf << " ";
    return 0;
}