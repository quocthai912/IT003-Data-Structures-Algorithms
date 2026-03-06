/*Yêu Cầu:
+ Biểu Diễn Đồ Thị Bằng Ma Trận Kề
+ Xuất Ra Ma Trận Kề Của Đồ Thị */
#include <iostream>
#include <vector>
using namespace std;

void Input(vector<vector<int>> &G, int v, int e)
{
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        G[a][b] = 1;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v, e; // v là số đỉnh, e là số cạnh
    cin >> e >> v;
    vector<vector<int>> G(v, vector<int>(v, 0));
    Input(G, v, e);
    return 0;
}
