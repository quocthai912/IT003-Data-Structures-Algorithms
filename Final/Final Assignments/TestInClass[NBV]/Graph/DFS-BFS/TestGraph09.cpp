// Kiểm tra một đồ thị đã cho có phải là cây hay không?
// Một đồ thị là 1 cây khi không có chu trình và tất cả các đỉnh đều liên thông
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
vector<bool> visited(100001, 0);
vector<int> parent(100001, -1);
bool cycle = false;

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

void DFS(map<int, set<int>> &Graph, int u, int father)
{
    // Phát hiện có chu trình nhưng vẫn duyệt tiếp, xem đồ thị có liên thông hay không
    visited[u] = true;
    parent[u] = father;
    for (const auto &v : Graph[u])
    {
        if (!visited[v])
            DFS(Graph, v, u);
        else
        {
            if (v != parent[u])
                cycle = true;
        }
    }
}

int main()
{
    int n, m;
    map<int, set<int>> Graph;
    Input(Graph, n, m);
    bool isTree = true;
    DFS(Graph, 1, -1);
    if (cycle)
    {
        isTree = false;
    }
    else
    {
        // Không có chu trình, giờ ta sẽ kiểm tra tính liên thông
        for (int i = 1; i <= n; i++)
        {
            // Nếu đồ thị không liên thông, không phải cây
            if (!visited[i])
                isTree = false;
        }
    }
    if (isTree)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}