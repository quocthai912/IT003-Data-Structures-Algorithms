#include <bits/stdc++.h>
using namespace std;
void Input(queue<int> &q)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        q.push(temp);
        cin >> temp;
    }
}
void Output(queue<int> q)
{
    int X;
    cin >> X;
    bool find = false;
    queue<int> temp;
    while (!q.empty())
    {
        int so = q.front();
        q.pop();
        if (so != X)
        {
            temp.push(so);
        }
        else
        {
            find = true;
            break;
        }
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    if (find)
    {
        cout << "Yes" << endl;
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    else
    {
        cout << "No" << endl;
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
}
int main()
{
    queue<int> q;
    Input(q);
    Output(q);
    return 0;
}
