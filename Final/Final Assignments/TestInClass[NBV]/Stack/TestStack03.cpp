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
###End banned keyword*/
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

void Input(stack<int> &s)
{
    string st;
    cin >> st;
    int count = 1;
    for (int i = 0; i < st.length(); i++)
    {
        s.push(int(st[i]));
        while (i + 1 < st.length() && st[i] == st[i + 1])
        {
            count++;
            i++;
        }
        s.push(count);
        count = 1;
    }
}

void Output(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

int main()
{
    stack<int> s;
    Input(s);
    Output(s);
    return 0;
}
