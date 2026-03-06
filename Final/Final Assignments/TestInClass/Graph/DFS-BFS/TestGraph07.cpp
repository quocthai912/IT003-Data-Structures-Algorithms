// Tìm chu trình trong 1 đồ thị vô hướng
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
// Lưu vết cha
vector<int> Parent(200001, -1);
// Lưu đỉnh đã thăm
vector<bool> Visited(200001, 0);
// Đỉnh bắt đầu chu trình
int cycle_u = -1;
// Đỉnh kế đỉnh kết thúc chu trình
int cycle_v = -1;
// Biến phát hiện có chu trình
bool found = false;
void InputGraph(map<int, set<int>> &Graph, int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // Đồ thị vô hướng
        Graph[x].insert(y);
        Graph[y].insert(x);
    }
}

void DFS(map<int, set<int>> &Graph, int u, int parent)
{
    // Nếu đã gán chu trình trước đó => Thoát
    if (found)
        return;
    Visited[u] = true;
    Parent[u] = parent;
    for (const auto &v : Graph[u])
    {
        // Nếu đỉnh chưa thăm, đánh dấu là đã thăm
        if (!Visited[v])
        {
            DFS(Graph, v, u);
        }
        // Đỉnh đã thăm rồi => Có thể là Chu trình
        else
        {
            // Kiểm tra chu trình
            if (!found && v != Parent[u])
            {
                cycle_u = v;
                cycle_v = u;
                found = true;
                return;
            }
        }
    }
}

int main()
{
    int n, m;
    map<int, set<int>> Graph;
    InputGraph(Graph, n, m);
    for (int i = 1; i <= n; i++)
    {
        // Kiểm tra hết tất cả thành phần liên thông
        // Có thể trả về bất kì chu trình nào trong Đồ thị
        // Nên u và v có khả năng bị ghi đè, việc đó cũng không ảnh hưởng đến kết quả
        if (!Visited[i])
        {
            DFS(Graph, i, -1);
        }
    }
    if (found)
    {
        vector<int> cycle;
        cycle.push_back(cycle_u);
        for (int i = cycle_v; i != cycle_u; i = Parent[i])
        {
            cycle.push_back(i);
        }
        cycle.push_back(cycle_u);
        cout << cycle.size() << endl;
        // Xuất chu trình từ u -> v -> u
        for (int i = cycle.size() - 1; i >= 0; i--)
        {
            cout << cycle[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}