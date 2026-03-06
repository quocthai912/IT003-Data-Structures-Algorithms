#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

void Input(queue<int> &q)
{
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        q.push(int(s[i]));
        while (i + 1 < s.length() && s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        q.push(count + 1);
        count = 0;
    }
}

void Output(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
}

int main()
{
    queue<int> q;
    Input(q);
    Output(q);
    return 0;
}
