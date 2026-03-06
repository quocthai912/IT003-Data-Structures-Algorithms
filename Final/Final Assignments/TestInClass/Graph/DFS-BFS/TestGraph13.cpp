// Cây cũng là một đồ thị
// Bài toán yêu cầu đếm số lượng Node tại cây con thứ i (bao gồm cả Node i)
#include <bits/stdc++.h>
using namespace std;

vector<int> subTree;
vector<bool> visited;
void InputGraph(map<int, set<int>> &Graph, int &n)
{
    cin >> n;
    subTree.resize(n + 1, 0);
    visited.resize(n + 1, false);
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
    subTree[source] = 1;
    for (const auto &v : Graph[source])
    {
        if (!visited[v])
        {
            DFS(Graph, v);
            subTree[source] += subTree[v];
        }
    }
}

int main()
{
    map<int, set<int>> Graph;
    int n;
    InputGraph(Graph, n);
    DFS(Graph, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << subTree[i] << " ";
    }
    return 0;
}