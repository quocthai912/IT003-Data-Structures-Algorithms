#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[1001] = {false};
struct Bando
{
    int N;
    bool Duong[3001][3001];
};
Bando banDo;
void NhapBanDo(Bando &banDo)
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < 3001; i++)
    {
        for (int j = 0; j < 3001; j++)
        {
            banDo.Duong[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        banDo.Duong[x][y] = true;
        banDo.Duong[y][x] = true;
    }
    banDo.N = m;
}

void duyetDoThi(const Bando &m, int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < m.N; v++)
        {
            if (!visited[v] && m.Duong[u][v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int coDuongDi(const Bando &m, int s, int e)
{
    if (s == e)
        return 1;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < m.N; v++)
        {
            if (m.Duong[u][v] && !visited[v])
            {
                if (v == e)
                    return 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    NhapBanDo(banDo);
    duyetDoThi(banDo, 0);
    for (int i = 1; i < banDo.N; i++)
    {
        if (visited[i])
        {
            cout << "CO" << endl;
        }
        else
        {
            cout << "KHONG" << endl;
        }
    }
    return 0;
}
