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

void Fun(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
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
