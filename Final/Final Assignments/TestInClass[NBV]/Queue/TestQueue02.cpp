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
#include <string.h>
#include <queue>
#include <stack>
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

void Fun(queue<int> &q)
{

    int X;
    cin >> X;
    queue<int> result;
    while (!q.empty())
    {
        if (q.front() != X)
            result.push(q.front());
        q.pop();
    }
    while (!result.empty())
    {
        q.push(result.front());
        result.pop();
    }
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
