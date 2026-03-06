/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

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
    cout << number_list[k].size();
}

int main()
{
    map<int, set<int>> number_list;
    int n;
    Input(number_list, n);
    return 0;
}
