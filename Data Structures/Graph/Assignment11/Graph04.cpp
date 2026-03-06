#include <iostream>
#include <set>
#include <map>
using namespace std;
void Input(map<int, set<int>> &number_list, int &e)
{
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        number_list[x].insert(y);
        number_list[y].insert(x);
    }
    int k;
    cin >> k;
    for (const auto &tapDinh : number_list[k])
    {
        cout << tapDinh << " ";
    }
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}