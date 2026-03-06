#include <iostream>
#include <set>
#include <map>
using namespace std;
void Input(map<int, set<int>> &number_list, int &e)
{
    cin >> e;
    set<int> tapDinh;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        number_list[x].insert(y);
        number_list[y].insert(x);
        tapDinh.insert(x);
        tapDinh.insert(y);
    }
    for (const auto &Dinh : tapDinh)
    {
        cout << Dinh << " ";
    }
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}