#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;
bool Visited[1001];

void InputGraph(map<int, set<int>> &Graph, int &m, int &n)
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void BFS(map<int, set<int>> &Graph, int DinhDuyet)
{
    queue<int> q;
    Visited[DinhDuyet] = true;
    q.push(DinhDuyet);
    while (!q.empty())
    {
        int dinhDangDuyet = q.front();
        q.pop();
        for (const auto &TapDinhKe : Graph[dinhDangDuyet])
        {
            if (!Visited[TapDinhKe])
            {
                Visited[TapDinhKe] = true;
                q.push(TapDinhKe);
            }
        }
    }
}

void OutputGraph(map<int, set<int>> Graph, int m)
{
    BFS(Graph, 0);
    bool dinhKhongCoLap = false;
    for (int i = 1; i < m; i++)
    {
        if (Visited[i] == true)
        {
            cout << i << " ";
            dinhKhongCoLap = true;
        }
    }
    if (!dinhKhongCoLap)
        cout << "KHONG";
}

int main()
{
    int m, n;
    map<int, set<int>> Graph;
    InputGraph(Graph, m, n);
    OutputGraph(Graph, m);
    return 0;
}