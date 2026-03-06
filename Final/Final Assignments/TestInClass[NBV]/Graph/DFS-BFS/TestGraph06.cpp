// Xác định đường đi từ đỉnh 1 -> đỉnh n
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
vector<int> Parent(100001, -1);
vector<bool> Visited(100001, 0);
void InputGraph(map<int, set<int>> &Graph, int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void BFS(map<int, set<int>> &Graph, int x, int y)
{
    // Đỉnh xuất phát
    Visited[x] = true;
    queue<int> q;
    bool found = false;
    q.push(x);
    while (!q.empty())
    {
        int dinhDuyet = q.front();
        q.pop();
        for (const auto &dinhKe : Graph[dinhDuyet])
        {
            if (!Visited[dinhKe])
            {
                // Lưu vết cha
                Parent[dinhKe] = dinhDuyet;
                Visited[dinhKe] = true;
                if (dinhKe == y)
                {
                    found = true;
                    break;
                }
                q.push(dinhKe);
            }
        }
    }
    if (found)
    {
        // Số lượng đỉnh phải đi qua
        vector<int> duongDi;
        for (int i = y; i != -1; i = Parent[i])
        {
            duongDi.push_back(i);
        }
        cout << duongDi.size() << endl;
        for (int i = duongDi.size() - 1; i >= 0; i--)
        {
            cout << duongDi[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}

int main()
{
    int n, m;
    map<int, set<int>> Graph;
    InputGraph(Graph, n, m);
    BFS(Graph, 1, n);
    return 0;
}
