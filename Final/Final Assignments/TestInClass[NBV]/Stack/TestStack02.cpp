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

void toBinary(stack<int> &s, int X)
{
    while (X / 2 > 0)
    {
        s.push(X % 2);
        X /= 2;
    }
    s.push(X % 2);
}

void Input(stack<int> &s)
{
    int X, Y;
    cin >> X >> Y;
    for (int i = 0; i < Y; i++)
        X *= 2;
    toBinary(s, X);
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
