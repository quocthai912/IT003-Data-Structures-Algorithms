#include <iostream>
#include <set>
#include <map>
#include <stack>
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

void DFS(map<int, set<int>> &Graph, int DinhBatDau)
{
    Visited[DinhBatDau] = true;
    stack<int> st;
    st.push(DinhBatDau);
    while (!st.empty())
    {
        int dinhDangDuyet = st.top();
        st.pop();
        for (const auto &DinhKe : Graph[dinhDangDuyet])
        {
            if (!Visited[DinhKe])
            {
                // Đã thăm
                Visited[DinhKe] = true;
                st.push(DinhKe);
            }
        }
    }
}

int SoLuongThanhPhanLienThong(map<int, set<int>> &Graph, int m)
{
    int soLuong = 0;
    for (int i = 0; i < m; i++)
    {
        if (!Visited[i])
        {
            soLuong++;
            DFS(Graph, i);
        }
    }
    return soLuong;
}

int main()
{
    int m, n;
    map<int, set<int>> Graph;
    InputGraph(Graph, m, n);
    cout << SoLuongThanhPhanLienThong(Graph, m);
    return 0;
}
