#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, pair<int, int>> hashTable;
void linearSearch(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (hashTable.count(v[i]) == 0)
        {
            hashTable[v[i]] = {i + 1, i + 1};
        }
        else
        {
            hashTable[v[i]].second = i + 1;
        }
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    vector<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    linearSearch(v);
    for (int i = 0; i < Q; i++)
    {
        cin.ignore();
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (hashTable.count(y) == 0)
            q.push_back(-1);
        else
        {
            if (x == 1)
                q.push_back(hashTable[y].first);
            else
                q.push_back(hashTable[y].second);
        }
    }
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << endl;
    }
    return 0;
}
