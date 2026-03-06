/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
[
]
###End banned keyword*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
void Input(queue<int> &q)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        q.push(x);
        cin >> x;
    }
}

bool Increase(queue<int> q)
{
    while (q.size() > 1)
    {
        int temp = q.front();
        q.pop();
        if (temp >= q.front())
            return false;
    }
    return true;
}

bool Decrease(queue<int> q)
{
    while (q.size() > 1)
    {
        int temp = q.front();
        q.pop();
        if (temp <= q.front())
            return false;
    }
    return true;
}

void Fun(queue<int> q)
{
    if (q.empty())
        return;
    if (Increase(q))
    {
        cout << "Increase" << endl;
        return;
    }
    if (Decrease(q))
    {
        cout << "Decrease" << endl;
        return;
    }
    cout << "None" << endl;
}

void Output(queue<int> q)
{
    if (q.empty())
    {
        cout << "Empty";
        return;
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    Input(q);
    Fun(q);
    Output(q);
    return 0;
}
