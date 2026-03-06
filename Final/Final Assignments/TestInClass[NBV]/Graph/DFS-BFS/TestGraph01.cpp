#include <iostream>
#include <set>
#include <map>
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

void DFS(map<int, set<int>> &Graph, int Dinh)
{
    // Đánh dấu đỉnh đã thăm
    Visited[Dinh] = true;
    for (const auto TapDinhKe : Graph[Dinh])
    {
        // Nếu đỉnh chưa thăm, thực hiện đệ quy DFS để đánh dấu và duyệt tiếp các đỉnh kề
        if (!Visited[TapDinhKe])
            DFS(Graph, TapDinhKe);
    }
}

void Output(map<int, set<int>> &Graph, int m)
{
    DFS(Graph, 0);
    for (int i = 1; i < m; i++)
    {
        // Nếu đỉnh đã được thăm, tức có đường đi từ đỉnh xuất phát
        if (Visited[i] == 1)
            cout << "CO";
        else
            cout << "KHONG";
        cout << endl;
    }
}

int main()
{
    map<int, set<int>> Graph;
    int m, n;
    InputGraph(Graph, m, n);
    Output(Graph, m);
    return 0;
}
